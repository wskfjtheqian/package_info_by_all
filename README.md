# package_info_by_all

Get package info ,support(android,ios,web,mac,linux)

## Getting Started

This project is a starting point for a Flutter
[plug-in package](https://flutter.dev/developing-packages/),
a specialized package that includes platform-specific implementation code for
Android and/or iOS.


## WEB
 please add "short_name","name","version","build_number" by at  manifest.json file

Example

{
    "name": "package_info_by_all_example",
    "short_name": "package_info_by_all_example",
    "start_url": ".",
    "display": "minimal-ui",
    "background_color": "#0175C2",
}

## Linux
 please add "kAppName","kPackageName","kVersion","kBuildNumber" by at  window_configuration.cc file

Example

 const char *kAppName = "package_info_by_all_example";

 const char *kPackageName = "package_info_by_all_example";

 const char *kVersion = "1.0.0";

 const char *kBuildNumber = "1";

## Windows
 Will be supported in subsequent releases