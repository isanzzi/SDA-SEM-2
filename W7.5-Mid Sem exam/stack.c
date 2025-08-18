#include "stack.h"

void createinitStack(Stack *S2){
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

void ExitStack (Stack *S2){
    DeAlokasi (&(S2->top));
}