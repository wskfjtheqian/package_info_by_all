#ifndef FLUTTER_PLUGIN_PACKAGE_INFO_BY_ALL_PLUGIN_H_
#define FLUTTER_PLUGIN_PACKAGE_INFO_BY_ALL_PLUGIN_H_

#include <flutter_plugin_registrar.h>
#pragma comment(linker, "/defaultlib:version.lib")

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __declspec(dllexport)
#else
#define FLUTTER_PLUGIN_EXPORT __declspec(dllimport)
#endif

#if defined(__cplusplus)
extern "C" {
#endif

FLUTTER_PLUGIN_EXPORT void PackageInfoByAllPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar);

#if defined(__cplusplus)
}  // extern "C"
#endif

#endif  // FLUTTER_PLUGIN_PACKAGE_INFO_BY_ALL_PLUGIN_H_
