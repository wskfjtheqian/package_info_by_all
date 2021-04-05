//
//  Generated file. Do not edit.
//

#include "generated_plugin_registrant.h"

#include <package_info_by_all/package_info_by_all_plugin.h>

void fl_register_plugins(FlPluginRegistry* registry) {
  g_autoptr(FlPluginRegistrar) package_info_by_all_registrar =
      fl_plugin_registry_get_registrar_for_plugin(registry, "PackageInfoByAllPlugin");
  package_info_by_all_plugin_register_with_registrar(package_info_by_all_registrar);
}
