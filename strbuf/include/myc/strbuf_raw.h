#ifndef MYC_STRBUF_RAW_H
#define MYC_STRBUF_RAW_H

#include <stdlib.h>

char *myc_strbuf_raw_alloc(const size_t len);
char *myc_strbuf_raw_build(const char * s);
char *myc_strbuf_raw_new();
void  myc_strbuf_raw_zero(char * s, const size_t len);
void  myc_strbuf_raw_zero_c(char * p, const size_t len, const char c);
char *myc_strbuf_raw_realloc(char * p, const size_t len);
char *myc_strbuf_raw_resize(char * p, const size_t len);
char *myc_strbuf_raw_copy(char * A, const char * B);
char *myc_strbuf_raw_copy_n(char * A, const char * B, const size_t n);
char *myc_strbuf_raw_set_n(char * A, const char *B, const size_t n);
int   myc_strbuf_raw_eq(const char * A, const char * B);
int   myc_strbuf_raw_compare(const char * A, const char *B);
char *myc_strbuf_raw_move(char ** A, char ** B);
void  myc_strbuf_raw_del(char ** p);

#endif
