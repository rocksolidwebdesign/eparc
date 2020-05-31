myc_setup_test(
  "tokpat_c"
  MYC_SOURCES
    "tokpat.c"
  MYC_DEPS
    "tokpat"
)

myc_setup_test(
  "tokpats_c"
  MYC_SOURCES
    "tokpats.c"
  MYC_DEPS
    "tokpat"
)

myc_setup_test(
  "tokpats_raw"
  MYC_SOURCES
    "tokpats_raw.c"
  MYC_DEPS
    "tokpat"
)
