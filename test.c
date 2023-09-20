#include "rpn.h"


int
main ()
{
  rpnState s;        /* declare state */
  rpn_newstate (&s); /* initialize rpn state */

  rpn_Lpush (&s, "12 2 /"); /* push a statement */

  rpn_Lexec (&s);

  rpn_free(&s);
}