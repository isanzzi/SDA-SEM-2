#include "historyarray.h"
#include "linkedarray.h"

addresshistoryarray createHistoryNodeArray(infotype bookTitle, char action, char status, addrBukuarray bookref, addressarray memberref) {
    addresshistoryarray newNode = (addresshistoryarray)malloc(sizeof(Historyarray));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->info = strdup(bookTitle);
    newNode->action = action;
    newNode->status = status;
    newNode->bookref = bookref;
    newNode->memberref = memberref;
    newNode->next = NULL;
    return newNode;
}

void addHistoryArray(addressarray member, infotype bookTitle, char action, char status, addrBukuarray bookref) {
    if (member == NULL) return;
    addresshistoryarray newHistory = createHistoryNodeArray(bookTitle, action, status, bookref, member);
    if (newHistory == NULL) return;
    newHistory->next = member->history.top;
    member->history.top = newHistory;
}

void displayHistoryArray(addressarray member) {
    if (member == NULL) {
        printf("Member not found\n");
        return;
    }
    printf("History for member '%s':\n", info(member));
    if (member->history.top == NULL) {
        printf("No history available\n");
        return;
    }
    printf("%-20s %-10s %-10s\n", "Book", "Action", "Status");
    printf("----------------------------------------\n");
    addresshistoryarray current = member->history.top;
    while (current != NULL) {
        char actionStr[20];
        switch (current->action) {
            case 'b': strcpy(actionStr, "Borrow"); break;
            case 'r': strcpy(actionStr, "Return"); break;
            case 'c': strcpy(actionStr, "Cancel"); break;
            default: strcpy(actionStr, "Unknown");
        }
        char statusStr[20];
        switch (current->status) {
            case 's': strcpy(statusStr, "Success"); break;
            case 'f': strcpy(statusStr, "Failed"); break;
            default: strcpy(statusStr, "Unknown");
        }
        printf("%-20s %-10s %-10s\n", current->info, actionStr, statusStr);
        current = current->next;
    }
}

void freeHistoryArray(Stackhistoryarray *history) {
    addresshistoryarray current, temp;
    current = history->top;
    while (current != NULL) {
        temp = current;
        current = current->next;
        if (temp->info != NULL) {
            free(temp->info);
        }
        free(temp);
    }
    history->top = NULL;
}