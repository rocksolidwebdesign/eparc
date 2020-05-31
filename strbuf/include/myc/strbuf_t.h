#ifndef MYC_STRBUF_T_H
#define MYC_STRBUF_T_H

#include <stdlib.h>

struct myc_StrBuf_t
{
    size_t len;
    size_t sz;
    char * data;
};

typedef struct myc_StrBuf_t myc_StrBuf;
typedef myc_StrBuf * myc_StrBuf_p;
typedef myc_StrBuf ** myc_StrBuf_P;

#endif
