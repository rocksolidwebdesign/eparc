#include "myc/toks_raw.h"

#include "myc/token.h"
#include "myc/token_t.h"

#include <string.h>

myc_Token_p
myc_toks_raw_create(
    const size_t len)
{
    myc_Token_p t = myc_toks_raw_alloc(len);

    myc_toks_raw_init(t, len);

    return t;
}

myc_Token_p
myc_toks_raw_new(
    const size_t sz)
{
    myc_Token_p t = myc_toks_raw_alloc(sz);

    return t;
}

myc_Token_p
myc_toks_raw_alloc(
    const size_t sz)
{
    return (myc_Token_p)malloc(sizeof(myc_Token) * sz);
}

myc_Token_p
myc_toks_raw_realloc(
    myc_Token_p t, const size_t sz)
{
    return (myc_Token_p)realloc(t, sizeof(myc_Token) * sz);
}

myc_Token_p
myc_toks_raw_resize(
    myc_Token_p t,
    const size_t sz)
{
    return (t == NULL)
        ? myc_toks_raw_alloc(sz)
        : myc_toks_raw_realloc(t, sz);
}

myc_Token_p
myc_toks_raw_grow(
    myc_Token_p t,
    const size_t cur_sz)
{
    const size_t sz = cur_sz == 0
        ? 1
        : cur_sz * 2;

    return myc_toks_raw_resize(t, sz);
}

myc_Token_p
myc_toks_raw_grow_init(
    myc_Token_p t,
    const size_t cur_sz)
{
    const size_t sz = cur_sz == 0
        ? 1
        : cur_sz * 2;

    return myc_toks_raw_resize_init(t, cur_sz, sz);
}

myc_Token_p
myc_toks_raw_resize_init(
    myc_Token_p t,
    const size_t cur_sz,
    const size_t new_sz)
{
    myc_Token_p p =
        myc_toks_raw_resize(t, new_sz);

    const size_t init_qty =
        new_sz < cur_sz
            ? 0
            : new_sz - cur_sz;

    if (init_qty)
    {
        myc_Token_p init_from = p + cur_sz;

        myc_toks_raw_init(init_from, init_qty);
    }

    return p;
}

void
myc_toks_raw_init(
    myc_Token_p T,
    const size_t len)
{
    for (size_t i = 0; i < len; i++) {
        myc_tok_init(T + i);
    }
}

void
myc_toks_raw_clean(
    myc_Token_p T,
    const size_t len)
{
    for (size_t i = 0; i < len; i++) {
        myc_tok_clean(T + i);
    }
}

void
myc_toks_raw_del(
    myc_Token_P Z,
    const size_t len)
{
    myc_Token_p A = *Z;

    if (Z != NULL && A != NULL)
    {
        myc_toks_raw_clean(A, len);

        free(A);

        *Z = NULL;
    }
}
