
# CMakeLists.txt — basic build file for a small C++ app + one test

# Need CMake 3.20 or newer
cmake_minimum_required(VERSION 3.20)

# Project name; we use C++ only
project(temp_converter LANGUAGES CXX)

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find headers under include/
include_directories(${CMAKE_SOURCE_DIR}/include)

# Build the CLI app from these source files
add_executable(temp_app
  src/main.cpp
  src/convert.cpp
)

# ----- Tests -----
# Turn on testing support
include(CTest)
enable_testing()

# Build the test program (reuses the same implementation file)
add_executable(converter_tests
  test/run_tests.cpp
  src/convert.cpp
)

# Let CTest run it (0 = pass, non-zero = fail)
add_test(NAME unit COMMAND converter_tests)


# ----- Install rules -----
include(GNUInstallDirs)

# Install the CLI program into install/bin
install(TARGETS temp_app
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# Install public headers into install/include
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
