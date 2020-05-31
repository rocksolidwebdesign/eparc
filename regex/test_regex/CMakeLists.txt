myc_setup_test(
  "re_pat"
  MYC_SOURCES
    "re_pat.c"
  MYC_DEPS
    "regex"
    "strbuf"
)

myc_setup_test(
  "re_mat"
  MYC_SOURCES
    "re_mat.c"
  MYC_DEPS
    "regex"
    "strbuf"
)

myc_setup_test(
  "re_grp"
  MYC_SOURCES
    "re_grp.c"
  MYC_DEPS
    "regex"
    "strbuf"
)

myc_setup_test(
  "re_util"
  MYC_SOURCES
    "re_util.c"
  MYC_DEPS
    "regex"
    "strbuf"
)

myc_setup_test(
  "regex"
  MYC_SOURCES
    "regex.c"
  MYC_DEPS
    "regex"
    "strbuf"
)
