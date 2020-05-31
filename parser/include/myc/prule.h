#ifndef MYC_PARSER_PRULE_H
#define MYC_PARSER_PRULE_H

#include "myc/grammar_t.h"
#include "myc/par_t.h"

myc_Expr_p
myc_prule_start(
    myc_Par_p p,
    int * rc);

myc_Expr_p
myc_prule_expr(
    myc_Par_p p,
    int * rc);

myc_ExprPrime_p
myc_prule_expr_cont(
    myc_Par_p p,
    int * rc);

myc_Term_p
myc_prule_term(
    myc_Par_p p,
    int * rc);

myc_TermPrime_p
myc_prule_term_cont(
    myc_Par_p p,
    int * rc);

myc_Factor_p
myc_prule_factor(
    myc_Par_p p,
    int * rc);

#endif
