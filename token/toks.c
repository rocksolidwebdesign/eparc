#include "myc/toks.h"
#include "myc/toks_t.h"
#include "myc/toks_raw.h"

#include "myc/token.h"
#include "myc/token_t.h"
#include "myc/strbuf.h"

#include <string.h>

myc_Toks_p
myc_toks_create(
    const size_t len)
{
    myc_Toks_p A = myc_toks_alloc();

    A->data = myc_toks_raw_alloc(len);
    A->sz = len;
    A->len = len;

    myc_toks_init(A);

    return A;
}

myc_Toks_p
myc_toks_new()
{
    myc_Toks_p A = myc_toks_alloc();

    A->data = myc_toks_raw_alloc(1);
    A->sz = 1;
    A->len = 0;

    return A;
}

myc_Toks_p
myc_toks_alloc()
{
    return (myc_Toks_p)malloc(sizeof(myc_Toks));
}

myc_Toks_p
myc_toks_resize(
    myc_Toks_p A, const size_t sz)
{
    A->data = myc_toks_raw_resize(A->data, sz);

    A->sz = sz;

    return A;
}

myc_Token_p
myc_toks_at(
    myc_Toks_p A, const size_t index)
{
    return A->data + index;
}

void
myc_toks_pop(
    myc_Toks_p A)
{
    const size_t len = A->len - 1;

    myc_Token_p last = A->data + len;

    myc_tok_clean(last);

    A->len = len;
}

myc_Toks_p
myc_toks_push(
    myc_Toks_p A_arg,
    const myc_Token_p tok)
{
    myc_Toks_p A = A_arg;

    if ((A->len + 1) >= (A->sz)) {
        A = myc_toks_grow(A);
    }

    myc_Token_p dest = myc_toks_at(A, A->len);

    myc_tok_init(dest);

    myc_tok_copy_assign(dest, tok);

    A->len += 1;

    return A;
}

myc_Toks_p
myc_toks_put(
    myc_Toks_p A_arg,
    const int tok_type,
    const int tok_ignore,
    const char * tok_str)
{
    myc_Toks_p A = A_arg;

    if ((A->len + 1) >= (A->sz)) {
        A = myc_toks_grow(A);
    }

    myc_Token_p dest = myc_toks_at(A, A->len);

    myc_tok_init_val(dest, tok_type, tok_ignore, tok_str);

    A->len += 1;

    return A;
}

myc_Toks_p
myc_toks_grow(
    myc_Toks_p A)
{
    const size_t sz =
        A->len == 0
            ? 1
            : A->len * 2;

    return myc_toks_resize(A, sz);
}

void
myc_toks_init(
    myc_Toks_p A)
{
    myc_toks_raw_init(A->data, A->len);
}

void
myc_toks_del(
    myc_Toks_p * Z)
{
    myc_Toks_p A = *Z;

    if ((Z != NULL) && (A != NULL))
    {
        if (A->data != NULL) {
            myc_toks_raw_del(&(A->data), A->len);
        }

        free(A);

        *Z = NULL;
    }
}
