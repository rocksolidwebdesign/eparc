#include "myc/grammar_types.h"
#include "myc/grammar_t.h"
#include "myc/prule.h"
#include "myc/parser.h"
#include "myc/par_t.h"
#include "myc/token_t.h"

#include <stdlib.h>

#define INDENT_SIZE 1
static long indent = 0;

static void myc_indent() { indent += INDENT_SIZE; }
static void myc_dedent() { indent -= INDENT_SIZE; }

#ifdef MYC_DEBUG_ENABLE

static const char * indent_str = "    ";

static int myc_print_indent() {
    for (long i = 0; i < indent; i++) {
        printf("%s", indent_str);
    }

    return 1;
}

#define MYC_IPRINT(...) { myc_print_indent(); printf(__VA_ARGS__); }
#else
#define MYC_IPRINT(...)
#endif

myc_Expr_p
myc_prule_start(
    myc_Par_p p,
    int * rc0)
{
    indent = 0;

    MYC_IPRINT("myc_prule_start\n");

    int rc = MYC_OK;

    myc_Expr_p expr = myc_prule_expr(p, &rc);

    if (expr != NULL && rc == MYC_OK && myc_parser_cur(p)->type == TOK_EOF)
    {
        *rc0 = MYC_OK;
    }
    else
    {
        MYC_IPRINT("ERROR myc_prule_start expected OK and EOF\n");
        *rc0 = MYC_ERR;
    }

    return expr;
}

myc_Expr_p
myc_prule_expr(
    myc_Par_p p,
    int * rc0)
{
    myc_indent();
    MYC_IPRINT("'%s' myc_prule_expr\n", myc_parser_cur(p)->str->data);

    myc_Expr_p expr = myc_gt_expr_new();

    int rc = MYC_OK;

    expr->term = myc_prule_term(p, &rc);

    if (rc == MYC_OK)
    {
        expr->next =
            myc_prule_expr_cont(p, rc0);

        myc_dedent();

        return expr;
    }

    MYC_IPRINT("ERROR myc_prule_expr expected term\n");

    *rc0 = MYC_ERR;

    myc_gt_expr_del(expr);

    myc_dedent();

    return expr;
}

myc_ExprPrime_p
myc_prule_expr_cont(
    myc_Par_p p,
    int * rc0)
{
    myc_indent();
    MYC_IPRINT("'%s' myc_prule_expr_cont\n", myc_parser_cur(p)->str->data);

    myc_ExprPrime_p expr_prime = myc_gt_expr_prime_new();

    myc_Token_p tok = myc_parser_cur(p);

    if (tok->type == TOK_ADD || tok->type == TOK_SUB)
    {
        expr_prime->op = tok->str->data[0];

        myc_parser_step(p);

        int rc = MYC_OK;

        expr_prime->term = myc_prule_term(p, &rc);

        if (rc == MYC_OK)
        {
            expr_prime->next =
                myc_prule_expr_cont(p, rc0);

            myc_dedent();

            return expr_prime;
        }

        MYC_IPRINT("ERROR myc_prule_expr_cont expected term\n");

        *rc0 = MYC_ERR;
    }
    else if (tok->type == TOK_CLS || tok->type == TOK_EOF)
    {
        *rc0 = MYC_OK;
    }
    else
    {
        MYC_IPRINT("ERROR myc_prule_expr_cont expected ')' or EOF\n");

        *rc0 = MYC_ERR;
    }

    myc_gt_expr_prime_del(expr_prime);

    myc_dedent();

    return NULL;
}

myc_Term_p
myc_prule_term(
    myc_Par_p p,
    int * rc0)
{
    myc_indent();
    MYC_IPRINT("'%s' myc_prule_term\n", myc_parser_cur(p)->str->data);

    myc_Term_p term = myc_gt_term_new();

    int rc = MYC_OK;

    term->factor = myc_prule_factor(p, &rc);

    if (rc == MYC_OK)
    {
        *rc0 = MYC_OK;

        term->next =
            myc_prule_term_cont(p, rc0);

        myc_dedent();

        return term;
    }

    MYC_IPRINT("ERROR myc_prule_term expected factor\n");

    *rc0 = MYC_ERR;

    myc_gt_term_del(term);

    myc_dedent();

    return NULL;
}

myc_TermPrime_p
myc_prule_term_cont(
    myc_Par_p p,
    int * rc0)
{
    myc_indent();
    MYC_IPRINT("'%s' myc_prule_term_cont\n", myc_parser_cur(p)->str->data);

    myc_TermPrime_p term_prime = myc_gt_term_prime_new();

    myc_Token_p tok = myc_parser_cur(p);

    if (tok->type == TOK_MUL || tok->type == TOK_DIV)
    {
        term_prime->op = tok->str->data[0];

        myc_parser_step(p);

        int rc = MYC_OK;

        term_prime->factor = myc_prule_factor(p, &rc);

        if (rc == MYC_OK)
        {
            *rc0 = MYC_OK;

            term_prime->next = myc_prule_term_cont(p, rc0);

            myc_dedent();

            return term_prime;
        }

        MYC_IPRINT("ERROR myc_prule_term_cont expected factor\n");

        *rc0 = MYC_ERR;
    }
    else if (tok->type == TOK_CLS || tok->type == TOK_SUB || tok->type == TOK_ADD || tok->type == TOK_EOF)
    {
        *rc0 = MYC_OK;
    }
    else
    {
        MYC_IPRINT("ERROR myc_prule_term_cont unexpected '%s'\n", tok->str->data);

        *rc0 = MYC_ERR;
    }

    myc_gt_term_prime_del(term_prime);

    myc_dedent();

    return NULL;
}

myc_Factor_p
myc_prule_factor(
    myc_Par_p p,
    int * rc0)
{
    myc_indent();
    MYC_IPRINT("'%s' myc_prule_factor\n", myc_parser_cur(p)->str->data);

    myc_Factor_p factor = myc_gt_factor_new();

    myc_Token_p tok = myc_parser_cur(p);

    if (tok->type == TOK_NUM)
    {
        factor->type = MYC_NUM_FACTOR;
        factor->num = atof(tok->str->data);

        myc_parser_step(p);

        *rc0 = MYC_OK;

        myc_dedent();

        return factor;
    }
    else if (tok->type == TOK_OPN)
    {
        factor->type = MYC_EXPR_FACTOR;

        myc_parser_step(p);

        int rc = MYC_OK;

        factor->expr = myc_prule_expr(p, &rc);

        if (rc == MYC_OK && myc_parser_cur(p)->type == TOK_CLS)
        {
            myc_parser_step(p);

            *rc0 = MYC_OK;

            myc_dedent();

            return factor;
        }
    }

    MYC_IPRINT("ERROR myc_prule_factor expected number or '('\n");

    *rc0 = MYC_ERR;

    myc_gt_factor_del(factor);

    myc_dedent();

    return NULL;

}
