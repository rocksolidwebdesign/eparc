#ifndef MY_PARSER_PAR_H
#define MY_PARSER_PAR_H

#include "myc/par_t.h"

myc_Par_p
myc_par_new();

void
myc_par_init(
    myc_Par_p A);

myc_Par_p
myc_par_alloc();

void
myc_par_del(
    myc_Par_P Z);

#endif
