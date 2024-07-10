cmake_minimum_required(VERSION 3.0.0)
project(GlogGflagsTest VERSION 0.1.0 LANGUAGES C CXX)
# glog基于c++ 14
set(CMAKE_CXX_STANDARD 14)

# gflags库带有.cmake文件，可以直接使用find_package
find_package(gflags)
if(NOT gflags_FOUND)
    message("gflags not found")
else()
    message("gflags found")
    message("gflags include dir: ${gflags_INCLUDE_DIRS}")
    message("gflags library: ${gflags_LIBRARIES}")
endif()

include_directories("./include")
# 使用file+GLOB命令将src目录下的所有.cpp文件赋值给变量SOURCES
file(GLOB SOURCES "./src/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(GlogGflagsTest main.cpp ${SOURCES})
# 使用pkg-config可以确定链接库名称为glog和gflags
target_link_libraries(GlogGflagsTest glog gflags)
