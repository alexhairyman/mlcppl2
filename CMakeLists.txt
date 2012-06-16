cmake_minimum_required(VERSION 2.8)
project(mlcppl2)

find_package(LibArchive REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/libmlcppl/include")

add_subdirectory("libmlcppl")
add_subdirectory("test")

configure_file("README" "README")
configure_file("LICENSE" "LICENSE")
configure_file("doc/mlcppl2.ini" "mlcppl2.doxyfile")
configure_file("doc/main.dox" "main.dox")
#file(GLOB DOCFILES "doc/docs/*.dox")
#foreach(DFILE IN LISTS DOCFILES)
	#message("${DFILE}")
	#get_filename_component(DFILE_R ${DFILE} NAME)
	#message("${DFILE_R}")
	#configure_file("${DFILE}" "docpages/${DFILE_R}")
#endforeach()
add_custom_target(doxy doxygen mlcppl2.doxyfile)
