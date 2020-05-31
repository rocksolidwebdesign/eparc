#include "myc/re_mat.h"
#include "myc/re_mat_t.h"
#include "myc/plre.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

myc_ReMat_p
myc_re_mat_new(pcre2_code * pat)
{
    assert(pat != NULL);

    myc_ReMat_p mat = myc_re_mat_alloc();

    myc_re_mat_init(mat, pat);

    return mat;
}

void
myc_re_mat_init(
    myc_ReMat_p mat,
    pcre2_code * pat)
{
    assert(mat != NULL);
    assert(pat != NULL);

    mat->data = NULL;
    mat->is_err = 1;
    mat->rc = -1;
    mat->count = 0;

    mat->data = pcre2_match_data_create_from_pattern(pat, NULL);
    mat->count = pcre2_get_ovector_count(mat->data);
    mat->V = pcre2_get_ovector_pointer(mat->data);
}

myc_ReMat_p
myc_re_mat_alloc()
{
    return (myc_ReMat_p)
        malloc(sizeof(myc_ReMat));
}

void
myc_re_mat_del(myc_ReMat_P r)
{
    myc_ReMat_p p = *r;

    if (r != NULL && p != NULL)
    {
        if (p->data != NULL) {
            pcre2_match_data_free(p->data);

            p->data = NULL;
        }

        free(p);

        *r = NULL;
    }
}
