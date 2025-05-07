#ifndef BUKU_H
#define BUKU_H

#include "conventionarray.h"
#include "queuearray.h"

#define MAX_TITLE 50

typedef struct bukuNodeArray *addrBukuarray;
typedef struct bukuNodeArray {
    infotype info;
    int stock;
    Queuearray Q;
} Bukuarray;

addrBukuarray findBukuArray(Bukuarray buku[], char *judul, int count);
void addBukuArray(Bukuarray buku[], char *judul, int jumlah, int *count, int maxCount);
void displayBukuArray(Bukuarray buku[], int count);
void freeBukuArray(Bukuarray buku[], int count);

#endif