#ifndef MYC_RE_MAT_H
#define MYC_RE_MAT_H

#include "myc/re_mat_t.h"

myc_ReMat_p
myc_re_mat_new(
    pcre2_code * pat);

void
myc_re_mat_init(
    myc_ReMat_p re,
    pcre2_code * pat);

myc_ReMat_p
myc_re_mat_alloc();

void
myc_re_mat_del(
    myc_ReMat_P r);

#endif
