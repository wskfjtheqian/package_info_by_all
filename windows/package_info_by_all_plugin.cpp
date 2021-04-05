#include "include/package_info_by_all/package_info_by_all_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <map>
#include <memory>
#include <sstream>

namespace {

 std::string WStringToString(const std::wstring& wstr)
    {
        std::string str;
        int nLen = (int)wstr.length();
        str.resize(nLen, ' ');
        WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wstr.c_str(), nLen, (LPSTR)str.c_str(), nLen, NULL, NULL);
        return str;
    }

    std::string GetResource(std::wstring name)
    {

        TCHAR pFilePath[MAX_PATH] = { 0 };
        DWORD dwRet = GetModuleFileName(NULL, pFilePath, MAX_PATH);
        if (dwRet == 0)
        {
            return "";
        }

        DWORD dwSize = GetFileVersionInfoSize(pFilePath, NULL);
        if (dwSize == 0)
        {
            return "";
        }

        TCHAR* pBuf = (TCHAR*)malloc(dwSize + 1);
        memset(pBuf, 0, dwSize + 1);

        DWORD dwRtn = GetFileVersionInfo(pFilePath, NULL, dwSize, pBuf);
        if (dwRtn == 0)
        {
            return "";
        }

        LPVOID lpBuffer = NULL;
        UINT uLen = 0;

        std::wstring path = L"\\StringFileInfo\\080404b0\\";
        path.append(name);

        dwRtn = VerQueryValue(pBuf, path.c_str(), &lpBuffer, &uLen);
        if (dwRtn == 0)
        {
            delete pBuf;
            return "";
        }

        std::string retValue = WStringToString((TCHAR*)lpBuffer);
        free( pBuf);

        return retValue;
    }

class PackageInfoByAllPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  PackageInfoByAllPlugin();

  virtual ~PackageInfoByAllPlugin();

 private:
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

// static
void PackageInfoByAllPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "package_info_by_all",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<PackageInfoByAllPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

PackageInfoByAllPlugin::PackageInfoByAllPlugin() {}

PackageInfoByAllPlugin::~PackageInfoByAllPlugin() {}

void PackageInfoByAllPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
   if (method_call.method_name().compare("getAll") == 0) {

       flutter::EncodableMap map;
       map[flutter::EncodableValue("appName")] = flutter::EncodableValue(GetResource(L"ProductName"));
       map[flutter::EncodableValue("packageName")] = flutter::EncodableValue(GetResource(L"ProductName"));
       map[flutter::EncodableValue("version")] = flutter::EncodableValue(GetResource(L"ProductVersion"));
       map[flutter::EncodableValue("buildNumber")] = flutter::EncodableValue(GetResource(L"BuildNumber"));

       flutter::EncodableValue response(map);
       result->Success(&response);
   }
   else {
       result->NotImplemented();
   }
}

}  // namespace

void PackageInfoByAllPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  PackageInfoByAllPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
