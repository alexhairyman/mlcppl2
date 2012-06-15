
include_directories("${CMAKE_SOURCE_DIR}/libmlcppl/include")

add_definitions("-D__TEST_PP")

add_library(arcy STATIC "src/arcy_util.cc" "src/arcy_arcfile.cc" "src/arcy_arcent.cc")
configure_file("include/arcy.hh" "arcy.hh")
target_link_libraries(arcy ${LibArchive_LIBRARIES})
set_target_properties(arcy PROPERTIES LINK_FLAGS "-Os")

