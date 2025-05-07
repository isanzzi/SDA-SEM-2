#ifndef BUKU_H
#define BUKU_H

#include "conventiondll.h"
#include "queuedll.h"

#define MAX_TITLE 50

typedef struct bukuNode *addrBukudll;
typedef struct bukuNode {
    infotype info;              // Nama buku
    int stock;                 // Jumlah buku yang tersedia
    Queuedll Q;                  // Pointer ke head antrian peminjam
    addrBukudll next;           // Pointer ke buku berikutnya
} Bukudll;

void initBukudll(addrBukudll *B);
addrBukudll createBukudll(char *judul, int jumlah);
void addBukudll(addrBukudll *head, char *judul, int jumlah);
addrBukudll findBukudll(addrBukudll head, char *judul);
void displayBukudll(addrBukudll head);
void freeBukudll(addrBukudll *head);
void displayBukuanggotadll(addrBukudll head);
void prosesbukudll(addrBukudll head, addressdll *allAnggota);
void returnBukudll(addrBukudll head, char *peminjam, addressdll *allAnggota);
int initstockdll();

#endif