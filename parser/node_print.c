#include "myc/node_print.h"
#include "myc/node_t.h"

#include <stdio.h>
#include <stdlib.h>

#define INDENT_SIZE 1
static long indent = 0;

static void myc_indent() { indent += INDENT_SIZE; }
static void myc_dedent() { indent -= INDENT_SIZE; }

#ifdef MYC_DEBUG_ENABLE

static const char * indent_str = "    ";

static int myc_print_indent() {
    for (long i = 0; i < indent; i++) {
        printf("%s", indent_str);
    }

    return 1;
}

#define MYC_IPRINT(...) { myc_print_indent(); printf(__VA_ARGS__); }
#else
#define MYC_IPRINT(...)
#endif

void myc_node_print_top(myc_Node_p n)
{
    indent = -1;

    myc_node_print(n);
}

void myc_node_print(myc_Node_p n)
{
    myc_indent();

    if (n == NULL)
    {
        MYC_IPRINT("NULL NODE\n");
        return;
    }

    switch (n->type)
    {
        case MYC_NODE_OP:
            MYC_IPRINT("Op '%c'\n", n->op);
            break;

        case MYC_NODE_LEAF:
            MYC_IPRINT("Leaf %f\n", n->val);
            break;

        default:
            printf("NodeErr\n");
            break;
    }

    if (n->left) {
        MYC_IPRINT("LEFT\n");
        myc_node_print(n->left);
    }

    if (n->right) {
        MYC_IPRINT("RIGHT\n");
        myc_node_print(n->right);
    }

    myc_dedent();
}
