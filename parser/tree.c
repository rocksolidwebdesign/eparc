#include "myc/tree.h"
#include "myc/node.h"
#include "myc/node_print.h"
#include "myc/node_t.h"
#include "myc/grammar_t.h"

#include <stdlib.h>
#include <stdio.h>

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

myc_Node_p
myc_tree_expr_top(
    myc_Expr_p expr)
{
    indent = 0;

    return myc_tree_expr(expr);
}

myc_Node_p
myc_tree_expr(
    myc_Expr_p expr)
{
    MYC_IPRINT("myc_tree_expr\n");

    myc_indent();

    if (expr->next == NULL)
    {
        return myc_tree_term(expr->term);
    }

    if (expr->next->next == NULL)
    {
        myc_Node_p node = myc_node_new_op(
            expr->next->op,
            myc_tree_term(expr->term),
            myc_tree_term(expr->next->term)
        );

        myc_dedent();

        return node;
    }

    myc_Node_p node = myc_node_new_op(
        expr->next->op,
        myc_tree_term(expr->term),
        myc_tree_expr_prime(expr->next)
    );

    myc_dedent();

    return node;
}

myc_Node_p
myc_tree_expr_prime(
    myc_ExprPrime_p expr_prime)
{
    MYC_IPRINT("myc_tree_expr_prime\n");

    myc_indent();

    if (expr_prime->next->next == NULL)
    {
        myc_Node_p node = myc_node_new_op(
            expr_prime->op,
            myc_tree_term(expr_prime->term),
            myc_tree_term(expr_prime->next->term)
        );

        return node;
    }

    myc_Node_p node = myc_node_new_op(
        expr_prime->op,
        myc_tree_term(expr_prime->term),
        myc_tree_expr_prime(expr_prime->next)
    );

    myc_dedent();

    return node;
}

myc_Node_p
myc_tree_term(
    myc_Term_p term)
{
    MYC_IPRINT("myc_tree_term\n");

    myc_indent();

    if (term->next == NULL)
    {
        return myc_tree_factor(term->factor);
    }

    if (term->next->next == NULL)
    {
        myc_Node_p node = myc_node_new_op(
            term->next->op,
            myc_tree_factor(term->factor),
            myc_tree_factor(term->next->factor)
        );

        myc_dedent();

        return node;
    }

    myc_Node_p node = myc_node_new_op(
        term->next->op,
        myc_tree_factor(term->factor),
        myc_tree_term_prime(term->next)
    );

    myc_dedent();

    return node;
}

myc_Node_p
myc_tree_term_prime(
    myc_TermPrime_p term_prime)
{
    MYC_IPRINT("myc_tree_term_prime\n");

    myc_indent();

    if (term_prime->next->next == NULL)
    {
        myc_Node_p node = myc_node_new_op(
            term_prime->next->op,
            myc_tree_factor(term_prime->factor),
            myc_tree_factor(term_prime->next->factor)
        );

        return node;
    }

    myc_Node_p node = myc_node_new_op(
        term_prime->next->op,
        myc_tree_factor(term_prime->factor),
        myc_tree_term_prime(term_prime->next)
    );

    myc_dedent();

    return node;
}

myc_Node_p
myc_tree_factor(
    myc_Factor_p factor)
{
    MYC_IPRINT("myc_tree_factor\n");

    myc_indent();

    if (factor->expr != NULL)
    {
        myc_Node_p nexpr =
            myc_tree_expr(factor->expr);

        myc_dedent();

        return nexpr;
    }

    myc_Node_p node =
        myc_node_new_leaf(factor->num);

    myc_dedent();

    return node;
}
