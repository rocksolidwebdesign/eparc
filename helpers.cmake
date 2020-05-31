function(_myc_setup_sources target_name target_sources)
  foreach(src_file ${target_sources})
    message("  Adding: ${src_file}")

    target_sources("${target_name}" PUBLIC "${src_file}")
  endforeach()
endfunction()

function(_myc_setup_target target_name deps conan_deps compile_defs)
  message("  Configuring Target ${target_name}")

  foreach(dep_name ${deps})
    set(link_dep "myc_lib_${dep_name}")

    message("  Linking: ${link_dep}")

    target_link_libraries("${target_name}" PUBLIC "${link_dep}")
  endforeach()

  foreach(cdef ${compile_defs})
    message("  Define: ${cdef}")

    target_compile_definitions("${target_name}" PUBLIC "${cdef}")
  endforeach()

  foreach(conan_dep ${conan_deps})
    message("  Finding: ${conan_dep}")

    find_package("${conan_dep}")

    if(${conan_dep}_FOUND)
      target_link_libraries("${target_name}" PUBLIC "${conan_dep}::${conan_dep}")
    else()
      message("  ERROR ${conan_dep} NOT FOUND")
    endif()
  endforeach()
endfunction()
