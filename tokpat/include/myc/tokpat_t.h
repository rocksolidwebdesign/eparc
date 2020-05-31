#ifndef MYC_TOKPAT_T_H
#define MYC_TOKPAT_T_H

#include "myc/regex_t.h"

#include <stdlib.h>

struct myc_TokPat_t
{
    int type;
    int ignore;
    myc_RegEx_p re;
    myc_StrBuf_p pat_str;
};

typedef struct myc_TokPat_t myc_TokPat;
typedef myc_TokPat * myc_TokPat_p;
typedef myc_TokPat ** myc_TokPat_P;

#endif
