#include "myc/re_util.h"
#include "myc/re_pat.h"
#include "myc/re_mat.h"
#include "myc/re_grp.h"
#include "myc/plre.h"
#include "myc/strbuf.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

int
myc_re_util_match(
    myc_RePat_p pat,
    myc_ReMat_p mat,
    const char * subj)
{
    assert(pat != NULL);
    assert(mat != NULL);
    assert(subj != NULL);
    assert(pat->data != NULL);
    assert(mat->data != NULL);

    mat->rc = myc_plre_match(
        pat->data,
        mat->data,
        subj
    );

    mat->is_err = mat->rc <= 0;

    mat->len = mat->is_err
        ? 0
        : myc_plre_g_len(mat->V, 0);

    return !mat->is_err;
}

myc_StrBuf_p
myc_re_util_g(
    myc_ReMat_p mat,
    const char * subj,
    const size_t k)
{
    assert(mat != NULL);
    assert(subj != NULL);
    assert(mat->data != NULL);

    if (mat->is_err || k >= mat->count) {
        return NULL;
    }

    myc_ReGrp_p g =
        myc_re_grp_create(mat->data, subj, k);

    myc_StrBuf_p out =
        myc_re_grp_str(g);

    myc_re_grp_del(&g);

    return out;
}
