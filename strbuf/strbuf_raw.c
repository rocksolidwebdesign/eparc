#include "myc/strbuf_raw.h"

#include <stdlib.h>
#include <string.h>

char * myc_strbuf_raw_build(const char * s)
{
    const size_t len = strlen(s);

    char * p = myc_strbuf_raw_alloc(len);

    myc_strbuf_raw_set_n(p, s, len);

    return p;
}

char * myc_strbuf_raw_new()
{
    return myc_strbuf_raw_alloc(0);
}

void myc_strbuf_raw_zero(char * p, const size_t len)
{
    myc_strbuf_raw_zero_c(p, len, '\0');
}

void myc_strbuf_raw_zero_c(char * p, const size_t len, const char c)
{
    memset(p, c, len);

    p[len] = '\0';
}

char * myc_strbuf_raw_alloc(const size_t len)
{
    char * p = (char *)malloc(sizeof(char) * (len + 1));

    p[0] = '\0';
    p[len] = '\0';

    return p;
}

char * myc_strbuf_raw_realloc(char * p0, const size_t len)
{
    char * p = (char *)realloc(p0, sizeof(char) * (len + 1));

    p[len] = '\0';

    return p;
}

char * myc_strbuf_raw_resize(char * p, const size_t len)
{
    if (p == NULL)
        return myc_strbuf_raw_alloc(len);
    else
        return myc_strbuf_raw_realloc(p, len);
}

char * myc_strbuf_raw_copy(char * A, const char * B)
{
    const size_t n = strlen(B);

    return myc_strbuf_raw_copy_n(A, B, n);
}

char * myc_strbuf_raw_copy_n(char * A, const char * B, const size_t n)
{
    char * a = myc_strbuf_raw_resize(A, n);

    return myc_strbuf_raw_set_n(a, B, n);
}

char * myc_strbuf_raw_set_n(
    char * A,
    const char * B,
    const size_t n)
{
    for (size_t i = 0; i < n; i++) {
        A[i] = B[i];
    }

    A[n] = '\0';

    return A;
}

char * myc_strbuf_raw_move(char ** A, char ** B)
{
    if (*A != NULL) myc_strbuf_raw_del(A);

    *A = *B;
    *B = NULL;

    return * A;
}

int myc_strbuf_raw_eq(const char * A, const char * B)
{
    return myc_strbuf_raw_compare(A, B) == 0;
}

int myc_strbuf_raw_compare(const char * A, const char * B)
{
    return strcmp(A, B);
}

void myc_strbuf_raw_del(char ** p)
{
    if (p != NULL && * p != NULL)
    {
        free(*p);

        *p = NULL;
    }
}
