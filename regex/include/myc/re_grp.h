#ifndef MYC_RE_GRP_H
#define MYC_RE_GRP_H

#include "myc/re_grp_t.h"
#include "myc/strbuf_t.h"

myc_ReGrp_p
myc_re_grp_create(
    pcre2_match_data * mat,
    const char * subj,
    const size_t k);

void
myc_re_grp_init(
    myc_ReGrp_p grp,
    pcre2_match_data * mat,
    const char * subj,
    const size_t k);

myc_StrBuf_p
myc_re_grp_str(
    myc_ReGrp_p grp);

const char * myc_re_grp_cstr(myc_ReGrp_p grp);
size_t myc_re_grp_len(myc_ReGrp_p grp);
size_t myc_re_grp_k_begin(myc_ReGrp_p grp);
size_t myc_re_grp_k_end(myc_ReGrp_p grp);

myc_ReGrp_p
myc_re_grp_alloc();

void
myc_re_grp_del(myc_ReGrp_P r);

#endif
