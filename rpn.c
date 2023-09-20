// Copyright 2020-2023 Kai D. Gonzalez
#include "rpn.h"

void rpn_newstate(rpnState *s)
 {
    str_init(&s->__expr);
    s->__stat = 0;
}

void
rpn_Lpush (rpnState *s, const char *stat)
{
    while ((*stat != '\0')) {
        str_add_char(&s->__expr, *stat);
        *stat++;
    }
}

void
rpn_free (rpnState *s)
{
    str_free(&s->__expr);
    s->__stat = -1;
    s->__res  = -1;
}
