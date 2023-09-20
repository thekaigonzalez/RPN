// Copyright 2020-2023 Kai D. Gonzalez

#include "rpn.h"
#include "rpnconfig.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

void
rpn_Lexec (rpnState *s)
{
  // expression is s->__expr;
  int i;
  int n;
  char t;
  n = 0;

  char* rpn_numbers[MAX_RPNN];

  String temp;
  str_init (&temp);

  for (i = 0; i < str_length (&s->__expr); ++i)
    {
      t = str_at (&s->__expr, i);
      if (!isdigit (t) && rpn_Lop(s, t) == -1 && !isspace(t))
        continue;
      else if (isspace (t) && str_length(&temp) > 0)
        {
            rpn_numbers[n] = str_get(&temp);
            str_init(&temp);
            n++;
        }
      else if (isdigit(t))
        {
          str_add_char (&temp, str_at(&s->__expr, i));
        }
        else if (rpn_Lop(s, t) != -1) {
            int _operator = rpn_Lop(s, t);
            
            int NUMZ[MAX_RPNN];

            int numz_index = 0;

            int x;

            for (x = 0; x < n; ++ x) {
                NUMZ[x] = atoi(rpn_numbers[x]);
            }

            rpn_Vcalc(s, NUMZ, x); /* push value to the stack */

            printf("Result: %d\n", rpn_Vpop(s));
        }
    }
}
