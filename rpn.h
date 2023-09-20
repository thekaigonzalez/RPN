// Copyright 2020-2023 Kai D. Gonzalez

#include "string.h"

typedef float rpn_number_t;
typedef int rpn_state_t;

/* definitions for symbols and their numbers */

#define RPN_OP_ADD '+'
#define RPN_OP_SUB '-'
#define RPN_OP_MUL '*'
#define RPN_OP_DIV '/'

#define RPN_ADD_N 1
#define RPN_SUB_N 2
#define RPN_MUL_N 3
#define RPN_DIV_N 4
#define RPN_NULL -1

struct rpnState
{
  rpn_state_t __stat;  /* the state */
  String __expr;       /* the expression */
  rpn_number_t __res;  /* this is a float/int/whatever you set it to :) */
  rpn_number_t __LAST; /* running functions to give you values, this value is
                          used to view those values */
};

typedef struct rpnState rpnState;

void rpn_newstate (rpnState *s);
void rpn_free (rpnState *s);

void rpn_Lpush (rpnState *s, const char *stat);

void rpn_Lexec (rpnState *s);
void rpn_Lres (rpnState *s, rpn_number_t result);
void rpn_Lset (rpnState *s, rpn_state_t __state);

void rpn_Loperator (rpnState *s, char ol);
int rpn_Lop (rpnState *s, char ol);

void rpn_Vlast (rpnState *s, rpn_number_t __val);

int rpn_Vpop (rpnState *s);

void rpn_Vcalc(rpnState *s, int NUMZ[], int _sz);
