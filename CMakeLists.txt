CMAKE_MINIMUM_REQUIRED(VERSION 3.15.4)
PROJECT(cmsbwt)

# Include Headers
include_directories(include)

# Include Source Files for Compilation
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Package library
add_library(cmsbwt SHARED ${SOURCES})
set_target_properties(cmsbwt PROPERTIES PUBLIC_HEADER "${HEADERS}")

# Tests
enable_testing()
add_subdirectory(tests)

# Examples
add_subdirectory(examples)

# sudo make install to apply
install(TARGETS cmsbwt
  LIBRARY DESTINATION /usr/local/lib
  PUBLIC_HEADER DESTINATION /usr/local/include)
