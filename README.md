# package_info_by_all

Get package info ,support(android,ios,web,mac,linux,windows)

## Getting Started

This project is a starting point for a Flutter
[plug-in package](https://flutter.dev/developing-packages/),
a specialized package that includes platform-specific implementation code for
android,ios,web,mac,linux,windows.


## Linux
 please add "kAppName","kPackageName","kVersion","kBuildNumber" by at  window_configuration.cc file

Example

 const char *kAppName = "package_info_by_all_example";

 const char *kPackageName = "package_info_by_all_example";

 const char *kVersion = "1.0.0";

 const char *kBuildNumber = "1";

## Windows
 please add "BuildNumber" by at Runner.rc file

 appName  by ProductName get

 packageName by ProductName get

 version by ProductVersion get

 buildNumber by BuildNumber get
