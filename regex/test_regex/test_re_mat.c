#include "myc/re_pat.h"
#include "myc/re_mat.h"
#include "myc/strbuf.h"
#include "myc/test_helper.h"

#include <pcre2.h>
#include <string.h>
#include <stdio.h>

int Test_myc_re_mat_new()
{
    const char * pat_str = "world";

    myc_RePat_p pat = myc_re_pat_create(pat_str);
    myc_ReMat_p mat = myc_re_mat_new(pat->data);

    TEST_ASSERT_NOT_NULL(mat,
        "myc_re_mat_new: it should create the match object");

    TEST_ASSERT_NOT_NULL(mat->data,
        "myc_re_mat_new: it should create the match data");

    TEST_ASSERT_EQ(mat->count, 1,
        "myc_re_mat_new: it should have one group");

    TEST_ASSERT_EQ(mat->is_err, 1,
        "myc_re_mat_new: it should initially be in error state");

    myc_re_mat_del(&mat);
    myc_re_pat_del(&pat);

    return 0;
}

int Test_myc_re_mat_new_count()
{
    const char * pat_str = "(hello|orange) (world|banana)";
    myc_RePat_p pat = myc_re_pat_create(pat_str);
    myc_ReMat_p mat = myc_re_mat_new(pat->data);

    TEST_ASSERT_EQ(mat->count, 3,
        "myc_re_mat_new: it should have multiple groups");

    myc_re_mat_del(&mat);
    myc_re_pat_del(&pat);

    return 0;
}

//int Test_myc_re_mat_create()
//{
//    const char * subj_str = "hello world";
//    const char * pat_str = "world";
//
//    myc_RePat_p pat = myc_re_pat_create(pat_str);
//    myc_ReMat_p mat = myc_re_mat_create(pat->data, subj_str);
//
//    TEST_ASSERT_NOT_NULL(mat,
//        "myc_re_mat_new: it should create the match object");
//
//    TEST_ASSERT_NOT_NULL(mat->data,
//        "myc_re_mat_new: it should create the match data");
//
//    TEST_ASSERT_EQ(mat->count, 1,
//        "myc_re_mat_new: it should one group");
//
//    TEST_ASSERT_EQ(mat->is_err, 1,
//        "myc_re_mat_new: it should initially be in error state");
//
//    myc_re_mat_del(&mat);
//    myc_re_pat_del(&pat);
//
//    return 0;
//}
//
//int Test_myc_re_mat_create_count()
//{
//    const char * subj_str = "hello world";
//    const char * pat_str = "(hello|orange) (world|banana)";
//    myc_RePat_p pat = myc_re_pat_create(pat_str);
//    myc_ReMat_p mat = myc_re_mat_create(pat->data, subj_str);
//
//    TEST_ASSERT_EQ(mat->count, 3,
//        "myc_re_mat_new: it should have multiple groups");
//
//    myc_re_mat_del(&mat);
//    myc_re_pat_del(&pat);
//
//    return 0;
//}

int RunTests_myc_regex_mat()
{
    int result = 0;

    RUN_TEST(Test_myc_re_mat_new);
    RUN_TEST(Test_myc_re_mat_new_count);
    //RUN_TEST(Test_myc_re_mat_create);
    //RUN_TEST(Test_myc_re_mat_create_count);

    return 0;
}

int main()
{
    return RunTests_myc_regex_mat();
}
