#include "myc/re_pat.h"
#include "myc/re_mat.h"
#include "myc/re_grp.h"
#include "myc/plre.h"
#include "myc/strbuf.h"
#include "myc/test_helper.h"

#include <pcre2.h>
#include <string.h>
#include <stdio.h>

int Test_myc_re_grp_new()
{
    const char * subj_str = "hello world";
    const char * pat_str = "world";

    myc_RePat_p pat = myc_re_pat_create(pat_str);
    myc_ReMat_p mat = myc_re_mat_new(pat->data);
    myc_ReGrp_p grp = myc_re_grp_create(mat->data, subj_str, 0);

    TEST_ASSERT_NOT_NULL(grp,
        "myc_re_grp_new: it should create the group object");

    myc_re_grp_del(&grp);
    myc_re_mat_del(&mat);
    myc_re_pat_del(&pat);

    return 0;
}

int Test_myc_re_grp_match()
{
    const char * subj_str = "hello world";
    const char * pat_str = "world";

    myc_RePat_p pat = myc_re_pat_create(pat_str);
    myc_ReMat_p mat = myc_re_mat_new(pat->data);

    mat->rc = myc_plre_match(
        pat->data,
        mat->data,
        subj_str
    );

    myc_ReGrp_p grp = myc_re_grp_create(mat->data, subj_str, 0);

    myc_StrBuf_p str = myc_re_grp_str(grp);

    TEST_ASSERT_MEM_EQ(str->data, "world", 6,
        "myc_re_grp_str: it should return the matched string");

    myc_strbuf_del(&str);
    myc_re_grp_del(&grp);
    myc_re_mat_del(&mat);
    myc_re_pat_del(&pat);

    return 0;
}

int RunTests_myc_regex_grp()
{
    int result = 0;

    RUN_TEST(Test_myc_re_grp_new);
    RUN_TEST(Test_myc_re_grp_match);

    return 0;
}

int main()
{
    return RunTests_myc_regex_grp();
}
