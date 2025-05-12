#include "stack.h"
#include <stdlib.h>

//linked list
addrelmt SetNode(infoelmt *nilai) {
    addrelmt newNode = (addrelmt)malloc(sizeof(tElmtlist));
    if (newNode != NULL) {
        newNode->info = *nilai;
        newNode->next = NULL;
    }
    return newNode;
}

void Ins_Awal(addrelmt *head, addrelmt newNode) {
    newNode->next = *head;
    *head = newNode;
}

void Del_Awal(addrelmt *head, infoelmt *nilai) {
    addrelmt temp = *head;
    *nilai = temp->info;
    *head = temp->next;
    free(temp);
}

void DeAlokasi(addrelmt *head) {
    addrelmt temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

bool isEmpty(addrelmt head) {
    return (head == NULL);
}


//stack
void createinitStack(Stack *S1) {
    S1->top = NULL;
}

void Push(Stack *S, infoelmt nilai) {
    Ins_Awal(&(S->top), SetNode(&nilai));
}

void Pop(Stack *S, infoelmt *nilai) {
    if (!isEmpty(S->top)) {
        Del_Awal(&(S->top), nilai);
    }
}

void ExitStack(Stack *S1) {
    DeAlokasi(&(S1->top));
}

bool StackEmpty(Stack *S) {
    return isEmpty(S->top);
}