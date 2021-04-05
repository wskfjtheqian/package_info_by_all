package com.wskfjt.package_info_by_all

import android.content.Context
import android.content.pm.PackageInfo
import android.content.pm.PackageManager
import androidx.annotation.NonNull
import androidx.core.content.pm.PackageInfoCompat.getLongVersionCode

import io.flutter.embedding.engine.plugins.FlutterPlugin
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result
import io.flutter.plugin.common.PluginRegistry.Registrar

/** PackageInfoByAllPlugin */
class PackageInfoByAllPlugin : FlutterPlugin, MethodCallHandler {
    private lateinit var channel: MethodChannel
    private lateinit var applicationContext: Context

    override fun onAttachedToEngine(@NonNull flutterPluginBinding: FlutterPlugin.FlutterPluginBinding) {
        channel = MethodChannel(flutterPluginBinding.binaryMessenger, "package_info_by_all")
        channel.setMethodCallHandler(this)
        applicationContext = flutterPluginBinding.applicationContext
    }

    override fun onMethodCall(@NonNull call: MethodCall, @NonNull result: Result) {
        try {
            if (call.method == "getAll" && null != applicationContext) {
                val pm: PackageManager = applicationContext.packageManager
                val info: PackageInfo = pm.getPackageInfo(applicationContext.packageName, 0)
                val map: MutableMap<String, String> = HashMap()
                map["appName"] = info.applicationInfo.loadLabel(pm).toString()
                map["packageName"] = applicationContext.packageName
                map["version"] = info.versionName
                map["buildNumber"] = getLongVersionCode(info).toString()
                result.success(map)
            } else {
                result.notImplemented()
            }
        } catch (ex: PackageManager.NameNotFoundException) {
            result.error("Name not found", ex.message, null)
        }
    }

    override fun onDetachedFromEngine(@NonNull binding: FlutterPlugin.FlutterPluginBinding) {
        channel.setMethodCallHandler(null)
    }
}
