#include "myc/eval.h"
#include "myc/node_t.h"

#include <stdio.h>

double
myc_eval_expr(
    myc_Node_p n)
{
    if (n->type == MYC_NODE_LEAF)
    {
        return n->val;
    }

    double lhs = myc_eval_expr(n->left);
    double rhs = myc_eval_expr(n->right);

    switch (n->op)
    {
        case '+': return lhs + rhs; break;
        case '-': return lhs - rhs; break;
        case '*': return lhs * rhs; break;
        case '/': return lhs / rhs; break;
        default: break;
    }

    return 0.0;
}
