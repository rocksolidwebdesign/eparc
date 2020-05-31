#include "myc/test_helper.h"
#include "myc/toks_raw.h"

#include <stdio.h>

int Test_myc_toks_raw_new()
{
    myc_Token_p list = myc_toks_raw_new(10);

    TEST_ASSERT_NOT_NULL(list,
        "myc_toks_raw_new: should not be null");

    myc_toks_raw_del(&list, 0);

    return 0;
}

int Test_myc_toks_raw_create()
{
    myc_Token_p list = myc_toks_raw_create(10);

    TEST_ASSERT_NOT_NULL(list,
        "myc_toks_raw_create: should not be null");

    myc_toks_raw_del(&list, 10);

    return 0;
}

int RunTests_myc_toks_raw()
{
    int result = 0;

    RUN_TEST(Test_myc_toks_raw_new);
    RUN_TEST(Test_myc_toks_raw_create);

    return 0;
}

int main()
{
    return RunTests_myc_toks_raw();
}
