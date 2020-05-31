#ifndef MYC_PARSER_PARSER_H
#define MYC_PARSER_PARSER_H

#include "myc/par_t.h"
#include "myc/token_t.h"

int
myc_parser_read(
    myc_Par_p p);

void
myc_parser_set_in(
    myc_Par_p p,
    const char * in);

void
myc_parser_push_pat(
    myc_Par_p p,
    const myc_TokPat_p pat);

void
myc_parser_add_pat(
    myc_Par_p p,
    const int type,
    const int ignore,
    const char * pat_str);

void
myc_parser_step(
    myc_Par_p p);

myc_Token_p
myc_parser_cur(
    myc_Par_p p);

myc_Token_p
myc_parser_peek(
    myc_Par_p p);

#endif
