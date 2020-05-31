#include "myc/grammar_print.h"
#include "myc/grammar_t.h"

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

void
myc_print_expr_top(
    myc_Expr_p expr)
{
    indent = 0;

    if (expr != NULL) {
        myc_print_expr(expr);
    }
    else {
        MYC_IPRINT("NULL Expr\n");
    }
}

void
myc_print_expr(
    myc_Expr_p expr)
{
    MYC_IPRINT("Expr\n");

    myc_indent();

    if (expr->term != NULL) {
        myc_print_term(expr->term);
    }

    if (expr->next != NULL) {
        myc_print_expr_prime(expr->next);
    }

    myc_dedent();
}

void
myc_print_expr_prime(
    myc_ExprPrime_p expr_prime)
{
    if (expr_prime->op == '\0')
        return;

    MYC_IPRINT("ExprPrime %c\n", expr_prime->op);

    myc_indent();

    if (expr_prime->term != NULL) {
        myc_print_term(expr_prime->term);
    }

    if (expr_prime->next != NULL) {
        myc_print_expr_prime(expr_prime->next);
    }

    myc_dedent();
}

void
myc_print_term(
    myc_Term_p term)
{
    MYC_IPRINT("Term\n");

    myc_indent();

    if (term->factor != NULL) {
        myc_print_factor(term->factor);
    }

    if (term->next != NULL) {
        myc_print_term_prime(term->next);
    }

    myc_dedent();
}

void
myc_print_term_prime(
    myc_TermPrime_p term_prime)
{
    if (term_prime->op == '\0')
        return;

    MYC_IPRINT("TermPrime %c\n", term_prime->op);
    //MYC_IPRINT("TermPrime\n");

    myc_indent();

    if (term_prime->factor != NULL) {
        myc_print_factor(term_prime->factor);
    }

    if (term_prime->next != NULL) {
        myc_print_term_prime(term_prime->next);
    }

    myc_dedent();
}

void
myc_print_factor(
    myc_Factor_p factor)
{
    MYC_IPRINT("Factor %f\n", factor->num);

    myc_indent();

    if (factor->expr != NULL) {
        myc_print_expr(factor->expr);
    }

    myc_dedent();
}

