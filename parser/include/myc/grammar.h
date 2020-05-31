#ifndef MYC_PARSER_GRAMMAR_H
#define MYC_PARSER_GRAMMAR_H

#include "myc/grammar_t.h"
#include "myc/par_t.h"

void
myc_grammar_setup(
    myc_Par_p p);

myc_Expr_p
myc_grammar_parse(
    myc_Par_p p,
    const char * subj,
    int * rc0);

#endif
