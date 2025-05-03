#include "stack.h"
#include "linked.h"

void createinitStack(Stack *S2){
    S2->top = nil;
}

void Push (Stack *S, infotype nilai, int level){
    addresshistory node = (addresshistory)SetNode(&nilai, level);
    Ins_Awal((address*)&(S->top), (address)node);
}

void Pop (Stack *S, infotype *nilai){
    if (!isEmpty((address)(S->top))) {
        Del_Awal((address*)&(S->top), nilai);
    }
}

void ExitStack (Stack *S2){
    DeAlokasi ((address*)&(S2->top));
}