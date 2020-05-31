#include "myc/strbuf.h"
#include "myc/strbuf_t.h"
#include "myc/strbuf_raw.h"

#include "myc/test_helper.h"

#include <stdio.h>

int Test_myc_strbuf_raw_alloc()
{
    char * p = myc_strbuf_raw_alloc(0);

    TEST_ASSERT_NOT_NULL(p,
        "myc_strbuf_raw_alloc: should not return null");

    p = myc_strbuf_raw_realloc(p, 10);


    TEST_ASSERT_NOT_NULL(p,
        "myc_strbuf_raw_realloc: should not return null");

    const char expected = '\0';
    const char actual = p[0];

    TEST_ASSERT_EQ(actual, expected,
        "myc_strbuf_raw_alloc: should be the empty string");

    myc_strbuf_raw_del(&p);

    return 0;
}

int Test_myc_strbuf_raw_zero()
{
    const size_t len = 3;

    char * p = myc_strbuf_raw_alloc(len);

    myc_strbuf_raw_zero_c(p, len, 'a');

    TEST_ASSERT_STR_EQ(p, "aaa",
        "myc_strbuf_raw_zeroChar: should be 'aaa'");

    myc_strbuf_raw_zero(p, len);

    TEST_ASSERT_MEM_EQ(p, "\0\0\0", len + 1,
        "myc_strbuf_raw_zeroChar: should be 000");

    myc_strbuf_raw_del(&p);

    return 0;
}

int Test_myc_strbuf_raw_resize()
{
    const size_t len = 3;
    const size_t len0 = len + 4;

    char * p = myc_strbuf_raw_alloc(len);
    myc_strbuf_raw_zero_c(p, len, 'x');
    p = myc_strbuf_raw_resize(p, len0);

    TEST_ASSERT_NOT_NULL(p,
        "myc_strbuf_raw_resize: should be not null");

    TEST_ASSERT_STR_EQ(p, "xxx",
        "myc_strbuf_raw_resize: should be 'xxx'");

    p[3] = 'y';
    p[4] = 'z';
    p[5] = 'w';
    p[6] = 'u';

    TEST_ASSERT_STR_EQ(p, "xxxyzwu",
        "myc_strbuf_raw_resize: should be 'xxxyzwu'");

    myc_strbuf_raw_del(&p);

    return 0;
}

int Test_myc_strbuf_raw_build()
{
    const char contents[] =
        "hello world how are you nice to meet\n"
        "you my programming tells me it is a\n"
        "very nice day\n"
    ;

    char * p = myc_strbuf_raw_build(contents);

    TEST_ASSERT_NEQ(p, contents,
        "myc_strbuf_raw_build: should be different memory");

    TEST_ASSERT_STR_EQ(p, contents,
        "myc_strbuf_raw_build: contents should be equal");

    myc_strbuf_raw_del(&p);

    return 0;
}

int Test_myc_strbuf_raw_move()
{
    const char * str = "dingo bingo\n";

    char * B = myc_strbuf_raw_build(str);
    const char * oldAddr = B;

    char * A = NULL;

    myc_strbuf_raw_move(&A, &B);

    TEST_ASSERT_EQ(B, NULL,
        "myc_strbuf_raw_build: old buf should be null");

    TEST_ASSERT_NOT_NULL(A,
        "myc_strbuf_raw_build: new buf should be not null");

    TEST_ASSERT_EQ(A, oldAddr,
        "myc_strbuf_raw_build: should point to buf");

    TEST_ASSERT_STR_EQ(A, str,
        "myc_strbuf_raw_build: contents should be equal");

    myc_strbuf_raw_del(&A);

    return 0;
}

int RunTests_myc_strbuf_raw()
{
    int result = 0;

    RUN_TEST(Test_myc_strbuf_raw_alloc);
    RUN_TEST(Test_myc_strbuf_raw_zero);
    RUN_TEST(Test_myc_strbuf_raw_resize);
    RUN_TEST(Test_myc_strbuf_raw_build);
    RUN_TEST(Test_myc_strbuf_raw_move);

    return 0;
}

int main()
{
    return RunTests_myc_strbuf_raw();
}
