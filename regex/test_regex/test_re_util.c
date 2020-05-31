#include "myc/re_util.h"
#include "myc/re_grp.h"
#include "myc/re_mat.h"
#include "myc/re_pat.h"
#include "myc/strbuf.h"
#include "myc/test_helper.h"

#include <pcre2.h>
#include <string.h>
#include <stdio.h>

int Test_myc_re_util_match()
{
    const char * subj_str = "hello orange world bar";
    const char * pat_str = "(hello|orange) (world|banana)";

    myc_RePat_p pat = myc_re_pat_create(pat_str);
    myc_ReMat_p mat = myc_re_mat_new(pat->data);

    TEST_ASSERT_EQ(mat->count, 3,
        "myc_re_util_match: it should have match groups");

    const int is_match =
        myc_re_util_match(pat, mat, subj_str);

    TEST_ASSERT_EQ(is_match, 1,
        "myc_re_util_match: it should match");

    TEST_ASSERT_EQ(mat->is_err, 0,
        "myc_re_util_match: it should not have errors");

    {
        myc_StrBuf_p str =
            myc_re_util_g(mat, subj_str, 0);

        TEST_ASSERT_STR_EQ(str->data, "orange world",
            "myc_re_util_match: it should return the whole match");

        myc_strbuf_del(&str);
    }

    {
        myc_StrBuf_p str =
            myc_re_util_g(mat, subj_str, 1);

        TEST_ASSERT_STR_EQ(str->data, "orange",
            "myc_re_util_match: it should return the first group");

        myc_strbuf_del(&str);
    }

    {
        myc_StrBuf_p str =
            myc_re_util_g(mat, subj_str, 2);

        TEST_ASSERT_STR_EQ(str->data, "world",
            "myc_re_util_match: it should return the second group");

        myc_strbuf_del(&str);
    }

    myc_re_mat_del(&mat);
    myc_re_pat_del(&pat);

    return 0;
}

int Test_myc_re_util_nomatch()
{
    const char * subj_str = "hello world";
    const char * pat_str = "strawberry";

    myc_RePat_p pat = myc_re_pat_create(pat_str);
    myc_ReMat_p mat = myc_re_mat_new(pat->data);

    const int is_match =
        myc_re_util_match(pat, mat, subj_str);

    TEST_ASSERT_EQ(is_match, 0,
        "myc_re_util_match: it should not be successful");

    TEST_ASSERT_EQ(mat->is_err, 1,
        "myc_re_util_match: it should have errors");

    {
        myc_StrBuf_p str =
            myc_re_util_g(mat, subj_str, 0);

        TEST_ASSERT_EQ(str, NULL,
            "myc_re_util_match: it should return null");
    }

    {
        myc_StrBuf_p str =
            myc_re_util_g(mat, subj_str, 1);

        TEST_ASSERT_EQ(str, NULL,
            "myc_re_util_match: it should return null again");
    }

    myc_re_mat_del(&mat);
    myc_re_pat_del(&pat);

    return 0;
}

int RunTests_myc_regex()
{
    int result = 0;

    RUN_TEST(Test_myc_re_util_match);
    RUN_TEST(Test_myc_re_util_nomatch);

    return 0;
}

int main()
{
    return RunTests_myc_regex();
}
