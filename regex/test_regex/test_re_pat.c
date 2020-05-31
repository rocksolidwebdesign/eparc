#include "myc/re_pat.h"
#include "myc/strbuf.h"
#include "myc/test_helper.h"

#include <pcre2.h>
#include <string.h>
#include <stdio.h>

int Test_myc_re_pat_new()
{
    myc_RePat_p pat = myc_re_pat_create("world");

    TEST_ASSERT_NOT_NULL(pat,
        "myc_regex_match: it should create the regex");

    TEST_ASSERT_EQ(pat->is_err, 0,
        "myc_regex_match: it should compile");

    myc_re_pat_del(&pat);

    return 0;
}

int RunTests_myc_regex_pat()
{
    int result = 0;

    RUN_TEST(Test_myc_re_pat_new);

    return 0;
}

int main()
{
    return RunTests_myc_regex_pat();
}
