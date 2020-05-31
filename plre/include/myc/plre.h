#ifndef MYC_PLRE_H
#define MYC_PLRE_H

#include <pcre2.h>

pcre2_code *
myc_plre_create(
    const char * pattern);

pcre2_code *
myc_plre_compile(
    const char * pattern,
    int * err_n,
    PCRE2_SIZE * err_i);

int
myc_plre_match(
    pcre2_code * re,
    pcre2_match_data * m,
    const char * subj);

size_t
myc_plre_m_count(
    pcre2_match_data * m);

const char * myc_plre_g_start(PCRE2_SIZE * V, const size_t k, const char * subj);
size_t myc_plre_g_k1(PCRE2_SIZE * V, const size_t k);
size_t myc_plre_g_k2(PCRE2_SIZE * V, const size_t k);
size_t myc_plre_g_len(PCRE2_SIZE * V, const size_t k);

size_t
myc_plre_get_group(
    PCRE2_SIZE * V,
    const size_t k,
    const char * subj,
    char * dest,
    const size_t dest_sz);

void
myc_plre_print_err(
    const char * pattern,
    const int err_n,
    const PCRE2_SIZE err_i);

#endif
