import 'dart:async';
import 'dart:html' as html;

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

    var completer = new Completer<PackageInfo>();
    var request = html.HttpRequest.request("manifest.json", responseType: "json").then((value) {
      try {
        var map = value.response as Map;
        _fromPlatform = PackageInfoByWeb(
          appName: map["short_name"],
          packageName: map["name"],
          version: map["version"],
          buildNumber: map["build_number"],
        );
        completer.complete(_fromPlatform);
      } catch (e) {
        completer.complete(null);
      }
    }, onError: () {
      completer.complete(null);
    });
    return completer.future;
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
}
