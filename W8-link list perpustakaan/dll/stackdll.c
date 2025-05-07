#include "stackdll.h"
#include "linkeddll.h"

void createinitStackdll(Stackdll *S2){
    S2->top = nil;
}

void Pushdll(Stackdll *S, infotype nilai, int level){
    addresshistorydll node = (addresshistorydll)SetNodedll(&nilai, level);
    Ins_Awaldll((addressdll*)&(S->top), (addressdll)node);
}

void Popdll(Stackdll *S, infotype *nilai){
    if (!isEmptydll((addressdll)(S->top))) {
        Del_Awaldll((addressdll*)&(S->top), nilai);
    }
}

void ExitStackdll(Stackdll *S2){
    DeAlokasidll((addressdll*)&(S2->top));
}