#include "myc/par.h"
#include "myc/tokpats.h"
#include "myc/test_helper.h"

#include <stdio.h>

int Test_par()
{
    myc_Par_p p = myc_par_new();

    TEST_ASSERT_NOT_NULL(p,
        "myc_parser_new: it should not be null");

    TEST_ASSERT_NOT_NULL(p->scanr,
        "myc_parser_new: it should have a scanr");

    TEST_ASSERT_NOT_NULL(p->stack,
        "myc_parser_new: it should have a stack");

    myc_tokpats_put(p->scanr->pats, 42, 0, "hello");

    myc_par_del(&p);

    return 0;
}

int RunTests_par()
{
    int result = 0;

    RUN_TEST(Test_par);

    return 0;
}

int main()
{
    return RunTests_par();
}
