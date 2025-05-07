#include "stackarray.h"
#include "linkedarray.h"

void createinitStackArray(Stackarray *S2){
    S2->top = nil;
}

void PushArray (Stackarray *S, infotype nilai, int level){
    addresshistoryarray node = (addresshistoryarray)SetNodeArray(&nilai, level);
    Ins_AwalArray((addressarray*)&(S->top), (addressarray)node);
}

void PopArray (Stackarray *S, infotype *nilai){
    if (!isEmptyarray((addressarray)(S->top))) {
        Del_AwalArray((addressarray*)&(S->top), nilai);
    }
}

void ExitStackArray (Stackarray *S2){
    DeAlokasiArray ((addressarray*)&(S2->top));
}