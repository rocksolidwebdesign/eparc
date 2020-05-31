#ifndef MYC_RE_MAT_T_H
#define MYC_RE_MAT_T_H

#include <pcre2.h>

struct myc_ReMat_t
{
    pcre2_match_data * data;
    PCRE2_SIZE * V;

    int is_err;
    int rc;

    size_t len;
    size_t count;
};

typedef struct myc_ReMat_t myc_ReMat;
typedef myc_ReMat * myc_ReMat_p;
typedef myc_ReMat ** myc_ReMat_P;

#endif
