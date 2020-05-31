enable_testing()

add_library(myc_lib_test_helpers INTERFACE)

target_include_directories(myc_lib_test_helpers INTERFACE
  "${CMAKE_CURRENT_SOURCE_DIR}/include")
