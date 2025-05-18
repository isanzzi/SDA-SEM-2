#include "linkedsll.h"

PairBukuAnggotasll* pairListHeadsll = NULL;

void initPairListsll() {
    pairListHeadsll = NULL;
}

PairBukuAnggotasll* createPairBukuAnggotasll(addrBukusll buku, infotypesll bookTitle) {
    if (buku == NULL || bookTitle == NULL) return NULL;
    PairBukuAnggotasll* pair = (PairBukuAnggotasll*)malloc(sizeof(PairBukuAnggotasll));
    if (pair == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    pair->buku = buku;
    pair->bookTitle = bookTitle;
    createinitQueuesll(&pair->Q);
    pair->next = NULL;
    return pair;
}

PairBukuAnggotasll* findOrCreatePairBukuAnggotaByAddrsll(addrBukusll book) {
    if (book == NULL) return NULL;
    PairBukuAnggotasll* current = pairListHeadsll;
    while (current != NULL) {
        if (current->buku == book) return current;
        current = current->next;
    }
    char* titleCopy = strdup(book->info);
    if (titleCopy == NULL) return NULL;
    PairBukuAnggotasll* newPair = createPairBukuAnggotasll(book, titleCopy);
    if (newPair != NULL) {
        newPair->next = pairListHeadsll;
        pairListHeadsll = newPair;
    }
    return newPair;
}

PairBukuAnggotasll* findOrCreatePairBukuAnggotaByTitlesll(infotypesll bookTitle, addrBukusll headbuku) {
    if (bookTitle == NULL) return NULL;
    PairBukuAnggotasll* current = pairListHeadsll;
    while (current != NULL) {
        if (current->bookTitle != NULL && strcmp(current->bookTitle, bookTitle) == 0) return current;
        current = current->next;
    }
    addrBukusll book = findBukusll(headbuku, bookTitle);
    if (book == NULL) return NULL;
    char* titleCopy = strdup(bookTitle);
    if (titleCopy == NULL) return NULL;
    PairBukuAnggotasll* newPair = createPairBukuAnggotasll(book, titleCopy);
    if (newPair != NULL) {
        newPair->next = pairListHeadsll;
        pairListHeadsll = newPair;
    }
    return newPair;
}

PairBukuAnggotasll* findPairBukuAnggotaByAddrsll(addrBukusll book) {
    if (book == NULL) return NULL;
    PairBukuAnggotasll* current = pairListHeadsll;
    while (current != NULL) {
        if (current->buku == book) return current;
        current = current->next;
    }
    return NULL;
}

void clearAllPairssll() {
    PairBukuAnggotasll* current = pairListHeadsll;
    while (current != NULL) {
        PairBukuAnggotasll* next = current->next;
        // Hanya free bookTitle dan struct pair saja
        if (current->bookTitle != NULL) {
            free(current->bookTitle);
            current->bookTitle = NULL;
        }
        free(current);
        current = next;
    }
    pairListHeadsll = NULL;
}
