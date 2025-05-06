#ifndef LINKED_H
#define LINKED_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convention.h"
#include "stack.h"
#include "queue.h"

typedef struct tElmtList {
    infotype info;
    int priority;
    struct tElmtList* next;
    Stack history;
} Anggota, Buku;

typedef struct pairbukuanggota {
    addrBuku buku;
    infotype bookTitle;
    Queue Q;
    struct pairbukuanggota* next;
} PairBukuAnggota;

boolean isEmpty(address p);
void CreateEmpty(address *q);
address SetNode(infotype *nama, int prior);
char* InsertTitle();
char* insertNama();
int initlevel();
int initStock();
void Tampil_List(address p);
address Search(address p, infotype nilai);
void Ins_Awal(address *p, address PNew);
void modifiedIns_Akhir(address *p, address PNew);
boolean DeleteValue(address *p, infotype target, infotype *X);
void DeAlokasi(address *p);
int NbElmt(address head, address tail);

void initBuku(addrBuku *B);
addrBuku createBuku(char *judul, int jumlah);
void addBuku(addrBuku *head, char *judul, int jumlah);
addrBuku findBuku(addrBuku head, char *judul);
void displayBuku(addrBuku head);
void freeBuku(addrBuku *head);
void displayBukuanggota(addrBuku head);
void prosesbuku(addrBuku head, address *allAnggota);
void returnBuku(addrBuku head, infotype peminjam, address *allAnggota);

PairBukuAnggota* createPairBukuAnggota(addrBuku buku, infotype bookTitle);
PairBukuAnggota* findOrCreatePairBukuAnggotaByAddr(addrBuku book);
PairBukuAnggota* findOrCreatePairBukuAnggotaByTitle(infotype bookTitle, addrBuku headbuku);
void clearAllPairs();
void initPairList();

#endif