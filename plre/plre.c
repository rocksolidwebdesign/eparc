#include "myc/plre.h"

#include <string.h>
#include <pcre2.h>

#include <stdio.h>
#include <assert.h>

void
myc_plre_print_err(
    const char * pattern,
    const int err_n,
    const PCRE2_SIZE err_i)
{
    PCRE2_UCHAR err[1024];
    pcre2_get_error_message(err_n, err, 1024);

    // https://www.pcre.org/current/doc/html/pcre2api.html#SEC31
    fprintf(stderr, "PCRE2 Compile Error: %s\n", err);
    fprintf(stderr, "  '%s' char %lu\n", pattern, err_i);
}

pcre2_code *
myc_plre_create(
    const char * pattern)
{
    int err_n = 0;
    PCRE2_SIZE err_i = 0;

    pcre2_code * re = myc_plre_compile(
        pattern,  /* the pattern */
        &err_n,   /* for error number */
        &err_i    /* for error offset */
    );

    return re;
}

pcre2_code *
myc_plre_compile(
    const char * pattern,
    int * err_n,
    PCRE2_SIZE * err_i)
{
    *err_n = 0;
    *err_i = 0;

    pcre2_code * re = pcre2_compile(
        (PCRE2_SPTR) pattern,  /* the pattern */
        PCRE2_ZERO_TERMINATED, /* indicates pattern is zero-terminated */
        PCRE2_UTF,             /* assume UTF-8 */
        err_n,                 /* for error number */
        err_i,                 /* for error offset */
        NULL                   /* use default compile context */
    );

    return re;
}

int
myc_plre_match(
    pcre2_code * re,
    pcre2_match_data * m,
    const char * subj)
{
    uint32_t options =
        PCRE2_NOTEMPTY |
        PCRE2_NO_UTF_CHECK;

    const int rc = pcre2_match(
        re,                    /* the compiled pattern */
        (PCRE2_SPTR) subj,     /* the subject string */
        PCRE2_ZERO_TERMINATED, /* the length of the subject */
        0,                     /* start at offset 0 in the subject */
        options,               /* default options */
        m,                     /* block for storing the result */
        NULL                   /* use default match context */
    );

    return rc;
}

size_t
myc_plre_m_count(
    pcre2_match_data * m)
{
    return pcre2_get_ovector_count(m);
}

const char * myc_plre_g_start(PCRE2_SIZE * V, const size_t k, const char * subj) {
    return subj + myc_plre_g_k1(V, k);
}

size_t myc_plre_g_len(PCRE2_SIZE * V, const size_t k) {
    PCRE2_SIZE S = myc_plre_g_k1(V, k); // start
    PCRE2_SIZE E = myc_plre_g_k2(V, k); // end

    return E > S ? E - S : 0;
}

size_t myc_plre_g_k1(PCRE2_SIZE * V, const size_t k) {
    return V[k*2];
}

size_t myc_plre_g_k2(PCRE2_SIZE * V, const size_t k) {
    return V[((k*2)+1)];
}

size_t
myc_plre_get_group(
    PCRE2_SIZE * V,
    const size_t k,
    const char * subj,
    char * dest,
    const size_t dest_sz)
{
    const char * s = myc_plre_g_start(V, k, subj);
    const size_t len = myc_plre_g_len(V, k);

    for (size_t i = 0; i < dest_sz; i++) {
        dest[i] = s[i];
    }

    // in our example where dest sz is 6
    // the last index is 5, which is len
    // so we're good
    dest[dest_sz] = '\0';

    return len;
}
