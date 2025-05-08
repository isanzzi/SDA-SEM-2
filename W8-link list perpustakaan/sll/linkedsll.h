#ifndef LINKED_H
#define LINKED_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conventionsll.h"
#include "stacksll.h"
#include "queuesll.h"

typedef struct tElmtListsll {
    infotypesll info;
    int priority;
    struct tElmtListsll* next;
    Stacksll history;
} Anggotasll, Bukusll;

typedef struct pairbukuanggotasll {
    addrBukusll buku;
    infotypesll bookTitle;
    Queuesll Q;
    struct pairbukuanggotasll* next;
} PairBukuAnggotasll;

booleansll isEmptysll(addresssll p);
void CreateEmptysll(addresssll *q);
addresssll SetNodesll(infotypesll *nama, int prior);
char* InsertTitlesll();
char* insertNamasll();
int initlevelsll();
int initStocksll();
void Tampil_Listsll(addresssll p);
addresssll Searchsll(addresssll p, infotypesll nilai);
void Ins_Awalsll(addresssll *p, addresssll PNew);
void modifiedIns_Akhirsll(addresssll *p, addresssll PNew);
booleansll DeleteValuesll(addresssll *p, infotypesll target, infotypesll *X);
void DeAlokasisll(addresssll *p);
int NbElmtsll(addresssll head, addresssll tail);

void initBukusll(addrBukusll *B);
addrBukusll createBukusll(char *judul, int jumlah);
void addBukusll(addrBukusll *head, char *judul, int jumlah);
addrBukusll findBukusll(addrBukusll head, char *judul);
void displayBukusll(addrBukusll head);
void freeBukusll(addrBukusll *head);
void displayBukuanggotasll(addrBukusll head);
void prosesbukusll(addrBukusll head, addresssll *allAnggota);
void returnBukusll(addrBukusll head, infotypesll peminjam, addresssll *allAnggota);

PairBukuAnggotasll* createPairBukuAnggotasll(addrBukusll buku, infotypesll bookTitle);
PairBukuAnggotasll* findOrCreatePairBukuAnggotaByAddrsll(addrBukusll book);
PairBukuAnggotasll* findOrCreatePairBukuAnggotaByTitlesll(infotypesll bookTitle, addrBukusll headbuku);
void clearAllPairssll();
void initPairListsll();
PairBukuAnggotasll* findPairBukuAnggotaByAddrsll(addrBukusll book);

#endif