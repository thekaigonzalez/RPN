// Copyright 2020-2023 Kai D. Gonzalez

#include "rpn.h"
#include "rpnconfig.h"

#include <stdio.h>

void
rpn_Loperator (rpnState *s, char ol)
{
    switch (ol) {
        case RPN_OP_ADD: rpn_Vlast(s, RPN_ADD_N); break;
        case RPN_OP_SUB: rpn_Vlast(s, RPN_SUB_N); break;
        case RPN_OP_MUL: rpn_Vlast(s, RPN_MUL_N); break;
        case RPN_OP_DIV: rpn_Vlast(s, RPN_DIV_N); break;
        default: rpn_Vlast(s, RPN_NULL); break;
    }
}

int
rpn_Lop (rpnState *s, char ol)
{
    rpn_Loperator(s, ol);
    return rpn_Vpop(s);
}
