#include "myc/grammar_types.h"
#include "myc/grammar_t.h"

#include <stdio.h>

myc_Expr_p myc_gt_expr_new() {
    myc_Expr_p x = (myc_Expr_p)malloc(sizeof(myc_Expr));
    x->term = NULL;
    x->next = NULL;
    return x;
}

void myc_gt_expr_del(myc_Expr_p x) {
    if (x == NULL) return;
    if (x->term != NULL) myc_gt_term_del(x->term);
    if (x->next != NULL) myc_gt_expr_prime_del(x->next);
    free(x);
}

myc_ExprPrime_p myc_gt_expr_prime_new() {
    myc_ExprPrime_p x = (myc_ExprPrime_p)malloc(sizeof(myc_ExprPrime));
    x->op = '\0';
    x->term = NULL;
    x->next = NULL;
    return x;
}

void myc_gt_expr_prime_del(myc_ExprPrime_p x) {
    if (x == NULL) return;
    if (x->term != NULL) myc_gt_term_del(x->term);
    if (x->next != NULL) myc_gt_expr_prime_del(x->next);
    free(x);
}

myc_Term_p myc_gt_term_new() {
    myc_Term_p x = (myc_Term_p)malloc(sizeof(myc_Term));
    x->factor = NULL;
    x->next = NULL;
    return x;
}

void myc_gt_term_del(myc_Term_p x) {
    if (x == NULL) return;
    if (x->factor != NULL) myc_gt_factor_del(x->factor);
    if (x->next != NULL) myc_gt_term_prime_del(x->next);
    free(x);
}

myc_TermPrime_p myc_gt_term_prime_new() {
    myc_TermPrime_p x = (myc_TermPrime_p)malloc(sizeof(myc_TermPrime));
    x->op = '\0';
    x->factor = NULL;
    x->next = NULL;
    return x;
}

void myc_gt_term_prime_del(myc_TermPrime_p x) {
    if (x == NULL) return;
    if (x->factor != NULL) myc_gt_factor_del(x->factor);
    if (x->next != NULL) myc_gt_term_prime_del(x->next);
    free(x);
}

myc_Factor_p myc_gt_factor_new() {
    myc_Factor_p x = (myc_Factor_p)malloc(sizeof(myc_Factor));
    x->type = MYC_NUM_FACTOR;
    x->num = 0;
    x->expr = NULL;
    return x;
}

void myc_gt_factor_del(myc_Factor_p x) {
    if (x == NULL) return;
    if (x->expr != NULL) myc_gt_expr_del(x->expr);
    free(x);
}
