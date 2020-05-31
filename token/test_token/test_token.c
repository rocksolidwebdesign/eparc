#include "myc/test_helper.h"
#include "myc/token.h"

#include <stdio.h>

int Test_myc_create_token()
{
    myc_Token_p a = myc_tok_create(42, 0, "hello");
    myc_Token_p b = myc_tok_create('+', 0, "");

    TEST_ASSERT_STR_EQ(a->str->data, "hello",
        "myc_create_token: id token data should be hello");

    TEST_ASSERT_EQ(a->type, 42,
        "myc_create_token: id token type should be id");

    TEST_ASSERT_EQ(b->type, '+',
        "myc_create_token: op token type should be the char value");

    myc_tok_del(&a);
    myc_tok_del(&b);

    return 0;
}

int Test_myc_copy_assign_token()
{
    myc_Token_p a = myc_tok_create(33, 0, "world");
    myc_Token_p b = myc_tok_new();

    TEST_ASSERT_STR_EQ(b->str->data, "",
        "myc_copy_assign_token: new token data should be empty");

    TEST_ASSERT_EQ(b->type, 0,
        "myc_copy_assign_token: new token type should be none");

    myc_tok_copy_assign(b, a);

    TEST_ASSERT_STR_EQ(b->str->data, "world",
        "myc_copy_assign_token: assigned token data should match original");

    TEST_ASSERT_EQ(b->type, 33,
        "myc_copy_assign_token: assigned token type should match original");

    myc_tok_del(&a);
    myc_tok_del(&b);

    return 0;
}

int RunTest_token()
{
    int result = 0;

    RUN_TEST(Test_myc_create_token);
    RUN_TEST(Test_myc_copy_assign_token);

    return 0;
}

int main()
{
    return RunTest_token();
}
