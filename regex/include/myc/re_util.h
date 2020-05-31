#ifndef MYC_RE_UTIL_H
#define MYC_RE_UTIL_H

#include "myc/re_mat_t.h"
#include "myc/re_pat_t.h"
#include "myc/strbuf.h"

myc_StrBuf_p
myc_re_util_g(
    myc_ReMat_p mat,
    const char * subj,
    const size_t k);

int
myc_re_util_match(
    myc_RePat_p pat,
    myc_ReMat_p mat,
    const char * subj);

#endif
