// Copyright 2020-2023 Kai D. Gonzalez

#include "rpn.h"

void rpn_Lset(rpnState * s, rpn_state_t __state)
{
    s->__stat = __state;
}