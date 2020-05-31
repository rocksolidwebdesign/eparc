#include "myc/tokpats.h"
#include "myc/tokpats_raw.h"
#include "myc/tokpats_t.h"
#include "myc/tokpat.h"
#include "myc/tokpat_t.h"
#include "myc/regex.h"

#include <assert.h>

myc_TokPats_p
myc_tokpats_new()
{
    myc_TokPats_p p = myc_tokpats_alloc();

    myc_tokpats_init(p, 1);

    return p;
}

void
myc_tokpats_init(
    myc_TokPats_p A,
    const size_t sz)
{
    assert(sz > 0);

    A->data = myc_tokpats_raw_alloc(sz);
    A->len = 0;
    A->sz = sz;
}

myc_TokPat_p
myc_tokpats_at(
    myc_TokPats_p A,
    const size_t i)
{
    assert(i < A->len);

    return (A->data + i);
}

void
myc_tokpats_push(
    myc_TokPats_p A,
    const myc_TokPat_p pat)
{
    myc_tokpats_put(A, pat->type, pat->ignore, pat->pat_str->data);
}

void
myc_tokpats_put(
    myc_TokPats_p A,
    const int type,
    const int ignore,
    const char * str)
{
    const size_t prev = A->len;
    const size_t len = prev + 1;

    if (A->sz < len) {
        myc_tokpats_grow(A, len);
    }

    myc_TokPat_p back = A->data + prev;

    myc_tokpat_init(back, type, ignore, str);

    A->len = len;
}

void
myc_tokpats_pop(
    myc_TokPats_p A)
{
    const size_t len = A->len - 1;

    myc_TokPat_p last = A->data + len;

    myc_tokpat_clean(last);

    A->len = len;
}

void
myc_tokpats_grow(
    myc_TokPats_p A,
    const size_t target_sz)
{
    size_t sz = A->sz;

    while (sz < target_sz) sz = sz * 2;

    A->data =
        myc_tokpats_raw_realloc(
            A->data, sz);

    A->sz = sz;
}

myc_TokPats_p
myc_tokpats_alloc()
{
    return (myc_TokPats_p)
        malloc(sizeof(myc_TokPats));
}

void
myc_tokpats_del(
    myc_TokPats_P Z)
{
    myc_TokPats_p A = *Z;

    if (Z != NULL && A != NULL)
    {
        if (A->data != NULL)
        {
            myc_tokpats_raw_clean(A->data, A->len);

            free(A->data);
        }

        free(A);

        *Z = NULL;
    }
}
