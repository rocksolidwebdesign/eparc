#ifndef MY_PARSER_TREE_H
#define MY_PARSER_TREE_H

#include "myc/node.h"
#include "myc/grammar_t.h"

myc_Node_p
myc_tree_expr_top(
    myc_Expr_p expr);

myc_Node_p
myc_tree_expr(
    myc_Expr_p expr);

myc_Node_p
myc_tree_expr_prime(
    myc_ExprPrime_p expr);

myc_Node_p
myc_tree_term(
    myc_Term_p term);

myc_Node_p
myc_tree_term_prime(
    myc_TermPrime_p term_prime);

myc_Node_p
myc_tree_factor(
    myc_Factor_p term);

#endif
