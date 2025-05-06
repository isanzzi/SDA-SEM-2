#include "stack.h"
#include "linked.h"

void createinitStack(Stack *S2) {
    S2->top = NULL;
}

void Push(Stack *S, infotype nilai) {
    addresshistory node = createHistoryNode(nilai, 'b', 's', NULL, NULL);
    if (node != NULL) {
        node->next = S->top;
        S->top = node;
    }
}

void Pop(Stack *S, infotype *nilai) {
    if (S->top != NULL) {
        addresshistory temp = S->top;
        *nilai = temp->info;
        S->top = temp->next;
        free(temp->info);
        free(temp);
    }
}

void ExitStack(Stack *S2) {
    addresshistory temp;
    while (S2->top != NULL) {
        temp = S2->top;
        S2->top = temp->next;
        free(temp->info);
        free(temp);
    }
}