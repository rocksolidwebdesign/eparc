#include "myc/token.h"
#include "myc/token_t.h"
#include "myc/strbuf.h"

#include <string.h>

myc_Token_p
myc_tok_create(
    const int type,
    const int ignore,
    const char * src)
{
    myc_Token_p t = myc_tok_alloc();

    myc_tok_init_val(t, type, ignore, src);

    return t;
}

myc_Token_p
myc_tok_new()
{
    myc_Token_p t = myc_tok_alloc();

    myc_tok_init(t);

    return t;
}

myc_Token_p
myc_tok_alloc()
{
    return (myc_Token_p)
        malloc(sizeof(myc_Token));
}

void
myc_tok_copy_assign(
    myc_Token_p dest,
    const myc_Token_p src)
{
    myc_strbuf_copy_assign(dest->str, src->str);

    dest->type = src->type;
    dest->ignore = src->ignore;
}

void
myc_tok_set(
    myc_Token_p tok,
    const int type,
    const int ignore,
    const myc_StrBuf_p p)
{
    tok->type = type;
    tok->ignore = ignore;

    myc_strbuf_copy_assign(tok->str, p);
}

void
myc_tok_set_str(
    myc_Token_p dest,
    const char * src)
{
    myc_strbuf_from_cstr(dest->str, src);
}

void myc_tok_clean(myc_Token_p tok)
{
    myc_strbuf_del(&(tok->str));
}

void myc_tok_init(myc_Token_p tok)
{
    tok->type = 0;
    tok->str = myc_strbuf_new();
}

void
myc_tok_init_val(
    myc_Token_p tok,
    const int type,
    const int ignore,
    const char * src)
{
    tok->type = type;
    tok->ignore = ignore;
    tok->str = myc_strbuf_create(src);
}

void
myc_tok_set_val(
    myc_Token_p tok,
    const int type,
    const int ignore,
    const char * src)
{
    tok->type = type;
    tok->ignore = ignore;

    if (tok->str != NULL) {
        myc_strbuf_del(&(tok->str));
    }

    tok->str = myc_strbuf_create(src);
}

void myc_tok_del(myc_Token_P tok)
{
    if (tok != NULL && *tok != NULL)
    {
        myc_tok_clean(*tok);

        free(*tok);

        *tok = NULL;
    }
}
