#ifndef history_H
#define history_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conventiondll.h"

struct tElmtList;
typedef struct tElmtList *addressdll;

struct bukuNode;
typedef struct bukuNode *addrBukudll;

typedef struct riwayat *addresshistorydll;
typedef struct riwayat {
    infotype info; // untuk judul buku
    char action;   // borrow, retur, cancel
    char status;   // success, failed
    addrBukudll bookref;
    addressdll memberref;
    addresshistorydll next;
} Historydll;

typedef struct {
    addresshistorydll top;
} Stackhistorydll;

// Function prototypes
addresshistorydll createHistoryNodedll(infotype bookTitle, char action, char status, addrBukudll bookref, addressdll memberref);
void addHistorydll(addressdll member, infotype bookTitle, char action, char status, addrBukudll bookref);
void displayHistorydll(addressdll member);
void freeHistorydll(Stackhistorydll *history);

#endif