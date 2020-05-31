#include "myc/scanr.h"
#include "myc/scanr_t.h"
#include "myc/tokpats.h"
#include "myc/tokpats_t.h"
#include "myc/tokpat_t.h"
#include "myc/token_t.h"
#include "myc/token.h"
#include "myc/regex.h"
#include "myc/strbuf.h"

#include <stdlib.h>
#include <assert.h>

myc_Scanr_p
myc_scanr_create(
    myc_TokPats_p pats)
{
    myc_Scanr_p obj = myc_scanr_alloc();

    assert(obj != NULL);

    myc_scanr_init(obj, pats);

    return obj;
}

myc_Scanr_p
myc_scanr_new()
{
    myc_Scanr_p obj = myc_scanr_alloc();

    assert(obj != NULL);

    myc_scanr_init(obj, NULL);

    return obj;
}

void
myc_scanr_init(
    myc_Scanr_p obj,
    myc_TokPats_p pats)
{
    assert(obj != NULL);

    obj->rc = MYC_RC_IN;
    obj->prev_pos = 0;
    obj->pos = 0;
    obj->in = NULL;
    obj->tok = myc_tok_new();
    obj->pats = pats != NULL
        ? pats
        : myc_tokpats_new();
}

void
myc_scanr_push_pat(
    myc_Scanr_p obj,
    const myc_TokPat_p pat)
{
    myc_tokpats_push(obj->pats, pat);
}

void
myc_scanr_put_pat(
    myc_Scanr_p obj,
    const int type,
    const int ignore,
    const char * pat_str)
{
    myc_tokpats_put(obj->pats, type, ignore, pat_str);
}

void
myc_scanr_set_in(
    myc_Scanr_p obj,
    const char * subj)
{
    obj->in = subj;
    obj->pos = 0;
}

int
myc_scanr_read(
    myc_Scanr_p obj)
{
    if (obj->in == NULL) {
        return MYC_RC_IN;
    }

    if (obj->in[obj->pos + 1] == '\0') {
        return MYC_RC_EOS;
    }

    const long is_match =
        myc_scanr_match_token(obj);

    if (!is_match) {
        return MYC_RC_ERR;
    }

    const size_t len = obj->tok->str->len;

    obj->prev_pos = obj->pos;
    obj->pos += len;

    return MYC_RC_TOK;
}

int
myc_scanr_match_token(
    myc_Scanr_p obj)
{
    const char * s = obj->in + obj->pos;

    const size_t len = obj->pats->len;

    for (size_t i = 0; i < len; i++)
    {
        myc_TokPat_p p = myc_tokpats_at(obj->pats, i);

        if (myc_regex_match(p->re, s))
        {
            myc_StrBuf_p str =
                myc_scanr_get_str(obj->pats, i);

            myc_tok_set(
                obj->tok,
                p->type,
                p->ignore,
                str
            );

            myc_strbuf_del(&str);

            return 1;
        }
    }

    return 0;
}


void
myc_scanr_copy_tok(
    myc_Scanr_p obj,
    myc_Token_p tok)
{
    myc_tok_copy_assign(tok, obj->tok);
}

myc_Token_p
myc_scanr_get_tok(
    myc_Scanr_p obj)
{
    return myc_tok_create(
        obj->tok->type,
        obj->tok->ignore,
        obj->tok->str->data
    );
}

myc_StrBuf_p
myc_scanr_get_str(
    myc_TokPats_p pats,
    const size_t i)
{
    return myc_regex_m(pats->data[i].re);
}

myc_Scanr_p
myc_scanr_alloc()
{
    return (myc_Scanr_p)
        malloc(sizeof(myc_Scanr));
}

void
myc_scanr_del(
    myc_Scanr_P Z)
{
    myc_Scanr_p A = *Z;

    if (Z != NULL && A != NULL)
    {
        if (A->pats != NULL) {
            myc_tokpats_del(&A->pats);
        }

        if (A->tok != NULL) {
            myc_tok_del(&A->tok);
        }

        free(A);

        *Z = NULL;
    }
}
