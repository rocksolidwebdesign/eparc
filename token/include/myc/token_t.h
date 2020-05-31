#ifndef MYC_LEXER_TOKEN_T_H
#define MYC_LEXER_TOKEN_T_H

#include "myc/strbuf_t.h"

#include <stdio.h>

struct myc_Token_t
{
    int type;
    int ignore;
    myc_StrBuf_p str;
};

typedef struct myc_Token_t myc_Token;
typedef myc_Token * myc_Token_p;
typedef myc_Token ** myc_Token_P;

#endif
