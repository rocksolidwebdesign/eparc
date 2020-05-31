#include "myc/main.h"
#include "myc/grammar.h"
#include "myc/grammar_t.h"
#include "myc/par.h"
#include "myc/tree.h"
#include "myc/eval.h"

#include <stdio.h>

int
myc_main_run(
    const char * subj)
{
    myc_Par_p p = myc_par_new();

    myc_grammar_setup(p);

    int rc = MYC_OK;
    myc_Expr_p expr =
        myc_grammar_parse(
            p, subj, &rc);

    if (rc != MYC_OK) {
        printf("Parse Error\n");
        return 1;
    }

    myc_Node_p node =
        myc_tree_expr_top(expr);

    double res = myc_eval_expr(node);

    printf("%f\n", res);

    return 0;
}

int main(int argc, char ** argv)
{
    if (argc < 2) {
        printf("ERROR: Expression arg required\n");
        return 1;
    }

    myc_StrBuf_p str = myc_strbuf_create(argv[1]);

    myc_strbuf_cat_c(str, '\n');

    int rc = myc_main_run(str->data);

    myc_strbuf_del(&str);

    return rc;
}
