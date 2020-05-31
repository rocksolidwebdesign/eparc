#ifndef MYC_RE_PAT_H
#define MYC_RE_PAT_H

#include "myc/re_pat_t.h"

myc_RePat_p
myc_re_pat_create(
    const char * pat_str);

void
myc_re_pat_init(
    myc_RePat_p p,
    const char * pat_str);

myc_RePat_p
myc_re_pat_alloc();

void
myc_re_pat_del(
    myc_RePat_P r);

#endif
