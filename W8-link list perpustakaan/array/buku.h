#ifndef BUKU_H
#define BUKU_H

#include "convention.h"
#include "queue.h"

#define MAX_TITLE 50

typedef struct bukuNode *addrBuku;
typedef struct bukuNode {
    infotype info;              // Nama buku
    int stock;                 // Jumlah buku yang tersedia
    Queue Q;                  // Pointer ke head antrian peminjam
} Buku;

addrBuku findBukuArray(Buku buku[], char *judul, int count);
void addBukuArray(Buku buku[], char *judul, int jumlah, int *count, int maxCount);
void displayBukuArray(Buku buku[], int count);
void freeBukuArray(Buku buku[], int count);

#endif