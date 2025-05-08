#ifndef stack_H
#define stack_H
#include "historysll.h"

typedef struct stacksll {
    addresshistorysll top;
} Stacksll;

void createinitStacksll(Stacksll *S2);
void Pushsll(Stacksll *S, infotypesll nilai);
void Popsll(Stacksll *S, infotypesll *nilai);
void ExitStacksll(Stacksll *S2);

#endif