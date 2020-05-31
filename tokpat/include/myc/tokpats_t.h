#ifndef MYC_TOKPATS_T_H
#define MYC_TOKPATS_T_H

#include "myc/tokpat_t.h"

struct myc_TokPats_t
{
    myc_TokPat_p data;
    size_t len;
    size_t sz;
};

typedef struct myc_TokPats_t myc_TokPats;
typedef myc_TokPats * myc_TokPats_p;
typedef myc_TokPats ** myc_TokPats_P;

#endif
