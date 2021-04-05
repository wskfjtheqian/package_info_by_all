import 'dart:async';
import 'dart:convert';
import 'dart:html' as html;

import 'package:flutter/services.dart';
import 'package:flutter_web_plugins/src/plugin_registry.dart';

import '../package_info_by_all.dart';
import 'package_info_platform.dart';

class PackageInfoByWebPlugin extends PackageInfoPlatform {
  PackageInfoByWeb _fromPlatform;

  static void registerWith(Registrar registrarFor) {
    PackageInfoPlatform.platform = PackageInfoByWebPlugin();
  }

  @override
  Future<PackageInfo> get() async {
    if (null != _fromPlatform) {
      return _fromPlatform;
    }

    var version = await rootBundle.loadString('../version.json');
    var map = json.decode(version);
    return PackageInfoByWeb(
      appName: map["app_name"],
      packageName: map["app_name"],
      version: map["version"],
      buildNumber: map["build_number"],
    );
  }
}

class PackageInfoByWeb extends PackageInfo {
  final String appName;

  final String packageName;

  final String version;

  final String buildNumber;

  PackageInfoByWeb({
    this.appName,
    this.packageName,
    this.version,
    this.buildNumber,
  });

  @override
  String toString() {
    return 'PackageInfoByWeb{appName: $appName, packageName: $packageName, version: $version, buildNumber: $buildNumber}';
  }
}
