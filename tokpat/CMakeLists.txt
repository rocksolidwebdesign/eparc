myc_setup_lib(
  "tokpat"
  MYC_SOURCES
    "tokpat.c"
    "tokpats.c"
    "tokpats_raw.c"
  MYC_DEPS
    "regex"
)

add_subdirectory("test_tokpat")
