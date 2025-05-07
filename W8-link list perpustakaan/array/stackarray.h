#ifndef stack_H
#define stack_H

#include "conventionarray.h"
#include "historyarray.h"

typedef struct{
    addresshistoryarray top;
} Stackarray;

void createinitStackArray(Stackarray *S2);
void PushArray(Stackarray *S, infotype nilai, int level);
void PopArray(Stackarray *S, infotype *nilai);
void ExitStackArray(Stackarray *S2);

#endif