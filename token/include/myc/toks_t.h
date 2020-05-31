#ifndef MYC_LEXER_TOKEN_LIST_T_H
#define MYC_LEXER_TOKEN_LIST_T_H

#include "myc/token_t.h"

#include <stdlib.h>

struct myc_Toks_t
{
    size_t len;
    size_t sz;
    myc_Token_p data;
};

typedef struct myc_Toks_t myc_Toks;
typedef myc_Toks * myc_Toks_p;
typedef myc_Toks ** myc_Toks_P;

#endif
