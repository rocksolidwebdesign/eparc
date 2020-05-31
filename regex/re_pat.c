#include "myc/re_pat.h"
#include "myc/re_pat_t.h"
#include "myc/re_mat.h"
#include "myc/plre.h"
#include "myc/strbuf.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

myc_RePat_p
myc_re_pat_create(
    const char * pat_str)
{
    myc_RePat_p pat = myc_re_pat_alloc();

    myc_re_pat_init(pat, pat_str);

    return pat;
}

void
myc_re_pat_init(
    myc_RePat_p pat,
    const char * pat_str)
{
    assert(pat != NULL);

    pat->data = NULL;
    pat->is_err = 0;
    pat->err_i = 0;
    pat->err_n = 100; // COMPILE_ERROR_BASE

    pat->data = myc_plre_compile(pat_str, (&(pat->err_n)), (&(pat->err_i)));

    if (pat->data == NULL) {
        pat->is_err = 1;

        pcre2_get_error_message(pat->err_n, pat->err, 1024);
    }
}

myc_RePat_p
myc_re_pat_alloc()
{
    return (myc_RePat_p)
        malloc(sizeof(myc_RePat));
}

void
myc_re_pat_del(myc_RePat_P Z)
{
    myc_RePat_p A = *Z;

    if (Z != NULL && A != NULL)
    {
        if (A->data != NULL) {
            pcre2_code_free(A->data);

            A->data = NULL;
        }

        free(A);

        *Z = NULL;
    }
}
