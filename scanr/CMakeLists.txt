myc_setup_lib(
  "scanr"
  MYC_SOURCES
    "scanr.c"
  MYC_DEPS
    "token"
    "tokpat"
)

add_subdirectory("test_scanr")
