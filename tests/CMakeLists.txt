include_directories(${TEST_SOURCE_DIR}/include)
add_executable(BWTTest test.cpp)
target_link_libraries(BWTTest cmsbwt)
add_test(NAME Test COMMAND BWTTest)
