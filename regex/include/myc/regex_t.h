#ifndef MYC_REGEX_T_H
#define MYC_REGEX_T_H

#include "myc/re_grp_t.h"
#include "myc/re_mat_t.h"
#include "myc/re_pat_t.h"
#include "myc/strbuf.h"

struct myc_RegEx_t
{
    myc_RePat_p pat;
    myc_ReMat_p mat;
    const char * subj;
};

typedef struct myc_RegEx_t myc_RegEx;
typedef myc_RegEx * myc_RegEx_p;
typedef myc_RegEx ** myc_RegEx_P;

#endif
