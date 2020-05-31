myc_setup_test(
  "token"
  MYC_SOURCES "token.c"
  MYC_DEPS    "token"
)

myc_setup_test(
  "toks_raw"
  MYC_SOURCES "toks_raw.c"
  MYC_DEPS    "token"
)

myc_setup_test(
  "toks"
  MYC_SOURCES "toks.c"
  MYC_DEPS    "token"
)
