include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(example cmsbwt_example.cpp)
target_link_libraries(example cmsbwt)
