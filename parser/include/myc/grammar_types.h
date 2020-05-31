#ifndef MYC_PARSER_GRAMMAR_TYPES_H
#define MYC_PARSER_GRAMMAR_TYPES_H

#include "myc/grammar_t.h"

myc_Expr_p myc_gt_expr_new();
void myc_gt_expr_del( myc_Expr_p x);

myc_ExprPrime_p myc_gt_expr_prime_new();
void myc_gt_expr_prime_del(myc_ExprPrime_p x);

myc_Term_p myc_gt_term_new();
void myc_gt_term_del(myc_Term_p x);

myc_TermPrime_p myc_gt_term_prime_new();
void myc_gt_term_prime_del(myc_TermPrime_p x);

myc_Factor_p myc_gt_factor_new();
void myc_gt_factor_del(myc_Factor_p x);

#endif
