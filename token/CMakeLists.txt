myc_setup_lib("token"
  MYC_SOURCES
    "token.c"
    "toks.c"
    "toks_raw.c"
  MYC_DEPS
    "strbuf"
)

add_subdirectory("test_token")
