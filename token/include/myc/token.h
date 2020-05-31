#ifndef MYC_LEXER_TOKEN_H
#define MYC_LEXER_TOKEN_H

#include "myc/token_t.h"
#include "myc/strbuf_t.h"

#include <stdlib.h>

myc_Token_p myc_tok_new();
myc_Token_p myc_tok_create(
    const int type,
    const int ignore,
    const char * src);

void myc_tok_init(myc_Token_p tok);
void myc_tok_init_val(
    myc_Token_p tok,
    const int type,
    const int ignore,
    const char * src);

myc_Token_p myc_tok_alloc();

void myc_tok_copy_assign(
    myc_Token_p dest,
    const myc_Token_p src);

void myc_tok_set_str(
    myc_Token_p dest,
    const char *src);

void myc_tok_set_val(
    myc_Token_p tok,
    const int type,
    const int ignore,
    const char *src);

void myc_tok_set(
    myc_Token_p tok,
    const int type,
    const int ignore,
    const myc_StrBuf_p p);

void myc_tok_clean(myc_Token_p tok);
void myc_tok_del(myc_Token_P tok);

#endif
