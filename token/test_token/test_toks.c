#include "myc/test_helper.h"
#include "myc/toks.h"
#include "myc/token.h"

#include <stdio.h>

int Test_myc_toks_new()
{
    myc_Toks_p list = myc_toks_new();

    TEST_ASSERT_NOT_NULL(list,
        "myc_toks_raw_new: new list should not be null");

    TEST_ASSERT_EQ(list->sz, 1,
        "myc_toks_raw_new: new list should have no capacity");

    TEST_ASSERT_EQ(list->len, 0,
        "myc_toks_raw_new: new list should have no items");

    myc_toks_del(&list);

    return 0;
}

int Test_myc_toks_create()
{
    myc_Toks_p list = myc_toks_create(10);

    TEST_ASSERT_NOT_NULL(list,
        "myc_toks_raw_new: new list should not be null");

    TEST_ASSERT_EQ(list->sz, 10,
        "myc_toks_raw_new: new list should have capacity");

    TEST_ASSERT_EQ(list->len, 10,
        "myc_toks_raw_new: new list should have items");

    myc_toks_del(&list);

    return 0;
}

int Test_myc_toks_push()
{
    myc_Toks_p list = myc_toks_new();

    TEST_ASSERT_NOT_NULL(list,
        "myc_toks_push: new list should not be null");

    {
        myc_Token_p tok = myc_tok_new();

        myc_tok_set_val(tok, 25, 0, "helloWorld");
        myc_toks_push(list, tok);

        myc_tok_set_val(tok, 26, 0, "bingBaz");
        myc_toks_push(list, tok);

        myc_tok_set_val(tok, 27, 0, "123");
        myc_toks_push(list, tok);

        TEST_ASSERT_EQ(list->len, 3,
            "myc_toks_push: length should update")

        TEST_ASSERT_GTE(list->sz, 3,
            "myc_toks_push: capacity should update")

        myc_tok_del(&tok);
    }

    {
        myc_Token_p tok = myc_toks_at(list, 0);

        TEST_ASSERT_STR_EQ(tok->str->data, "helloWorld",
            "myc_toks_push: first token data should be correct")

        TEST_ASSERT_EQ(tok->type, 25,
            "myc_toks_push: first token type should be correct")
    }

    {
        myc_Token_p tok = myc_toks_at(list, 1);

        TEST_ASSERT_STR_EQ(tok->str->data, "bingBaz",
            "myc_toks_push: second token data should be correct")

        TEST_ASSERT_EQ(tok->type, 26,
            "myc_toks_push: second token type should be correct")
    }

    {
        myc_Token_p tok = myc_toks_at(list, 2);

        TEST_ASSERT_STR_EQ(tok->str->data, "123",
            "myc_toks_push: third token data should be correct")

        TEST_ASSERT_EQ(tok->type, 27,
            "myc_toks_push: third token type should be correct")
    }

    myc_toks_del(&list);

    return 0;
}

int Test_myc_toks_put()
{
    myc_Toks_p list = myc_toks_new();

    TEST_ASSERT_NOT_NULL(list,
        "myc_toks_put: new list should not be null");

    myc_toks_put(list, 45, 0, "chooChoo");
    myc_toks_put(list, 48, 0, "imaTrain");
    myc_toks_put(list, 49, 0, "456");

    TEST_ASSERT_EQ(list->len, 3,
        "myc_toks_put: length should update")

    TEST_ASSERT_GTE(list->sz, 4,
        "myc_toks_put: capacity should grow")

    {
        myc_Token_p tok = myc_toks_at(list, 0);

        TEST_ASSERT_STR_EQ(tok->str->data, "chooChoo",
            "myc_toks_put: first token data should be correct")

        TEST_ASSERT_EQ(tok->type, 45,
            "myc_toks_put: first token type should be correct")
    }

    {
        myc_Token_p tok = myc_toks_at(list, 1);

        TEST_ASSERT_STR_EQ(tok->str->data, "imaTrain",
            "myc_toks_put: second token data should be correct")

        TEST_ASSERT_EQ(tok->type, 48,
            "myc_toks_put: second token type should be correct")
    }

    {
        myc_Token_p tok = myc_toks_at(list, 2);

        TEST_ASSERT_STR_EQ(tok->str->data, "456",
            "myc_toks_put: third token data should be correct")

        TEST_ASSERT_EQ(tok->type, 49,
            "myc_toks_put: third token type should be correct")
    }

    myc_toks_del(&list);

    return 0;
}

int RunTests_myc_toks()
{
    int result = 0;

    RUN_TEST(Test_myc_toks_new);
    RUN_TEST(Test_myc_toks_create);
    RUN_TEST(Test_myc_toks_push);
    RUN_TEST(Test_myc_toks_put);

    return 0;
}

int main()
{
    return RunTests_myc_toks();
}
