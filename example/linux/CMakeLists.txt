cmake_minimum_required(VERSION 3.15)
project(linux)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(flutter)
include_directories(flutter/ephemeral/cpp_client_wrapper_glfw/include)
include_directories(flutter/ephemeral/.plugin_symlinks/package_info_by_all/linux)

set(SOURCE_FILES main.cc)
add_custom_target(package_info_by_all_example)
add_executable(untitled ${SOURCE_FILES})