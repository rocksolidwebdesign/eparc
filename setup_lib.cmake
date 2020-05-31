function(_myc_setup_lib_target target_name lib_sources deps conan_deps compile_defs)
  add_library("${target_name}")

  _myc_setup_sources("${target_name}" "${lib_sources}")

  _myc_setup_target("${target_name}" "${deps}" "${conan_deps}" "${compile_defs}")
endfunction()

function(_myc_setup_lib name lib_sources deps conan_deps compile_defs)
  set(lib_name "myc_lib_${name}")

  message("  Lib Target Name: ${lib_name}")

  set(CMAKE_C_FLAGS "${g_c_flags}")

  set(lib_includes "${CMAKE_CURRENT_SOURCE_DIR}/include")

  message("  Includes: ${lib_includes}")

  _myc_setup_lib_target(
    "${lib_name}"
    "${lib_sources}"
    "${deps}"
    "${conan_deps}"
    "${compile_defs}"
  )

  target_include_directories("${lib_name}" PUBLIC "${lib_includes}")
endfunction()

function(myc_setup_lib)
  set(array_name "NONE")
  set(target_name "${ARGV0}")

  message("")
  message("------------------------------------------------------------")
  message("Setting Up Lib '${target_name}' in ${CMAKE_CURRENT_SOURCE_DIR}")
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

  _myc_setup_lib(
    "${target_name}"
    "${sources}"
    "${deps}"
    "${conan_deps}"
    "${compile_defs}"
  )
endfunction()
