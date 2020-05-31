#ifndef MYC_TOKPAT_H
#define MYC_TOKPAT_H

#include "myc/tokpat_t.h"

myc_TokPat_p
myc_tokpat_create(
    const int type,
    const int ignore,
    const char * pat_str);

void
myc_tokpat_init(
    myc_TokPat_p p,
    const int type,
    const int ignore,
    const char * str);

void
myc_tokpat_set(
    myc_TokPat_p A,
    const int type,
    const int ignore,
    const char * pat_str);

void
myc_tokpat_copy(
    myc_TokPat_p A,
    const myc_TokPat_p B);

myc_TokPat_p
myc_tokpat_alloc();

void
myc_tokpat_clean(
    myc_TokPat_p A);

void
myc_tokpat_del(
    myc_TokPat_P ref);

#endif
