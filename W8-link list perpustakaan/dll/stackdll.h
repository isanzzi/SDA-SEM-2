#ifndef stack_H
#define stack_H

#include "conventiondll.h"
#include "historydll.h"

typedef struct{
    addresshistorydll top;
} Stackdll;

void createinitStackdll(Stackdll *S2);

void Pushdll(Stackdll *S, infotype nilai, int level);

void Popdll(Stackdll *S, infotype *nilai);

void ExitStackdll(Stackdll *S2);

#endif