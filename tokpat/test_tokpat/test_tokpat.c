#include "myc/tokpat.h"
#include "myc/tokpat_t.h"
#include "myc/regex.h"
#include "myc/test_helper.h"

#include <stdio.h>
#include <stdlib.h>

int Test_myc_tokpat_new()
{
    myc_TokPat_p p = myc_tokpat_create(
        123,
        0,
        "tok hello pat"
    );

    TEST_ASSERT_NOT_NULL(p,
        "myc_tokpat_new: it should be not null");

    myc_tokpat_del(&p);

    return 0;
}

int Test_myc_tokpat_obj()
{
    myc_TokPat obj;
    obj.type = 0;
    obj.pat_str = myc_strbuf_create("hello");
    obj.re = myc_regex_create("hello");

    TEST_ASSERT_NOT_NULL(obj.re,
        "myc_tokpat_obj: it should be not null");

    myc_tokpat_clean(&obj);

    return 0;
}

int RunTests_myc_tokpat()
{
    int result = 0;

    RUN_TEST(Test_myc_tokpat_obj);
    RUN_TEST(Test_myc_tokpat_new);

    return 0;
}

int main()
{
    return RunTests_myc_tokpat();
}
