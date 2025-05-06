#include "linked.h"

PairBukuAnggota* pairListHead = NULL;

void initPairList() {
    pairListHead = NULL;
}

PairBukuAnggota* createPairBukuAnggota(addrBuku buku, infotype bookTitle) {
    if (buku == NULL || bookTitle == NULL) return NULL;
    PairBukuAnggota* pair = (PairBukuAnggota*)malloc(sizeof(PairBukuAnggota));
    if (pair == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    pair->buku = buku;
    pair->bookTitle = bookTitle;
    createinitQueue(&pair->Q);
    pair->next = NULL;
    return pair;
}

PairBukuAnggota* findOrCreatePairBukuAnggotaByAddr(addrBuku book) {
    if (book == NULL) return NULL;
    PairBukuAnggota* current = pairListHead;
    while (current != NULL) {
        if (current->buku == book) return current;
        current = current->next;
    }
    char* titleCopy = strdup(book->info);
    if (titleCopy == NULL) return NULL;
    PairBukuAnggota* newPair = createPairBukuAnggota(book, titleCopy);
    if (newPair != NULL) {
        newPair->next = pairListHead;
        pairListHead = newPair;
    }
    return newPair;
}

PairBukuAnggota* findOrCreatePairBukuAnggotaByTitle(infotype bookTitle, addrBuku headbuku) {
    if (bookTitle == NULL) return NULL;
    PairBukuAnggota* current = pairListHead;
    while (current != NULL) {
        if (current->bookTitle != NULL && strcmp(current->bookTitle, bookTitle) == 0) return current;
        current = current->next;
    }
    addrBuku book = findBuku(headbuku, bookTitle);
    if (book == NULL) return NULL;
    char* titleCopy = strdup(bookTitle);
    if (titleCopy == NULL) return NULL;
    PairBukuAnggota* newPair = createPairBukuAnggota(book, titleCopy);
    if (newPair != NULL) {
        newPair->next = pairListHead;
        pairListHead = newPair;
    }
    return newPair;
}

void clearAllPairs() {
    PairBukuAnggota* current = pairListHead;
    while (current != NULL) {
        PairBukuAnggota* next = current->next;
        ExitQueue(&current->Q);
        free(current->bookTitle);
        free(current);
        current = next;
    }
    pairListHead = NULL;
}