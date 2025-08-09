#include "stack.h"

address CreateStack (infotype nilai){
    address P;
    Create_Node (&P);
    Isi_Node(&P, nilai);
    return P;
}

void Push (Stack *S, infotype nilai){
    Ins_Awal (S, CreateStack(nilai));
}

void Pop (Stack *S, infotype *nilai){
    Del_Awal (S, nilai);
}

void popallandprint(address *q){
    infotype nilai;
    while (!isEmpty(*q)){
        Pop(q, &nilai);
        printf("%d", nilai);
    }
    printf("\n");
}