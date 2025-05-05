#ifndef stack_H
#define stack_H

#include "convention.h"
#include "history.h"

typedef struct{
    addresshistory top;
} Stack;

void createinitStack(Stack *S2);

void Push(Stack *S, infotype nilai, int level);

void Pop(Stack *S, infotype *nilai);

void ExitStack(Stack *S2);

#endif