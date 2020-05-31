#ifndef MYC_PARSER_NODE_T_H
#define MYC_PARSER_NODE_T_H

enum MYC_NODE_TYPES_ENUM
{
    MYC_NODE_OP = 901,
    MYC_NODE_LEAF,
    MYC_NODE_ERR
};

struct myc_Node_t
{
    int type;
    double val;
    char op;
    struct myc_Node_t* left;
    struct myc_Node_t* right;
};

typedef struct myc_Node_t myc_Node;
typedef myc_Node * myc_Node_p;
typedef myc_Node ** myc_Node_P;

#endif
