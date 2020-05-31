cmake_minimum_required(VERSION 3.17)

include("guard.cmake")

project(MyExpressionParser)

enable_testing()

option(MORE_WARNINGS   "Show lots and lots of warnings, LOTS I TELL YOU!." ON)
option(BUILD_TESTS     "Build the accompanying tests." ON)
option(ENABLE_VALGRIND "Run tests with valgrind for memory leaks." OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(conan_paths "${CMAKE_BINARY_DIR}/conan_paths.cmake")

if(EXISTS "${conan_paths}")
  include("${conan_paths}")
endif()

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)

if(MSVC)
  add_compile_options("/W4")
else()
  add_compile_options("-Wall" "-Wextra" "-Wpedantic" "-Wconversion")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include("helpers.cmake")
include("setup_lib.cmake")
include("setup_test.cmake")

add_subdirectory("test_helpers")
add_subdirectory("plre")
add_subdirectory("strbuf")
add_subdirectory("regex")
add_subdirectory("token")
add_subdirectory("tokpat")
add_subdirectory("scanr")
add_subdirectory("parser")
add_subdirectory("main")
