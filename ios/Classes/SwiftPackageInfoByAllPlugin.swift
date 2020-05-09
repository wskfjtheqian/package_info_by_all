import Flutter
import UIKit

public class SwiftPackageInfoByAllPlugin: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: "package_info_by_all", binaryMessenger: registrar.messenger())
    let instance = SwiftPackageInfoByAllPlugin()
    registrar.addMethodCallDelegate(instance, channel: channel)
  }

  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    if(call.method == "getAll"){
        let airportsDic:Dictionary<String,Any> = [
            "appName":  Bundle.main.infoDictionary?["CFBundleDisplayName"]as Any,
            "packageName": Bundle.main.bundleIdentifier as Any,
            "version":Bundle.main.infoDictionary?["CFBundleShortVersionString"] as Any,
            "buildNumber": Bundle.main.infoDictionary?["CFBundleVersion"]as Any,
        ]
        result(airportsDic)
    }else{
        result(FlutterMethodNotImplemented)
    }
  }
}
