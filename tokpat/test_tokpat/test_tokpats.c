#include "myc/tokpats.h"
#include "myc/tokpats_t.h"
#include "myc/tokpat.h"
#include "myc/tokpat_t.h"
#include "myc/regex.h"
#include "myc/test_helper.h"

#include <stdio.h>
#include <stdlib.h>

int Test_myc_tokpats_new()
{
    myc_TokPats_p p = myc_tokpats_new();

    TEST_ASSERT_NOT_NULL(p,
        "myc_tokpats_new: it should be not null");

    myc_tokpats_del(&p);

    return 0;
}

int Test_myc_tokpats_grow()
{
    myc_TokPats_p p = myc_tokpats_new();

    TEST_ASSERT_NOT_NULL(p,
        "myc_tokpats_grow: it should be not null");

    myc_tokpats_grow(p, 10);

    myc_tokpats_del(&p);

    return 0;
}

int Test_myc_tokpats_push()
{
    myc_TokPats_p p = myc_tokpats_new();

    TEST_ASSERT_NOT_NULL(p,
        "myc_tokpats_push: it should be not null");

    myc_TokPat_p x0 = myc_tokpat_create(42, 0, "i am a tok pat");
    myc_TokPat_p x1 = myc_tokpat_create(43, 0, "pat am a tok");

    TEST_ASSERT_EQ(p->len, 0,
        "myc_tokpats_push: it should have no length");

    myc_tokpats_push(p, x0);

    TEST_ASSERT_EQ(p->len, 1,
        "myc_tokpats_push: it should increment length");

    myc_tokpats_push(p, x1);

    TEST_ASSERT_EQ(p->len, 2,
        "myc_tokpats_push: it should increment length again");

    myc_tokpats_pop(p);

    TEST_ASSERT_EQ(p->len, 1,
        "myc_tokpats_push: it should decrement length");

    myc_tokpat_del(&x0);
    myc_tokpat_del(&x1);
    myc_tokpats_del(&p);

    return 0;
}

int RunTests_myc_tokpats()
{
    int result = 0;

    RUN_TEST(Test_myc_tokpats_new);
    RUN_TEST(Test_myc_tokpats_grow);
    RUN_TEST(Test_myc_tokpats_push);

    return 0;
}

int main()
{
    return RunTests_myc_tokpats();
}
