import Flutter
import UIKit

public class SwiftPackageInfoByAllPlugin: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: "package_info_by_all", binaryMessenger: registrar.messenger())
    let instance = SwiftPackageInfoByAllPlugin()
    registrar.addMethodCallDelegate(instance, channel: channel)
  }

  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    result("iOS " + UIDevice.current.systemVersion)
  }


//   - (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
//     if ([call.method isEqualToString:@"getAll"]) {
//       result(@{
//         @"appName" : [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"]
//             ?: [NSNull null],
//         @"packageName" : [[NSBundle mainBundle] bundleIdentifier] ?: [NSNull null],
//         @"version" : [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"]
//             ?: [NSNull null],
//         @"buildNumber" : [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleVersion"]
//             ?: [NSNull null],
//       });
//     } else {
//       result(FlutterMethodNotImplemented);
//     }
//   }

}
