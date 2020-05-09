import 'package:flutter/services.dart';

import '../package_info_by_all.dart';

class PackageInfoPlatform {
  static const MethodChannel _channel = const MethodChannel('package_info_by_all');
  static PackageInfoPlatform _platform;

  PackageInfo _fromPlatform;

  static PackageInfoPlatform get platform => _platform ??= PackageInfoPlatform();

  static set platform(PackageInfoPlatform value) {
    _platform = value;
  }

  Future<PackageInfo> get() async {
    if (null != _fromPlatform) {
      return _fromPlatform;
    }
    final Map<String, dynamic> map = await _channel.invokeMapMethod<String, dynamic>('getAll');
    return _fromPlatform = PackageInfoByPlatform(
      appName: map["appName"],
      packageName: map["packageName"],
      version: map["version"],
      buildNumber: map["buildNumber"],
    );
  }
}

class PackageInfoByPlatform extends PackageInfo {
  final String appName;

  final String packageName;

  final String version;

  final String buildNumber;

  PackageInfoByPlatform({
    this.appName,
    this.packageName,
    this.version,
    this.buildNumber,
  });
}
