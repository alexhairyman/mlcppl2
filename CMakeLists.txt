cmake_minimum_required(VERSION 2.8)
project(mlcppl2)

find_package(LibArchive REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/libmlcppl/include")

add_subdirectory("libmlcppl")
add_subdirectory("test")
