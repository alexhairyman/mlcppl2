find_package(LibArchive REQUIRED)
add_library(arcy STATIC "arcy_arcent.cc" "arcy_arcfile.cc" "arcy_util.cc")
target_link_libraries(arcy ${LibArchive_LIBRARIES})
