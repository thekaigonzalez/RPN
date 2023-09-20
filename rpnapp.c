#include "rpn.h"
#include "rpnconfig.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main ()
{
  printf ("RPN (Reverse-Polish Notation) Calculator\nLicensed under: BSD "
          "2-Clause License\nCopyright (c) 2023, Kai D. Gonzalez\ntype 'exit' to exit\n\n");
  while (1)
    {
      rpnState s;        /* declare state */
      rpn_newstate (&s); /* initialize rpn state */
      printf ("rpn> ");
      char *c = malloc (BUFSIZ);

      fgets (c, BUFSIZ, stdin);

      if ((strlen (c) > 0) && (c[strlen (c) - 1] == '\n')) // wtf is this
        c[strlen (c) - 1] = '\0';

      if (strcmp(c, "exit") == 0) { printf("rpn: exiting\n"); exit(0);}

      rpn_Lpush (&s, c); /* push a statement */
      rpn_Lexec (&s);

      rpn_free (&s);
    }
}