#ifndef stack_H
#define stack_H

#include "convention.h"
#include "linked.h"

typedef address Stack;

address CreateStack (infotype nilai);

void Push (Stack *S, infotype nilai);

void Pop (Stack *S, infotype *nilai);

void popallandprint(address *q);

#endif