#include "historysll.h"
#include "linkedsll.h"

addresshistorysll createHistoryNodesll(infotypesll bookTitle, char action, char status, addrBukusll bookref, addresssll memberref) {
    addresshistorysll newNode = (addresshistorysll)malloc(sizeof(Historysll));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->info = strdup(bookTitle);
    if (newNode->info == NULL) {
        free(newNode);
        printf("Memory allocation failed for book title\n");
        return NULL;
    }
    newNode->action = action;
    newNode->status = status;
    newNode->bookref = bookref;
    newNode->memberref = memberref;
    newNode->next = NULL;
    return newNode;
}

void addHistorysll(addresssll member, infotypesll bookTitle, char action, char status, addrBukusll bookref) {
    if (member == NULL) return;
    addresshistorysll newHistory = createHistoryNodesll(bookTitle, action, status, bookref, member);
    if (newHistory == NULL) return;
    newHistory->next = member->history.top;
    member->history.top = newHistory;
}

void displayHistorysll(addresssll member) {
    if (member == NULL) {
        printf("Member not found\n");
        return;
    }
    printf("History for %s:\n", info(member));
    if (member->history.top == NULL) {
        printf("No history available\n");
        return;
    }
    printf("%-20s %-10s %-10s\n", "Book", "Action", "Status");
    printf("----------------------------------------\n");
    addresshistorysll current = member->history.top;
    while (current != NULL) {
        char actionStr[20];
        switch (current->action) {
            case 'b': strcpy(actionStr, "Borrow"); break;
            case 'r': strcpy(actionStr, "Return"); break;
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