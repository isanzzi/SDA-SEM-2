#include "stack.h"

void createinitStack(Stack *S1, Stack *S2){
    S1->top = nil;
    S2->top = nil;
}

void Push (Stack *S, infotype nilai){
    Ins_Awal (&(S->top), SetNode(&nilai));
}

void Pop (Stack *S, infotype *nilai){
if (!isEmpty(S->top)) {
    Del_Awal(&(S->top), nilai);
    }
}

void ExitStack (Stack *S1, Stack *S2){
    DeAlokasi (&(S1->top));
    DeAlokasi (&(S2->top));
}