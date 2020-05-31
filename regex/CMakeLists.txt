myc_setup_lib("regex"
  MYC_SOURCES
    "regex.c"
    "re_util.c"
    "re_grp.c"
    "re_mat.c"
    "re_pat.c"
  MYC_DEPS
    "strbuf"
    "plre"
)

add_subdirectory("test_regex")
