#include "myc/grammar.h"
#include "myc/grammar_t.h"
#include "myc/prule.h"
#include "myc/parser.h"
#include "myc/par_t.h"
#include "myc/token_t.h"
#include "myc/toks.h"

void
myc_grammar_setup(
    myc_Par_p p)
{
    myc_parser_add_pat(p, TOK_NUM,   0, "^[0-9]+(\\.[0-9]+)?\\b");
    myc_parser_add_pat(p, TOK_ADD,   0, "^[+]");
    myc_parser_add_pat(p, TOK_SUB,   0, "^[-]");
    myc_parser_add_pat(p, TOK_MUL,   0, "^[*]");
    myc_parser_add_pat(p, TOK_DIV,   0, "^[/]");
    myc_parser_add_pat(p, TOK_OPN,   0, "^[(]");
    myc_parser_add_pat(p, TOK_CLS,   0, "^[)]");
    myc_parser_add_pat(p, TOK_SPACE, 1, "^[\\s\\v]+");
}

myc_Expr_p
myc_grammar_parse(
    myc_Par_p p,
    const char * subj,
    int * rc0)
{
    myc_parser_set_in(p, subj);

    int rc = myc_parser_read(p);

    if (rc == MYC_RC_EOS) {
        myc_toks_put(p->stack, TOK_EOF, 0, "");

        return myc_prule_start(p, rc0);
    }

    *rc0 = MYC_RC_ERR;

    return NULL;
}
