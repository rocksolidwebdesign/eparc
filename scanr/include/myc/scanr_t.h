#ifndef MYC_LEXER_SCANR_T_H
#define MYC_LEXER_SCANR_T_H

#include "myc/token_t.h"
#include "myc/tokpat_t.h"
#include "myc/tokpats_t.h"

#include <stdio.h>

enum MYC_SCANR_RC_ENUM
{
    MYC_RC_TOK = 0, // found a token
    MYC_RC_ERR,     // unexpected token
    MYC_RC_EOS,     // end of input string
    MYC_RC_IN,      // no input stream
};

struct myc_Scanr_t
{
    // return code
    int rc;

    // input stream
    const char * in;

    // current seek position
    size_t prev_pos;
    size_t pos;

    size_t num_pats;
    myc_TokPats_p pats;

    myc_Token_p tok;
};

typedef struct myc_Scanr_t myc_Scanr;
typedef myc_Scanr * myc_Scanr_p;
typedef myc_Scanr ** myc_Scanr_P;

#endif
