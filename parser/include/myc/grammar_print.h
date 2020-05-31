#ifndef MYC_PARSER_GRAMMAR_PRINT_H
#define MYC_PARSER_GRAMMAR_PRINT_H

#include "myc/grammar_t.h"

void
myc_print_expr_top(
    myc_Expr_p expr);

void
myc_print_expr(
    myc_Expr_p expr);

void
myc_print_expr_prime(
    myc_ExprPrime_p expr);

void
myc_print_term(
    myc_Term_p term);

void
myc_print_term_prime(
    myc_TermPrime_p term);

void
myc_print_factor(
    myc_Factor_p factor);

#endif
