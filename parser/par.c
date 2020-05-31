#include "myc/par.h"
#include "myc/scanr.h"
#include "myc/toks.h"
#include "myc/tokpats.h"

#include <assert.h>

myc_Par_p
myc_par_new()
{
    myc_Par_p p = myc_par_alloc();

    myc_par_init(p);

    return p;
}

void
myc_par_init(
    myc_Par_p p)
{
    p->scanr = myc_scanr_new();
    p->stack = myc_toks_new();
    p->pos = 0;
}

myc_Par_p
myc_par_alloc()
{
    return (myc_Par_p)
        malloc(sizeof(myc_Par));
}

void
myc_par_del(
    myc_Par_P Z)
{
    myc_Par_p A = *Z;

    if (Z != NULL && A != NULL)
    {
        if (A->stack != NULL) {
            myc_toks_del(&(A->stack));
        }

        if (A->scanr != NULL) {
            myc_scanr_del(&(A->scanr));
        }

        free(A);

        *Z = NULL;
    }
}
