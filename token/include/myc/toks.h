#ifndef MYC_LEXER_TOKEN_LIST_H
#define MYC_LEXER_TOKEN_LIST_H

#include "myc/toks_t.h"
#include "myc/token_t.h"

#include <stdlib.h>

myc_Toks_p myc_toks_create(const size_t len);
myc_Toks_p myc_toks_new();
myc_Toks_p myc_toks_alloc();

myc_Toks_p
myc_toks_resize(
    myc_Toks_p A,
    const size_t sz);

myc_Toks_p
myc_toks_grow(
    myc_Toks_p A);

myc_Token_p
myc_toks_at(
    myc_Toks_p A,
    const size_t index);

myc_Toks_p
myc_toks_push(
    myc_Toks_p A_arg,
    const myc_Token_p tok);

myc_Toks_p
myc_toks_put(
    myc_Toks_p A_arg,
    const int tok_type,
    const int tok_ignore,
    const char * tok_str);

void
myc_toks_pop(
    myc_Toks_p A);

void myc_toks_init(myc_Toks_p A);
void myc_toks_clean(myc_Toks_p A);
void myc_toks_del(myc_Toks_P A);

#endif
