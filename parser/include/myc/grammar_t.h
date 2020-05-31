#ifndef MYC_PARSER_GRAMMAR_T_H
#define MYC_PARSER_GRAMMAR_T_H

#include <stdlib.h>

/*

  Start  -> Expr EOF

  Expr   -> Term Expr'
  Expr'  -> + Term Expr'
          | - Term Expr'
          | empty

  Term   -> Factor Term'
  Term'  -> * Factor Term'
          | / Factor Term'
          | empty

  Factor -> num | ( Expr )

*/

enum MYC_PRULE_RESULT_ENUM
{
    MYC_OK,
    MYC_ERR
};

enum MYC_TOKEN_TYPES_ENUM
{
    TOK_NUM = 1000,
    TOK_ADD,
    TOK_SUB,
    TOK_MUL,
    TOK_DIV,
    TOK_OPN,
    TOK_CLS,
    TOK_SPACE,
    TOK_EOF
};

struct myc_Expr_t;
struct myc_ExprPrime_t;
struct myc_Term_t;
struct myc_TermPrime_t;
struct myc_Factor_t;

typedef struct myc_Expr_t myc_Expr;
typedef myc_Expr * myc_Expr_p;
typedef myc_Expr ** myc_Expr_P;

typedef struct myc_ExprPrime_t myc_ExprPrime;
typedef myc_ExprPrime * myc_ExprPrime_p;
typedef myc_ExprPrime ** myc_ExprPrime_P;

typedef struct myc_Term_t myc_Term;
typedef myc_Term * myc_Term_p;
typedef myc_Term ** myc_Term_P;

typedef struct myc_TermPrime_t myc_TermPrime;
typedef myc_TermPrime * myc_TermPrime_p;
typedef myc_TermPrime ** myc_TermPrime_P;

typedef struct myc_Factor_t myc_Factor;
typedef myc_Factor * myc_Factor_p;
typedef myc_Factor ** myc_Factor_P;

struct myc_Expr_t
{
    myc_Term_p term;
    myc_ExprPrime_p next;
};

struct myc_ExprPrime_t
{
    char op;
    myc_Term_p term;
    myc_ExprPrime_p next;
};

struct myc_Term_t
{
    myc_Factor_p factor;
    myc_TermPrime_p next;
};

struct myc_TermPrime_t
{
    char op;
    myc_Factor_p factor;
    myc_TermPrime_p next;
};

enum MYC_FACTOR_TYPES_ENUM
{
    MYC_NUM_FACTOR,
    MYC_EXPR_FACTOR
};

struct myc_Factor_t
{
    int type;
    double num;
    myc_Expr_p expr;
};

#endif
