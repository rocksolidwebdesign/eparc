#ifndef MY_PARSER_PAR_T_H
#define MY_PARSER_PAR_T_H

#include "myc/scanr_t.h"
#include "myc/toks_t.h"

struct myc_Par_t
{
    myc_Scanr_p scanr;
    myc_Toks_p stack;
    size_t pos;
};

typedef struct myc_Par_t myc_Par;
typedef myc_Par * myc_Par_p;
typedef myc_Par ** myc_Par_P;

#endif
