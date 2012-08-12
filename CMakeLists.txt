cmake_minimum_required(VERSION 2.8)
project(mlcppl2)

set(CMAKE_CXX_FLAGS "-g -Wall")

if(CLX)
  set(CMAKE_CXX_COMPILER "clang++")
endif()

include_directories("libmlcppl/include")
add_subdirectory("libmlcppl")
add_subdirectory("test")

configure_file("doc/mlcppl2.ini" "mlcppl2.doxyfile")
configure_file("doc/main.dox" "main.dox")
 
add_custom_target(doxy doxygen mlcppl2.doxyfile)

