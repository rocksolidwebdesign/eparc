#include "myc/node.h"
#include "myc/node_t.h"

#include <stdlib.h>

myc_Node_p
myc_node_new()
{
    myc_Node_p p = myc_node_alloc();

    myc_node_init(p);

    return p;
}

myc_Node_p
myc_node_new_leaf(
    double val)
{
    myc_Node_p p = myc_node_alloc();

    myc_node_init_leaf(p, val);

    return p;
}

myc_Node_p
myc_node_new_op(
    char op,
    myc_Node_p left,
    myc_Node_p right)
{
    myc_Node_p p = myc_node_alloc();

    myc_node_init_op(p, op, left, right);

    return p;
}

myc_Node_p
myc_node_alloc()
{
    return (myc_Node_p)
        malloc(sizeof(myc_Node));
}

void
myc_node_init(
    myc_Node_p p)
{
    p->type = MYC_NODE_ERR;
    p->op = '~';
    p->val = 0.0;
    p->left = NULL;
    p->right = NULL;
}

void
myc_node_init_leaf(
    myc_Node_p p,
    double val)
{
    p->type = MYC_NODE_LEAF;
    p->op = '~';
    p->val = val;
    p->left = NULL;
    p->right = NULL;
}

void
myc_node_init_op(
    myc_Node_p p,
    char op,
    myc_Node_p left,
    myc_Node_p right)
{
    p->type = MYC_NODE_OP;
    p->op = op;
    p->val = 0.0;
    p->left = left;
    p->right = right;
}

void
myc_node_del(myc_Node_P Z)
{
    if (Z == NULL) return;

    myc_Node_p A = *Z;

    if (A != NULL)
    {
        if (A->left != NULL)
            myc_node_del(&A->left);

        if (A->right != NULL)
            myc_node_del(&A->right);

        free(A);
    }

    *Z = NULL;
}
