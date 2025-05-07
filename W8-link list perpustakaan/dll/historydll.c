#include "historydll.h"
#include "linkeddll.h"

addresshistorydll createHistoryNodedll(infotype bookTitle, char action, char status, addrBukudll bookref, addressdll memberref) {
    addresshistorydll newNode = (addresshistorydll)malloc(sizeof(Historydll));
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

void addHistorydll(addressdll member, infotype bookTitle, char action, char status, addrBukudll bookref) {
    if (member == NULL) return;
    
    addresshistorydll newHistory = createHistoryNodedll(bookTitle, action, status, bookref, member);
    if (newHistory == NULL) return;
    
    // Add to stack (insert at beginning)
    newHistory->next = member->history.top;
    member->history.top = newHistory;
}

void displayHistorydll(addressdll member) {
    if (member == NULL) {
        printf("Member not found\n");
        return;
    }
    
    printf("History for %s:\n", info(member) ? info(member) : "Unknown");
    if (member->history.top == NULL) {
        printf("No history available\n");
        return;
    }
    
    printf("%-20s %-10s %-10s\n", "Book", "Action", "Status");
    printf("----------------------------------------\n");
    
    addresshistorydll current = member->history.top;
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
        
        printf("%-20s %-10s %-10s\n", 
               current->info ? current->info : "Unknown", 
               actionStr, 
               statusStr);
        current = current->next;
    }
}

void freeHistorydll(Stackhistorydll *history) {
    addresshistorydll current, temp;
    
    current = history->top;
    
    while (current != NULL) {
        temp = current;
        current = current->next;
        
        // Free the book title string
        if (temp->info != NULL) {
            free(temp->info);
        }
        
        // Free node
        free(temp);
    }
    
    // Reset pointer stack top
    history->top = NULL;
}