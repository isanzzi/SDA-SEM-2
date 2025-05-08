#include "stacksll.h"
#include "linkedsll.h"

void createinitStacksll(Stacksll *S2) {
    S2->top = NULL;
}

void Pushsll(Stacksll *S, infotypesll nilai) {
    addresshistorysll node = createHistoryNodesll(nilai, 'b', 's', NULL, NULL);
    if (node != NULL) {
        node->next = S->top;
        S->top = node;
    }
}

void Popsll(Stacksll *S, infotypesll *nilai) {
    if (S->top != NULL) {
        addresshistorysll temp = S->top;
        *nilai = temp->info;
        S->top = temp->next;
        free(temp->info);
        free(temp);
    }
}

void ExitStacksll(Stacksll *S2) {
    if (S2 == NULL) return;
    addresshistorysll temp;
    while (S2->top != NULL) {
        temp = S2->top;
        S2->top = temp->next;
        if (temp->info != NULL) {
            free(temp->info);
            temp->info = NULL;
        }
        free(temp);
    }
    S2->top = NULL;
}
