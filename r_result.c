// Copyright 2020-2023 Kai D. Gonzalez

#include "rpn.h"

void
rpn_Lres (rpnState *s, rpn_number_t result)
{
    s->__res = result; /* change state */
}
