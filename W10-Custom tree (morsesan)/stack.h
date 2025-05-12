#ifndef stack_H
#define stack_H

#include "convention.h"
#include <stdio.h>

typedef char infoelmt;

typedef struct tElmtlist *addrelmt;
typedef struct tElmtlist {
    infoelmt info;
    addrelmt next;
} tElmtlist;

typedef struct {
    addrelmt top;
} Stack;

// Linked list
addrelmt SetNode(infoelmt *nilai);
void Ins_Awal(addrelmt *head, addrelmt newNode);
void Del_Awal(addrelmt *head, infoelmt *nilai);
void DeAlokasi(addrelmt *head);
bool isEmpty(addrelmt head);

// Stack
void createinitStack(Stack *S1);
void Push(Stack *S, infoelmt nilai);
void Pop(Stack *S, infoelmt *nilai);
void ExitStack(Stack *S1);
bool StackEmpty(Stack *S);

#endif