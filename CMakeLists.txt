set(CMAKE_EXTRA_GENERATOR "CodeBlocks")
if ("${CMAKE_BUILD_TYPE}" STREQUAL "debug")
	set(CMAKE_CXX_FLAGS "-Wall")
endif()
cmake_minimum_required(VERSION 2.8)
project(mlcppl2)

find_package(LibArchive REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/libmlcppl/include")

add_subdirectory("libmlcppl")
add_subdirectory("test")

configure_file("README.md" "README.md")
configure_file("support/LICENSE" "LICENSE")
configure_file("doc/mlcppl2.ini" "mlcppl2.doxyfile")
configure_file("doc/main.dox" "main.dox")
configure_file("support/build.sh" "build.sh")
configure_file("support/build.ninja" "build.ninja")
configure_file("support/Jamfile" "Jamfile")

#file(GLOB DOCFILES "doc/docs/*.dox")
#foreach(DFILE IN LISTS DOCFILES)
	#message("${DFILE}")
	#get_filename_component(DFILE_R ${DFILE} NAME)
	#message("${DFILE_R}")
	#configure_file("${DFILE}" "docpages/${DFILE_R}")
#endforeach()
add_custom_target(doxy doxygen mlcppl2.doxyfile)

