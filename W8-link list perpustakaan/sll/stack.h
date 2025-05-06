#ifndef stack_H
#define stack_H
#include "history.h"

typedef struct stack {
    addresshistory top;
} Stack;

void createinitStack(Stack *S2);
void Push(Stack *S, infotype nilai);
void Pop(Stack *S, infotype *nilai);
void ExitStack(Stack *S2);

#endif