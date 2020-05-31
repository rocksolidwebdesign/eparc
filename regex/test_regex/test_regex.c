#include "myc/regex.h"
#include "myc/re_util.h"
#include "myc/re_grp.h"
#include "myc/re_mat.h"
#include "myc/re_pat.h"
#include "myc/strbuf.h"
#include "myc/test_helper.h"

#include <pcre2.h>
#include <string.h>
#include <stdio.h>

int Test_myc_regex_create()
{
    const char * pat = "world";

    myc_RegEx_p re = myc_regex_create(pat);

    TEST_ASSERT_NOT_NULL(re,
        "myc_regex_create: it should not be null");

    myc_regex_del(&re);

    return 0;
}

int Test_myc_regex_match()
{
    const char * subj = "monkey hello world pants";
    const char * pat = "world";

    myc_RegEx_p re = myc_regex_create(pat);

    const int is_match =
        myc_regex_match(re, subj);

    TEST_ASSERT_TRUE(is_match,
        "myc_regex_match: it should match");

    TEST_ASSERT_EQ(re->subj, subj,
        "myc_regex_match: it should track the subject");

    myc_regex_del(&re);

    return 0;
}

int Test_myc_regex_m()
{
    const char * subj = "apple hello world banana";
    const char * pat = "wo(rld)";

    myc_RegEx_p re = myc_regex_create(pat);

    myc_regex_match(re, subj);

    myc_StrBuf_p str_m = myc_regex_m(re);
    myc_StrBuf_p str_g0 = myc_regex_g(re, 0);
    myc_StrBuf_p str_g1 = myc_regex_g(re, 1);
    myc_StrBuf_p str_g2 = myc_regex_g(re, 2);

    TEST_ASSERT_NOT_NULL(str_m,
        "myc_regex_m: it should not be null");

    TEST_ASSERT_EQ(str_m->len, 5,
        "myc_regex_m: it should set the strlen");

    TEST_ASSERT_EQ(str_g2, NULL,
        "myc_regex_m: it should not return bad groups");

    TEST_ASSERT_MEM_EQ(str_m->data, "world", 6,
        "myc_regex_m: it should have the whole match");

    TEST_ASSERT_STR_EQ(str_m->data, str_g0->data,
        "myc_regex_m: the match should be the zero group");

    TEST_ASSERT_EQ(str_g1->len, 3,
        "myc_regex_m: the second group should be correct length");

    TEST_ASSERT_STR_EQ(str_g1->data, "rld",
        "myc_regex_m: the second group should match");

    myc_strbuf_del(&str_m);
    myc_strbuf_del(&str_g0);
    myc_strbuf_del(&str_g1);
    myc_regex_del(&re);

    return 0;
}

int Test_myc_regex_get_match()
{
    const char * subj = "car hello world truck";
    const char * pat = "world";

    myc_RegEx_p re = myc_regex_create(pat);

    myc_StrBuf_p str =
        myc_regex_get_match(re, subj);

    myc_regex_del(&re);

    TEST_ASSERT_NOT_NULL(str,
        "myc_regex_match: it should not be null");

    TEST_ASSERT_MEM_EQ(str->data, "world", 6,
        "myc_regex_match: it should return the match");

    myc_strbuf_del(&str);

    return 0;
}

int RunTests_myc_regex()
{
    int result = 0;

    RUN_TEST(Test_myc_regex_create);
    RUN_TEST(Test_myc_regex_m);
    RUN_TEST(Test_myc_regex_match);
    RUN_TEST(Test_myc_regex_get_match);

    return 0;
}

int main()
{
    return RunTests_myc_regex();
}
