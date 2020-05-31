#ifndef MYC_LEXER_SCANR_H
#define MYC_LEXER_SCANR_H

#include "myc/scanr_t.h"
#include "myc/token_t.h"
#include "myc/tokpat_t.h"
#include "myc/tokpats_t.h"

myc_Scanr_p
myc_scanr_create(
    myc_TokPats_p pats);

myc_Scanr_p
myc_scanr_new();

myc_Scanr_p
myc_scanr_alloc();

void
myc_scanr_init(
    myc_Scanr_p obj,
    myc_TokPats_p pats);

void
myc_scanr_set_in(
    myc_Scanr_p obj,
    const char * in);

void
myc_scanr_push_pat(
    myc_Scanr_p obj,
    const myc_TokPat_p pat);

void
myc_scanr_put_pat(
    myc_Scanr_p obj,
    const int type,
    const int ignore,
    const char * pat_str);

void
myc_scanr_copy_tok(
    myc_Scanr_p obj,
    myc_Token_p);

myc_Token_p
myc_scanr_get_tok(
    myc_Scanr_p obj);

myc_StrBuf_p
myc_scanr_get_str(
    myc_TokPats_p pats,
    const size_t i);

int
myc_scanr_read(
    myc_Scanr_p obj);

int
myc_scanr_match_token(
    myc_Scanr_p obj);

void
myc_scanr_del(
    myc_Scanr_P ref);

#endif
