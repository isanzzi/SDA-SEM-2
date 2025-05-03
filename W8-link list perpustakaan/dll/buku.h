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
    addrBuku next;           // Pointer ke buku berikutnya
} Buku;

void initBuku(addrBuku *B);
addrBuku createBuku(char *judul, int jumlah);
void addBuku(addrBuku *head, char *judul, int jumlah);
addrBuku findBuku(addrBuku head, char *judul);
void displayBuku(addrBuku head);
void freeBuku(addrBuku *head);
void displayBukuanggota(addrBuku head);
void prosesbuku(addrBuku head, address *allAnggota);
void returnBuku(addrBuku head, char *peminjam, address *allAnggota);
int initstock();

#endif