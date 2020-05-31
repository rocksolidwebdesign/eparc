#include "myc/strbuf.h"
#include "myc/strbuf_t.h"
#include "myc/strbuf_raw.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// lifetime {{{
myc_StrBuf_p
myc_strbuf_create(
    const char * B)
{
    myc_StrBuf_p A = myc_strbuf_new();

    myc_strbuf_from_cstr(A, B);

    return A;
}

myc_StrBuf_p
myc_strbuf_new()
{
    return myc_strbuf_new_sz(8);
}

myc_StrBuf_p
myc_strbuf_new_sz(
    const size_t sz)
{
    myc_StrBuf_p b = myc_strbuf_alloc();

    myc_strbuf_init_sz(b, sz);

    return b;
}

myc_StrBuf_p
myc_strbuf_new_fill(
    const size_t sz,
    const char c)
{
    myc_StrBuf_p b = myc_strbuf_new();

    myc_strbuf_init_sz(b, sz);

    myc_strbuf_raw_zero_c(b->data, sz, c);

    return b;
}

void
myc_strbuf_init_sz(
    myc_StrBuf_p s,
    const size_t sz)
{
    s->data = myc_strbuf_raw_alloc(sz);
    s->len = 0;
    s->sz = sz;
}

myc_StrBuf_p
myc_strbuf_alloc()
{
    return (myc_StrBuf_p)
        malloc(sizeof(myc_StrBuf));
}

void
myc_strbuf_grow(
    myc_StrBuf_p p)
{
    const size_t n = p->sz;

    const size_t sz = n == 0 ? 1 : n * 2;

    p->data = myc_strbuf_raw_resize(p->data, sz);

    p->sz = sz;
}

void
myc_strbuf_grow_to(
    myc_StrBuf_p p,
    const size_t target_sz)
{
    size_t sz = p->sz;

    while (sz < target_sz) sz = sz * 2;

    p->data = myc_strbuf_raw_resize(p->data, sz);

    p->sz = sz;
}

void
myc_strbuf_shrink(
    myc_StrBuf_p a)
{
    if (a->sz > a->len) {
        a->data = myc_strbuf_raw_realloc(a->data, a->len);
        a->sz = a->len;
    }
}

void
myc_strbuf_del(
    myc_StrBuf_P p)
{
    if (p != NULL && *p != NULL)
    {
        myc_strbuf_raw_del(&((*p)->data));

        free(*p);

        *p = NULL;
    }
}
// }}}

// zero {{{
void myc_strbuf_zero(myc_StrBuf_p s)
{
    myc_strbuf_raw_zero_c(s->data, s->sz, '\0');
}

void myc_strbuf_zero_c(myc_StrBuf_p s, const char c)
{
    myc_strbuf_raw_zero_c(s->data, s->sz, c);
}
// }}}

// assign {{{
myc_StrBuf_p myc_strbuf_move_assign(myc_StrBuf_P a, myc_StrBuf_p b)
{
    if (*a != NULL) myc_strbuf_del(a);

    *a = b;

    return *a;
}

void myc_strbuf_copy_assign(myc_StrBuf_p a, const myc_StrBuf_p b)
{
    a->data = myc_strbuf_raw_resize(a->data, b->len);

    myc_strbuf_raw_set_n(a->data, b->data, b->len);

    a->len = b->len;
    a->sz = b->len;
}
// }}}

// concat {{{
void
myc_strbuf_cat_cstr(
    myc_StrBuf_p a,
    const char * b)
{
    const size_t blen = strlen(b);

    const size_t new_len =
        a->len + blen;

    if (a->sz < new_len) {
        myc_strbuf_grow_to(a, new_len);
    }

    myc_strbuf_raw_set_n(
        (a->data + a->len),
        b,
        blen
    );

    a->len = new_len;
}

void
myc_strbuf_cat(
    myc_StrBuf_p a,
    const myc_StrBuf_p b)
{
    const size_t new_len =
        a->len + b->len;

    if (a->sz < new_len) {
        myc_strbuf_grow_to(a, new_len);
    }

    myc_strbuf_raw_set_n(
        (a->data + a->len),
        b->data,
        b->len
    );

    a->len = new_len;
}

void
myc_strbuf_cat_c(
    myc_StrBuf_p a,
    const char c)
{
    const size_t new_len =
        a->len + 1;

    if (a->sz < new_len) {
        myc_strbuf_grow_to(a, new_len);
    }

    a->data[a->len] = c;
    a->data[new_len] = '\0';

    a->len = new_len;
}
// }}}

// conversion {{{
void
myc_strbuf_from_cstr(
    myc_StrBuf_p dest,
    const char * src)
{
    const size_t n = strlen(src);

    myc_strbuf_from_cstr_n(dest, src, n);
}

void
myc_strbuf_from_cstr_n(
    myc_StrBuf_p dest,
    const char * src,
    const size_t src_len)
{
    myc_strbuf_grow_to(dest, src_len);

    for (size_t i = 0; i < src_len; i++) {
        dest->data[i] = src[i];
    }

    dest->data[src_len] = '\0';

    dest->len = src_len;
}

void
myc_strbuf_to_cstr(
    char * dest,
    const myc_StrBuf_p src)
{
    const size_t dest_sz = strlen(dest) + 1;

    myc_strbuf_to_cstr_n(
        dest, dest_sz, src);
}

void
myc_strbuf_to_cstr_n(
    char * dest,
    const size_t dest_sz,
    const myc_StrBuf_p src)
{
    const size_t dsz = dest_sz - 1;

    const size_t src_sz = (src->len) + 1;

    const size_t len =
        src_sz <= dsz
            ? src_sz
            : dsz;

    for (size_t i = 0; i < len; i++) {
        dest[i] = src->data[i];
    }

    dest[len] = '\0';
}
// }}}

// comparison {{{
int myc_strbuf_eq(const myc_StrBuf_p a, const myc_StrBuf_p b)
{
    return myc_strbuf_compare(a, b) == 0;
}

int myc_strbuf_compare(const myc_StrBuf_p a, const myc_StrBuf_p b)
{
    return myc_strbuf_raw_compare(a->data, b->data);
}
// }}}
