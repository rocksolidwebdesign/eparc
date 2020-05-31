myc_setup_lib("plre"
  MYC_SOURCES
    "plre.c"
  MYC_CONAN
    "pcre2"
  MYC_DEFS
    "PCRE2_NEVER_UCP"
    "PCRE2_CODE_UNIT_WIDTH=8"
    "PCRE2_NEVER_BACKSLASH_C"
)

add_subdirectory("test_plre")
