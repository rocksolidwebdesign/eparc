#ifndef MYC_REGEX_H
#define MYC_REGEX_H

#include "myc/regex_t.h"

myc_RegEx_p
myc_regex_create(
    const char * pat_str);

void
myc_regex_init(
    myc_RegEx_p re,
    const char * pat_str);

int
myc_regex_match(
    myc_RegEx_p re,
    const char * subj);

myc_StrBuf_p
myc_regex_m(
    myc_RegEx_p re);

myc_StrBuf_p
myc_regex_g(
    myc_RegEx_p re,
    const size_t k);

myc_StrBuf_p
myc_regex_get_match(
    myc_RegEx_p re,
    const char * subj);

myc_StrBuf_p
myc_regex_get_match_n(
    myc_RegEx_p re,
    const char * subj,
    const size_t n);

myc_RegEx_p
myc_regex_alloc();

void
myc_regex_del(myc_RegEx_P r);

#endif
