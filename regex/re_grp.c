#include "myc/re_grp.h"
#include "myc/re_grp_t.h"
#include "myc/re_mat_t.h"
#include "myc/plre.h"
#include "myc/strbuf.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

myc_ReGrp_p
myc_re_grp_create(
    pcre2_match_data * mat,
    const char * subj,
    const size_t k)
{
    assert(mat != NULL);
    assert(subj != NULL);

    myc_ReGrp_p grp = myc_re_grp_alloc();

    myc_re_grp_init(grp, mat, subj, k);

    return grp;
}

void
myc_re_grp_init(
    myc_ReGrp_p grp,
    pcre2_match_data * mat,
    const char * subj,
    const size_t k)
{
    assert(grp != NULL);
    assert(mat != NULL);
    assert(subj != NULL);

    grp->subj = subj;

    grp->V = pcre2_get_ovector_pointer(mat);

    assert(grp->V != NULL);

    grp->k = k;
}

myc_StrBuf_p
myc_re_grp_str(
    myc_ReGrp_p grp)
{
    const size_t len = myc_re_grp_len(grp);

    myc_StrBuf_p str = myc_strbuf_new_sz(len);

    myc_plre_get_group(
        grp->V,
        grp->k,
        grp->subj,
        str->data,
        len
    );

    str->len = len;

    return str;
}

size_t myc_re_grp_len(myc_ReGrp_p grp) {
    return myc_plre_g_len(grp->V, grp->k);
}

const char * myc_re_grp_cstr(myc_ReGrp_p grp) {
    return myc_plre_g_start(grp->V, grp->k, grp->subj);
}

size_t myc_re_grp_k_begin(myc_ReGrp_p grp) {
    return myc_plre_g_k1(grp->V, grp->k);
}

size_t myc_re_grp_k_end(myc_ReGrp_p grp) {
    return myc_plre_g_k1(grp->V, grp->k);
}

myc_ReGrp_p
myc_re_grp_alloc()
{
    return (myc_ReGrp_p)
        malloc(sizeof(myc_ReGrp));
}

void
myc_re_grp_del(myc_ReGrp_P r)
{
    myc_ReGrp_p p = *r;

    if (r != NULL && p != NULL)
    {
        free(p);

        *r = NULL;
    }
}
