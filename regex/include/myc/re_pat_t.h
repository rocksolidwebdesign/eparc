#ifndef MYC_RE_PAT_T_H
#define MYC_RE_PAT_T_H

#include <pcre2.h>

struct myc_RePat_t
{
    pcre2_code * data;
    int is_err;
    int err_n;
    PCRE2_SIZE err_i;
    PCRE2_UCHAR err[1024];
};

typedef struct myc_RePat_t myc_RePat;
typedef myc_RePat * myc_RePat_p;
typedef myc_RePat ** myc_RePat_P;

#endif
