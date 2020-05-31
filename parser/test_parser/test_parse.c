#include "myc/eval.h"
#include "myc/grammar.h"
#include "myc/grammar_types.h"
#include "myc/grammar_print.h"
#include "myc/grammar_t.h"
#include "myc/node_print.h"
#include "myc/node_t.h"
#include "myc/prule.h"
#include "myc/parser.h"
#include "myc/par.h"
#include "myc/tokpats.h"
#include "myc/toks.h"
#include "myc/tree.h"
#include "myc/test_helper.h"

#include <stdio.h>

int Test_parse()
{
    myc_Par_p p = myc_par_new();

    TEST_ASSERT_NOT_NULL(p,
        "myc_parser_new: it should not be null");

    myc_grammar_setup(p);

    char * subj = "1 + 2 * 3 + ((5 + 8) - 9.4 * 3 / 7.77)\n";

    int rc = MYC_OK;
    myc_Expr_p expr =
        myc_grammar_parse(
            p, subj, &rc);

    printf("\n");

    if (rc != MYC_OK) {
        printf("Parse Error\n");
        return 1;
    }

    printf("\n");

    myc_print_expr_top(expr);

    printf("\n");

    myc_Node_p node =
        myc_tree_expr_top(expr);

    printf("\n");

    myc_node_print_top(node);

    printf("\n");

    double res = myc_eval_expr(node);

    printf("res: %f\n", res);

    myc_node_del(&node);
    myc_gt_expr_del(expr);
    myc_par_del(&p);

    return 0;
}

int RunTests_parse()
{
    int result = 0;

    RUN_TEST(Test_parse);

    return 0;
}

int main()
{
    return RunTests_parse();
}
