#include "myc/tokpats.h"
#include "myc/tokpats_t.h"
#include "myc/tokpat.h"
#include "myc/tokpat_t.h"
#include "myc/regex.h"

myc_TokPat_p
myc_tokpats_raw_alloc(
    const size_t n)
{
    return (myc_TokPat_p)
        malloc(sizeof(myc_TokPat) * n);
}

myc_TokPat_p
myc_tokpats_raw_realloc(
    myc_TokPat_p A,
    const size_t n)
{
    return (myc_TokPat_p)
        realloc(A, (sizeof(myc_TokPat) * n));
}

void
myc_tokpats_raw_clean(
    myc_TokPat_p A,
    const size_t n)
{
    for (size_t i = 0; i < n; i++) {
        myc_tokpat_clean(A + i);
    }
}

void
myc_tokpats_raw_del(
    myc_TokPat_P Z,
    const size_t n)
{
    myc_TokPat_p A = *Z;

    if (Z != NULL && A != NULL)
    {
        myc_tokpats_raw_clean(A, n);

        free(A);

        *Z = NULL;
    }
}
