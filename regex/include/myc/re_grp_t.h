#ifndef MYC_RE_GRP_T_H
#define MYC_RE_GRP_T_H

#include <pcre2.h>

struct myc_ReGrp_t
{
    const char * subj;
    PCRE2_SIZE * V;
    size_t k;
    size_t len;
    size_t start_at;
    size_t end_at;
};

typedef struct myc_ReGrp_t myc_ReGrp;
typedef myc_ReGrp * myc_ReGrp_p;
typedef myc_ReGrp ** myc_ReGrp_P;

#endif
