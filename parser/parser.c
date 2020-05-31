#include "myc/parser.h"
#include "myc/par.h"
#include "myc/scanr.h"
#include "myc/toks.h"

#include <assert.h>

int
myc_parser_read(
    myc_Par_p p)
{
    int rc = 0;

    while ((rc = myc_scanr_read(p->scanr)) == MYC_RC_TOK)
    {
        if (!p->scanr->tok->ignore)
        {
            myc_toks_push(p->stack, p->scanr->tok);
        }
    }

    return rc;
}

void
myc_parser_set_in(
    myc_Par_p p,
    const char * in)
{
    myc_scanr_set_in(p->scanr, in);
}

void
myc_parser_push_pat(
    myc_Par_p p,
    const myc_TokPat_p pat)
{
    myc_scanr_push_pat(p->scanr, pat);

    p->stack = myc_toks_new();
    p->pos = 0;
}

void
myc_parser_add_pat(
    myc_Par_p p,
    const int type,
    const int ignore,
    const char * pat_str)
{
    myc_scanr_put_pat(p->scanr, type, ignore, pat_str);
}


void
myc_parser_step(
    myc_Par_p p)
{
    p->pos += 1;

    if (p->pos >= p->stack->len) {
        p->pos = p->stack->len - 1;
    }
}

myc_Token_p
myc_parser_cur(
    myc_Par_p p)
{
    assert(p->pos < p->stack->len);

    return myc_toks_at(p->stack, p->pos);
}

myc_Token_p
myc_parser_peek(
    myc_Par_p p)
{
    const size_t next_pos = p->pos + 1;

    assert(next_pos < p->stack->len);

    return myc_toks_at(p->stack, next_pos);
}
