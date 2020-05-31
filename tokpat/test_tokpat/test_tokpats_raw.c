#include "myc/tokpats_raw.h"
#include "myc/test_helper.h"

#include <stdio.h>
#include <stdlib.h>

int Test_myc_tokpats_raw_new()
{
    myc_TokPat_p x = myc_tokpats_raw_alloc(5);

    TEST_ASSERT_NOT_NULL(x,
        "myc_tokpats_raw_alloc: it should not be null");

    x = myc_tokpats_raw_realloc(x, 10);

    TEST_ASSERT_NOT_NULL(x,
        "myc_tokpats_raw_realloc: it should resize larger");

    x = myc_tokpats_raw_realloc(x, 3);

    TEST_ASSERT_NOT_NULL(x,
        "myc_tokpats_raw_realloc: it should resize smaller");

    myc_tokpats_raw_del(&x, 0);

    return 0;
}

int RunTests_myc_tokpats_raw()
{
    int result = 0;

    RUN_TEST(Test_myc_tokpats_raw_new);

    return 0;
}

int main()
{
    return RunTests_myc_tokpats_raw();
}
