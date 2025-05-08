#ifndef history_H
#define history_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conventionsll.h"

struct tElmtListsll;
typedef struct tElmtListsll *addresssll;
struct Stacksll;

typedef struct riwayatsll *addresshistorysll;
typedef struct riwayatsll {
    infotypesll info;
    char action;
    char status;
    addrBukusll bookref;
    addresssll memberref;
    addresshistorysll next;
} Historysll;

addresshistorysll createHistoryNodesll(infotypesll bookTitle, char action, char status, addrBukusll bookref, addresssll memberref);
void addHistorysll(addresssll member, infotypesll bookTitle, char action, char status, addrBukusll bookref);
void displayHistorysll(addresssll member);

#endif