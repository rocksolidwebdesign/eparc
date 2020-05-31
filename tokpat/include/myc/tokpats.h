#ifndef MYC_TOKPATS_H
#define MYC_TOKPATS_H

#include "myc/tokpats_t.h"

myc_TokPats_p
myc_tokpats_new();

myc_TokPats_p
myc_tokpats_alloc();

void
myc_tokpats_init(
    myc_TokPats_p A,
    const size_t sz);

myc_TokPat_p
myc_tokpats_at(
    myc_TokPats_p A,
    const size_t i);

void
myc_tokpats_push(
    myc_TokPats_p A,
    const myc_TokPat_p pat);

void
myc_tokpats_put(
    myc_TokPats_p A,
    const int type,
    const int ignore,
    const char * str);

void
myc_tokpats_pop(
    myc_TokPats_p A);

void
myc_tokpats_grow(
    myc_TokPats_p A,
    const size_t sz);

void
myc_tokpats_clean(
    myc_TokPats_p A);

void
myc_tokpats_del(
    myc_TokPats_P Z);

#endif
