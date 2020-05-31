#include "myc/tokpat.h"
#include "myc/tokpat_t.h"
#include "myc/regex.h"

#include <assert.h>

myc_TokPat_p
myc_tokpat_create(
    const int type,
    const int ignore,
    const char * pat_str)
{
    myc_TokPat_p p = myc_tokpat_alloc();

    myc_tokpat_init(p, type, ignore, pat_str);

    return p;
}

void
myc_tokpat_init(
    myc_TokPat_p p,
    const int type,
    const int ignore,
    const char * str)
{
    p->type = type;
    p->ignore = ignore;
    p->pat_str = myc_strbuf_create(str);
    p->re = myc_regex_create(str);
}

void
myc_tokpat_copy(
    myc_TokPat_p A,
    const myc_TokPat_p B)
{
    myc_tokpat_clean(A);

    myc_tokpat_init(A, B->type, B->ignore, B->pat_str->data);
}

void
myc_tokpat_clean(
    myc_TokPat_p A)
{
    assert(A != NULL);

    if (A->pat_str != NULL) {
        myc_strbuf_del(&(A->pat_str));
    }

    if (A->re != NULL) {
        myc_regex_del(&(A->re));
    }
}

myc_TokPat_p
myc_tokpat_alloc()
{
    return (myc_TokPat_p)
        malloc(sizeof(myc_TokPat));
}

void
myc_tokpat_del(
    myc_TokPat_P Z)
{
    myc_TokPat_p A = *Z;

    if (Z != NULL && A != NULL)
    {
        myc_tokpat_clean(A);

        free(A);

        *Z = NULL;
    }
}
