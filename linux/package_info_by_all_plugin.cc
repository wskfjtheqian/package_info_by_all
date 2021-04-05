#include "include/package_info_by_all/package_info_by_all_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>
#include <sys/utsname.h>

#include <cstring>

#define PACKAGE_INFO_BY_ALL_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), package_info_by_all_plugin_get_type(), \
                              PackageInfoByAllPlugin))

struct _PackageInfoByAllPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(PackageInfoByAllPlugin, package_info_by_all_plugin, g_object_get_type())

// Called when a method call is received from Flutter.
static void package_info_by_all_plugin_handle_method_call(
    PackageInfoByAllPlugin* self,
    FlMethodCall* method_call) {
  g_autoptr(FlMethodResponse) response = nullptr;

  const gchar* method = fl_method_call_get_name(method_call);

  if (strcmp(method, "getAll") == 0) {
    g_autoptr(FlValue) result = fl_value_new_map();
    fl_value_set_string_take (result, "appName", fl_value_new_string (kAppName));
    fl_value_set_string_take (result, "packageName", fl_value_new_string (kPackageName));
    fl_value_set_string_take (result, "version", fl_value_new_string (kVersion));
    fl_value_set_string_take (result, "buildNumber", fl_value_new_string (kBuildNumber));
    response = FL_METHOD_RESPONSE(fl_method_success_response_new(result));
  } else {
    response = FL_METHOD_RESPONSE(fl_method_not_implemented_response_new());
  }

  fl_method_call_respond(method_call, response, nullptr);
}

static void package_info_by_all_plugin_dispose(GObject* object) {
  G_OBJECT_CLASS(package_info_by_all_plugin_parent_class)->dispose(object);
}

static void package_info_by_all_plugin_class_init(PackageInfoByAllPluginClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = package_info_by_all_plugin_dispose;
}

static void package_info_by_all_plugin_init(PackageInfoByAllPlugin* self) {}

static void method_call_cb(FlMethodChannel* channel, FlMethodCall* method_call,
                           gpointer user_data) {
  PackageInfoByAllPlugin* plugin = PACKAGE_INFO_BY_ALL_PLUGIN(user_data);
  package_info_by_all_plugin_handle_method_call(plugin, method_call);
}

void package_info_by_all_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  PackageInfoByAllPlugin* plugin = PACKAGE_INFO_BY_ALL_PLUGIN(
      g_object_new(package_info_by_all_plugin_get_type(), nullptr));

  g_autoptr(FlStandardMethodCodec) codec = fl_standard_method_codec_new();
  g_autoptr(FlMethodChannel) channel =
      fl_method_channel_new(fl_plugin_registrar_get_messenger(registrar),
                            "package_info_by_all",
                            FL_METHOD_CODEC(codec));
  fl_method_channel_set_method_call_handler(channel, method_call_cb,
                                            g_object_ref(plugin),
                                            g_object_unref);

  g_object_unref(plugin);
}
