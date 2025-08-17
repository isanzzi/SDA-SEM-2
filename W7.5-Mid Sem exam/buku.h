#ifndef BUKU_H
#define BUKU_H

#include "queue.h"
#include "stack.h"
#include "convention.h"

#define MAX_TITLE 50

typedef struct bukuNode *addrBuku;
typedef struct bukuNode {
    char info[MAX_TITLE];    // Nama buku
    int jml;                 // Jumlah buku yang tersedia
    address headQueue;       // Pointer ke head antrian peminjam
    addrBuku next;           // Pointer ke buku berikutnya
} Buku;

void initBuku(addrBuku *B);
addrBuku createBuku(char *judul, int jumlah);
void addBuku(addrBuku *head, char *judul, int jumlah);
addrBuku findBuku(addrBuku head, char *judul);
void displayBuku(addrBuku head);
void freeBuku(addrBuku *head);
addrBuku findNextAvailableBuku(addrBuku head);

#endif
