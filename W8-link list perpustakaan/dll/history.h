#ifndef history_H
#define history_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convention.h"

struct tElmtList;
typedef struct tElmtList *address;

struct bukuNode;
typedef struct bukuNode *addrBuku;

typedef struct riwayat *addresshistory;
typedef struct riwayat {
    infotype info; // untuk judul buku
    char action;   // borrow, retur, cancel
    char status;   // success, failed
    addrBuku bookref;
    address memberref;
    addresshistory next;
} History;

typedef struct {
    addresshistory top;
} Stackhistory;

// Function prototypes
addresshistory createHistoryNode(infotype bookTitle, char action, char status, addrBuku bookref, address memberref);
void addHistory(address member, infotype bookTitle, char action, char status, addrBuku bookref);
void displayHistory(address member);
void freeHistory(Stackhistory *history);

#endif