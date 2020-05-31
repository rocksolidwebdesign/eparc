#ifndef MYC_STRBUF_H
#define MYC_STRBUF_H

#include "myc/strbuf_t.h"

myc_StrBuf_p myc_strbuf_create(const char * B);
myc_StrBuf_p myc_strbuf_new(void);
myc_StrBuf_p myc_strbuf_new_sz(const size_t len);
myc_StrBuf_p myc_strbuf_new_fill(const size_t sz, const char c);
myc_StrBuf_p myc_strbuf_alloc(void);
void myc_strbuf_init_sz(myc_StrBuf_p s, const size_t len);
void myc_strbuf_grow(myc_StrBuf_p p);
void myc_strbuf_grow_to(myc_StrBuf_p p, const size_t sz);
void myc_strbuf_shrink(myc_StrBuf_p a);
void myc_strbuf_del(myc_StrBuf_P p);

void myc_strbuf_zero(myc_StrBuf_p);
void myc_strbuf_zero_c(myc_StrBuf_p s, const char c);

void myc_strbuf_copy_assign(myc_StrBuf_p a, const myc_StrBuf_p b);
myc_StrBuf_p myc_strbuf_move_assign(myc_StrBuf_P a, myc_StrBuf_p b);

void myc_strbuf_cat_cstr(myc_StrBuf_p a, const char * b);
void myc_strbuf_cat(myc_StrBuf_p a, const myc_StrBuf_p b);
void myc_strbuf_cat_c(myc_StrBuf_p a, const char b_);

void
myc_strbuf_from_cstr(
    myc_StrBuf_p dest,
    const char * src);

void
myc_strbuf_from_cstr_n(
    myc_StrBuf_p dest,
    const char * src,
    const size_t src_len);

void
myc_strbuf_to_cstr(
    char * dest,
    const myc_StrBuf_p src);

void
myc_strbuf_to_cstr_n(
    char * dest,
    const size_t dest_len,
    const myc_StrBuf_p src);

int myc_strbuf_eq(const myc_StrBuf_p a, const myc_StrBuf_p b);
int myc_strbuf_compare(const myc_StrBuf_p a, const myc_StrBuf_p b);

#endif
