#include "myc/strbuf.h"
#include "myc/strbuf_t.h"
#include "myc/strbuf_raw.h"

#include "myc/test_helper.h"

#include <stdio.h>

int Test_myc_strbuf_create()
{
    const char * x = "wildwildwest";

    const size_t n = strlen(x);

    myc_StrBuf_p y = myc_strbuf_create(x);

    TEST_ASSERT_NOT_NULL(y,
        "myc_strbuf_create: should not be null");

    TEST_ASSERT_EQ(y->len, 12,
        "myc_strbuf_create: should track the length");

    TEST_ASSERT_NEQ(y->data, x,
        "myc_strbuf_create: should not be same memory");

    TEST_ASSERT_MEM_EQ(y->data, x, n + 1,
        "myc_strbuf_create: raw data should be equal");

    myc_strbuf_del(&y);

    return 0;
}

int Test_myc_strbuf_to_from()
{
    {
        char dest[5] = "blah";

        myc_StrBuf_p src = myc_strbuf_create("world");

        myc_strbuf_to_cstr_n(
            dest, 5, src);

        TEST_ASSERT_MEM_EQ(dest, "worl", 5,
            "myc_strbuf_to_cstr_n: it should copy part of the string");

        myc_strbuf_del(&src);
    }

    {
        char dest[10] = "hello";

        myc_StrBuf_p src = myc_strbuf_create("world");

        myc_strbuf_to_cstr_n(
            dest, 10, src);

        TEST_ASSERT_MEM_EQ(dest, "world", 6,
            "myc_strbuf_to_cstr_n: it should copy the string");

        myc_strbuf_del(&src);
    }

    {
        char src[20] = "0123456789abcdef";
        const size_t n = strlen(src);

        myc_StrBuf_p dest = myc_strbuf_create("fruit");

        myc_strbuf_from_cstr_n(
            dest, src, n);

        TEST_ASSERT_MEM_EQ(dest->data, "0123456789abcdef", n + 1,
            "myc_strbuf_to_cstr_n: it should copy to the strbuf and null char");

        myc_strbuf_del(&dest);
    }

    return 0;
}

int Test_myc_strbuf_cat_c()
{
    const char * a_ = "o";

    myc_StrBuf_p a = myc_strbuf_create(a_);

    myc_strbuf_cat_c(a, 'n');
    myc_strbuf_cat_c(a, 'e');
    myc_strbuf_cat_c(a, 't');
    myc_strbuf_cat_c(a, 'w');
    myc_strbuf_cat_c(a, 'o');

    TEST_ASSERT_STR_EQ(a->data, "onetwo",
        "myc_strbuf_cat_c: should append the chars");

    myc_strbuf_del(&a);

    return 0;
}

int Test_myc_strbuf_cat()
{
    myc_StrBuf_p a = myc_strbuf_create("foo");
    myc_StrBuf_p b = myc_strbuf_create("bar");

    myc_strbuf_cat(a, b);

    TEST_ASSERT_STR_EQ(a->data, "foobar",
        "myc_strbuf_cat: should append the string");

    myc_strbuf_del(&a);
    myc_strbuf_del(&b);

    return 0;
}

int Test_myc_strbuf_shrink()
{
    myc_StrBuf_p a = myc_strbuf_create("foobarbaz");

    TEST_ASSERT_EQ(a->len, 9,
        "myc_strbuf_shrink: should have the right length");

    TEST_ASSERT_EQ(a->sz, 16,
        "myc_strbuf_shrink: should grow the size");

    myc_strbuf_shrink(a);

    TEST_ASSERT_EQ(a->sz, 9,
        "myc_strbuf_shrink: should shrink the size");

    TEST_ASSERT_MEM_EQ(a->data, "foobarbaz", 10,
        "myc_strbuf_shrink: should keep the string");

    myc_strbuf_del(&a);

    return 0;
}

int RunTests_myc_strbuf()
{
    int result = 0;

    RUN_TEST(Test_myc_strbuf_create);
    RUN_TEST(Test_myc_strbuf_to_from);
    RUN_TEST(Test_myc_strbuf_cat_c);
    RUN_TEST(Test_myc_strbuf_cat);
    RUN_TEST(Test_myc_strbuf_shrink);

    return 0;
}

int main()
{
    return RunTests_myc_strbuf();
}
