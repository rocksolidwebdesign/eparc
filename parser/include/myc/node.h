#ifndef MYC_PARSER_NODE_C_H
#define MYC_PARSER_NODE_C_H

#include "myc/node_t.h"

myc_Node_p
myc_node_new();

myc_Node_p
myc_node_new_leaf(
    double val);

myc_Node_p
myc_node_new_op(
    char op,
    myc_Node_p left,
    myc_Node_p right);

myc_Node_p
myc_node_alloc();

void
myc_node_init(
    myc_Node_p p);

void
myc_node_init_leaf(
    myc_Node_p p,
    double val);

void
myc_node_init_op(
    myc_Node_p p,
    char op,
    myc_Node_p left,
    myc_Node_p right);

void
myc_node_del(myc_Node_P Z);

#endif
