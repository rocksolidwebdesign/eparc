function(_myc_setup_test_sources target_name test_sources)
  foreach(src_file ${test_sources})
    set(test_src_file "test_${src_file}")
    message("  Adding: ${test_src_file}")

    target_sources("${exe_name}" PUBLIC "${test_src_file}")
  endforeach()
endfunction()

function(_myc_setup_test_exe target_name test_sources deps conan_deps compile_defs)
  add_executable("${target_name}")

  _myc_setup_test_sources("${target_name}" "${test_sources}")

  _myc_setup_target("${target_name}" "${deps}" "${conan_deps}" "${compile_defs}")
endfunction()

function(_myc_setup_test name test_sources deps conan_deps compile_defs)
  set(exe_name "test_myc_${name}")

  message("  Test Target Name: ${exe_name}")

  set(CMAKE_C_FLAGS "${g_c_flags}")

  list(APPEND deps "test_helpers")

  _myc_setup_test_exe(
    "${exe_name}"
    "${test_sources}"
    "${deps}"
    "${conan_deps}"
    "${compile_defs}"
  )

  enable_testing()

  set(root_dir "${CMAKE_SOURCE_DIR}")
  set(bin_dir  "${CMAKE_CURRENT_BINARY_DIR}")
  set(bin_path "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${exe_name}")

  if(ENABLE_VALGRIND AND "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(log_file "${bin_dir}/${exe_name}.valgrind.txt")
    set(grind_cmd )

    add_test(NAME "grindtest_${exe_name}"
      COMMAND "${root_dir}/grind_test.sh" "${bin_path}" "${log_file}")
  else()
    add_test(NAME "runtest_${exe_name}"
      COMMAND "${bin_path}")
  endif()
endfunction()

function(myc_setup_test)
  set(array_name "NONE")
  set(target_name "${ARGV0}")

  message("")
  message("------------------------------------------------------------")
  message("Setting Up Test '${target_name}' in ${CMAKE_CURRENT_SOURCE_DIR}")
  message("------------------------------------------------------------")

  set(i 1)
  while(i LESS ARGC)
    set(arg_name "ARGV${i}")

    set(arg ${${arg_name}})

    if("${arg}" STREQUAL "MYC_SOURCES")
      set(array_name "sources")
    elseif("${arg}" STREQUAL "MYC_DEPS")
      set(array_name "deps")
    elseif("${arg}" STREQUAL "MYC_CONAN")
      set(array_name "conan_deps")
    elseif("${arg}" STREQUAL "MYC_DEFS")
      set(array_name "compile_defs")
    else()
      if(array_name STREQUAL "NONE")
        message(FATAL_ERROR "UNKNOWN ARRAY TYPE")
      endif()

      list(APPEND ${array_name} "${arg}")
    endif()

    math(EXPR i "${i} + 1")
  endwhile()

  _myc_setup_test(
    "${target_name}"
    "${sources}"
    "${deps}"
    "${conan_deps}"
    "${compile_defs}"
  )
endfunction()
