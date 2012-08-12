
add_executable(smalltest1 "smalltest1.cc")
target_link_libraries(smalltest1 arcy)

add_executable(arcutil_test1 "arcutil_test1.cc")
target_link_libraries(arcutil_test1 arcy)

add_executable(arcfile_test1 "arcfile_test1.cc")
target_link_libraries(arcfile_test1 arcy "boost_filesystem" "boost_system")

add_executable(mlarray_test "mlarray_test.cc")
#target_link_libraries(mlarray_test
