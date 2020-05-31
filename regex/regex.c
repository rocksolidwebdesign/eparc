#include "myc/regex.h"
#include "myc/re_util.h"
#include "myc/re_pat.h"
#include "myc/re_mat.h"
#include "myc/plre.h"
#include "myc/strbuf.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

myc_RegEx_p
myc_regex_create(
    const char * pat_str)
{
    myc_RegEx_p re = myc_regex_alloc();

    myc_regex_init(re, pat_str);

    return re;
}

void
myc_regex_init(
    myc_RegEx_p re,
    const char * pat_str)
{
    re->pat = myc_re_pat_create(pat_str);
    re->mat = myc_re_mat_new(re->pat->data);
}

int
myc_regex_match(
    myc_RegEx_p re,
    const char * subj)
{
    re->subj = subj;

    return myc_re_util_match(re->pat, re->mat, subj);
}

myc_StrBuf_p
myc_regex_m(
    myc_RegEx_p re)
{
    assert(re->subj != NULL);

    return myc_regex_g(re, 0);
}

myc_StrBuf_p
myc_regex_g(
    myc_RegEx_p re,
    const size_t k)
{
    assert(re->subj != NULL);

    return myc_re_util_g(re->mat, re->subj, k);
}

myc_StrBuf_p
myc_regex_get_match(
    myc_RegEx_p re,
    const char * subj)
{
    return myc_regex_get_match_n(re, subj, 0);
}

myc_StrBuf_p
myc_regex_get_match_n(
    myc_RegEx_p re,
    const char * subj,
    const size_t n)
{
    myc_regex_match(re, subj);
    return myc_regex_g(re, n);
}

myc_RegEx_p
myc_regex_alloc()
{
    return (myc_RegEx_p)
        malloc(sizeof(myc_RegEx));
}

void
myc_regex_del(myc_RegEx_P r)
{
    myc_RegEx_p p = *r;

    if (r != NULL && p != NULL)
    {
        if (p->mat != NULL) {
            myc_re_mat_del(&(p->mat));

            p->mat = NULL;
        }

        if (p->pat != NULL) {
            myc_re_pat_del(&(p->pat));

            p->pat = NULL;
        }

        free(p);

        *r = NULL;
    }
}
