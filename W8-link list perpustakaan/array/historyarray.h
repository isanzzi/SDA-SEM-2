#ifndef history_H
#define history_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conventionarray.h"

struct tElmtListArray;
typedef struct tElmtListArray *addressarray;

struct bukuNodeArray;
typedef struct bukuNodeArray *addrBukuarray;

typedef struct riwayatArray *addresshistoryarray;
typedef struct riwayatArray {
    infotype info;
    char action;
    char status;
    addrBukuarray bookref;
    addressarray memberref;
    addresshistoryarray next;
} Historyarray;

typedef struct {
    addresshistoryarray top;
} Stackhistoryarray;

addresshistoryarray createHistoryNodeArray(infotype bookTitle, char action, char status, addrBukuarray bookref, addressarray memberref);
void addHistoryArray(addressarray member, infotype bookTitle, char action, char status, addrBukuarray bookref);
void displayHistoryArray(addressarray member);
void freeHistoryArray(Stackhistoryarray *history);

#endif