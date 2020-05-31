#ifndef MYC_LEXER_TOKEN_LIST_RAW_H
#define MYC_LEXER_TOKEN_LIST_RAW_H

#include "myc/token_t.h"

#include <stdlib.h>

myc_Token_p
myc_toks_raw_create(
    const size_t len);

myc_Token_p
myc_toks_raw_new(
    const size_t sz);

myc_Token_p
myc_toks_raw_alloc(
    const size_t sz);

myc_Token_p
myc_toks_raw_realloc(
    myc_Token_p t,
    const size_t sz);

myc_Token_p
myc_toks_raw_resize(
    myc_Token_p t,
    const size_t sz);

myc_Token_p
myc_toks_raw_resize_init(
    myc_Token_p t,
    const size_t cur_sz,
    const size_t new_sz);

myc_Token_p
myc_toks_raw_grow(
    myc_Token_p t,
    const size_t cur_sz);

myc_Token_p
myc_toks_raw_grow_init(
    myc_Token_p t,
    const size_t cur_sz);

void
myc_toks_raw_init(
    myc_Token_p T,
    const size_t len);

void
myc_toks_raw_clean(
    myc_Token_p T,
    const size_t len);

void
myc_toks_raw_del(
    myc_Token_P Z,
    const size_t len);

#endif
