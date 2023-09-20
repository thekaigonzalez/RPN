// Copyright 2020-2023 Kai D. Gonzalez

#include "rpn.h"
#include "rpnconfig.h"

void
rpn_Vcalc (rpnState *s, int NUMZ[], int _sz)
{
  int i = 0;
  int __OPERATOR = rpn_Vpop(s);

  rpn_number_t RESULT = 0;

  while (i < _sz)
    {
      if (__OPERATOR == RPN_ADD_N) {
        RESULT = RESULT + NUMZ[i];
      }

      else if (__OPERATOR == RPN_SUB_N) {
        RESULT = NUMZ[0];
        RESULT = RESULT - NUMZ[i];
      }
      
      else if (__OPERATOR == RPN_MUL_N) {
        RESULT = NUMZ[0];
        RESULT = RESULT * NUMZ[i];
      }

      else if (__OPERATOR == RPN_DIV_N) {
        RESULT = NUMZ[0];
        RESULT = RESULT / NUMZ[i];
      }

      i++;
    }
  rpn_Vlast(s, RESULT);
}
