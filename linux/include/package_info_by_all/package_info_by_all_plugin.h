#ifndef FLUTTER_PLUGIN_PACKAGE_INFO_BY_ALL_PLUGIN_H_
#define FLUTTER_PLUGIN_PACKAGE_INFO_BY_ALL_PLUGIN_H_

#include <flutter_linux/flutter_linux.h>

G_BEGIN_DECLS

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

extern const char *kAppName;
extern const char *kPackageName;
extern const char *kVersion;
extern const char *kBuildNumber;

typedef struct _PackageInfoByAllPlugin PackageInfoByAllPlugin;
typedef struct {
  GObjectClass parent_class;
} PackageInfoByAllPluginClass;

FLUTTER_PLUGIN_EXPORT GType package_info_by_all_plugin_get_type();

FLUTTER_PLUGIN_EXPORT void package_info_by_all_plugin_register_with_registrar(
    FlPluginRegistrar* registrar);

G_END_DECLS

#endif  // FLUTTER_PLUGIN_PACKAGE_INFO_BY_ALL_PLUGIN_H_
