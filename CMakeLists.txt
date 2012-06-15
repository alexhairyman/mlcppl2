cmake_minimum_required(VERSION 2.8)
project(mlcppl2)

find_package(LibArchive REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/libmlcppl/include")

add_subdirectory("libmlcppl")
add_subdirectory("test")

configure_file("README" "README")
configure_file("LICENSE" "LICENSE")
configure_file("doc/mlcppl2.ini" "mlcppl2.dox")
add_custom_target(doxy doxygen mlcppl2.dox)
