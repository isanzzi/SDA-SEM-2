#include "history.h"
#include "linked.h"

addresshistory createHistoryNode(infotype bookTitle, char action, char status, addrBuku bookref, address memberref) {
    addresshistory newNode = (addresshistory)malloc(sizeof(History));
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

void addHistory(address member, infotype bookTitle, char action, char status, addrBuku bookref) {
    if (member == NULL) return;
    
    addresshistory newHistory = createHistoryNode(bookTitle, action, status, bookref, member);
    if (newHistory == NULL) return;
    
    // Add to stack (insert at beginning)
    newHistory->next = member->history.top;
    member->history.top = newHistory;
}

void displayHistory(address member) {
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
    
    addresshistory current = member->history.top;
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