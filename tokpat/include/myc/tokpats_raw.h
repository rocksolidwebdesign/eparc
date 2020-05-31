#ifndef MYC_TOKPATS_RAW_H
#define MYC_TOKPATS_RAW_H

#include "myc/tokpat_t.h"

myc_TokPat_p
myc_tokpats_raw_alloc(
    const size_t n);

myc_TokPat_p
myc_tokpats_raw_realloc(
    myc_TokPat_p A,
    const size_t n);

void
myc_tokpats_raw_clean(
    myc_TokPat_p A,
    const size_t n);

void
myc_tokpats_raw_del(
    myc_TokPat_P Z,
    const size_t n);

#endif
