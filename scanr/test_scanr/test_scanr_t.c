#include "myc/scanr.h"
#include "myc/token.h"

#include "myc/test_helper.h"

#include <stdio.h>

int Test_myc_scanr_new()
{
    myc_Scanr_p s = myc_scanr_new();

    TEST_ASSERT_EQ(s->pos, 0,
        "myc_scanr_new: position should be zero");

    myc_scanr_del(&s);

    return 0;
}

int Test_myc_scanr_set_in()
{
    myc_Scanr_p s = myc_scanr_new();

    TEST_ASSERT_NOT_NULL(s,
        "myc_scanr_set_in: should create a new scanr")

    const char * msg = "hello scanner input";

    myc_scanr_set_in(s, msg);

    TEST_ASSERT_EQ(s->in, msg,
        "myc_scanr_set_in: should have address of input")

    myc_scanr_del(&s);

    return 0;
}

int RunTests_scanr()
{
    int result = 0;

    RUN_TEST(Test_myc_scanr_new);
    RUN_TEST(Test_myc_scanr_set_in);

    return 0;
}

int main()
{
    return RunTests_scanr();
}
