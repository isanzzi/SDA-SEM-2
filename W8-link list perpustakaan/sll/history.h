#ifndef history_H
#define history_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convention.h"

struct tElmtList;
typedef struct tElmtList *address;
struct Stack;

typedef struct riwayat *addresshistory;
typedef struct riwayat {
    infotype info;
    char action;
    char status;
    addrBuku bookref;
    address memberref;
    addresshistory next;
} History;

addresshistory createHistoryNode(infotype bookTitle, char action, char status, addrBuku bookref, address memberref);
void addHistory(address member, infotype bookTitle, char action, char status, addrBuku bookref);
void displayHistory(address member);

#endif