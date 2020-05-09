import 'dart:async';

import 'package:flutter/services.dart';

import 'src/package_info_platform.dart';

abstract class PackageInfo {
  String get appName;

  String get packageName;

  String get version;

  String get buildNumber;

 static Future<PackageInfo> get() {
    return PackageInfoPlatform.platform.get();
  }
}
