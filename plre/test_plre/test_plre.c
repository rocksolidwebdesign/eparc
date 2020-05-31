#include "myc/plre.h"
#include "myc/test_helper.h"

#include <pcre2.h>
#include <string.h>
#include <stdio.h>

int Test_regex_version() // {{{
{
    TEST_ASSERT_EQ(PCRE2_MAJOR, 10,
        "PCRE2: Major version should be 10")

    TEST_ASSERT_GTE(PCRE2_MINOR, 33,
        "PCRE2: Minor version should be >= 33")

    return 0;
} // }}}

int Test_myc_plre_create() // {{{
{
    pcre2_code * pat = myc_plre_create("hello world");

    TEST_ASSERT_NOT_NULL(pat,
        "myc_plre_create: it should compile successfully");

    pcre2_match_data * m =
        pcre2_match_data_create_from_pattern(pat, NULL);

    TEST_ASSERT_NOT_NULL(m,
        "myc_plre_create: match data should be not null");

    PCRE2_SIZE * V =
        pcre2_get_ovector_pointer(m);

    TEST_ASSERT_NOT_NULL(V,
        "myc_plre_create: ovector should be not null");

    pcre2_match_data_free(m);
    pcre2_code_free(pat);

    return 0;
} // }}}

int Test_myc_plre_match() // {{{
{
    const char * subj = "hello world, beautiful world";

    pcre2_code * pat = myc_plre_create("world");

    pcre2_match_data * m =
        pcre2_match_data_create_from_pattern(pat, NULL);

    const int rc = myc_plre_match(pat, m, subj);

    TEST_ASSERT_EQ(rc, 1,
        "myc_plre_match: it should match");

    PCRE2_SIZE count =
        pcre2_get_ovector_count(m);

    TEST_ASSERT_EQ(count, 1,
        "myc_plre_match: it should match");

    PCRE2_SIZE * V =
        pcre2_get_ovector_pointer(m);

    const size_t start_at = myc_plre_g_k1(V, 0);
    TEST_ASSERT_EQ(start_at, 6,
        "myc_plre_match: it should have a start offset");

    const size_t end_at = myc_plre_g_k2(V, 0);
    TEST_ASSERT_EQ(end_at, 11,
        "myc_plre_match: it should have an end offset");

    const size_t len = myc_plre_g_len(V, 0);
    TEST_ASSERT_EQ(len, (end_at - start_at),
        "myc_plre_match: it should have the right length");

    pcre2_match_data_free(m);
    pcre2_code_free(pat);

    return 0;
} // }}}

int main()
{
    int result = 0;

    RUN_TEST(Test_regex_version);
    RUN_TEST(Test_myc_plre_create);
    RUN_TEST(Test_myc_plre_match);

    return 0;
}
