// Copyright 2020-2023 Kai D. Gonzalez

#include "rpn.h"
#include "rpnconfig.h"

void rpn_Vlast(rpnState * s, rpn_number_t __val)
{
    s->__LAST = __val;
}

int rpn_Vpop(rpnState * s)
{
return s->__LAST;
}
