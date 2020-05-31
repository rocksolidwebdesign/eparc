#include "myc/scanr.h"
#include "myc/regex.h"
#include "myc/token.h"
#include "myc/tokpat.h"
#include "myc/tokpats.h"

#include "myc/test_helper.h"

#include <stdio.h>

enum TOKEN_TYPES_ENUM
{
    TOK_S = 65,
    TOK_A,
    TOK_B,
};

int Test_myc_scanr_read()
{
    myc_Scanr_p s = myc_scanr_new();
    myc_tokpats_put(s->pats, TOK_S, 0, "^[\\s\\v]+");
    myc_tokpats_put(s->pats, TOK_A, 0, "^a");
    myc_tokpats_put(s->pats, TOK_B, 0, "^b");

    TEST_ASSERT_EQ(s->pos, 0,
        "myc_scanr_new: position should be zero");

    char * subj = "a b\n";

    myc_scanr_set_in(s, subj);

    int rc = 0;

    while ((rc = myc_scanr_read(s)) == MYC_RC_TOK)
    {
        if (rc == MYC_RC_ERR) {
            printf("ERROR\n");
            break;
        }

        myc_Token_p tok =
            myc_scanr_get_tok(s);

        printf("Token: %d '%s'\n",
            tok->type,
            tok->str->data
        );

        myc_tok_del(&tok);
    }

    if (rc == MYC_RC_EOS) {
        printf("EOS\n");
    }

    myc_scanr_del(&s);

    return 0;
}

int RunTests_scanr_read()
{
    int result = 0;

    RUN_TEST(Test_myc_scanr_read);

    return 0;
}

int main()
{
    return RunTests_scanr_read();
}
