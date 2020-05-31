enable_testing()

add_executable(eparc main.c)

target_include_directories(eparc PUBLIC "include")
target_link_libraries(eparc PUBLIC myc_lib_parser)
