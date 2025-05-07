#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bukuarray.h"

addrBukuarray findBukuArray(Bukuarray buku[], char *judul, int count) {
    int i = 0;
    while (i < count) {
        if (strcmp(buku[i].info, judul) == 0) {
            return &buku[i];
        }
        i++;
    }
    return NULL;
}

void addBukuArray(Bukuarray buku[], char *judul, int jumlah, int *count, int maxCount) {
    if (*count >= maxCount) {
        printf("Array buku sudah penuh!\n");
        free(judul);
        return;
    }
    
    if (jumlah < 1) {
        printf("Stock tidak memenuhi persyaratan, buku tidak dibuat\n");
        free(judul);
        return;
    }
    
    int i = 0;
    while (i < *count) {
        if (strcmp(buku[i].info, judul) == 0) {
            printf("Buku dengan judul yang sama sudah ada!\n");
            free(judul);
            return;
        }
        i++;
    }
    
    // Add the new book
    buku[*count].info = judul;
    buku[*count].stock = jumlah;
    createinitQueueArray(&(buku[*count].Q));
    (*count)++;
    printf("Buku berhasil ditambahkan!\n");
}

void displayBukuArray(Bukuarray buku[], int count) {
    if (count == 0) {
        printf("Tidak ada buku\n");
        return;
    }
    
    int i = 0;
    while (i < count) {
        int queueLength = 0;
        addressarray waitlistHead = buku[i].Q.head;
        
        printf("Buku: %s (Tersedia: %d)\n", buku[i].info, buku[i].stock);
        
        if (waitlistHead != NULL) {
            printf("  Antrian Peminjam:\n");
            while (waitlistHead != NULL) {
                printf("  - %s (Prioritas: %d)\n", waitlistHead->info, waitlistHead->level);
                waitlistHead = waitlistHead->next;
                queueLength++;
            }
            printf("  Total dalam antrian: %d\n", queueLength);
        } else {
            printf("  Tidak ada antrian peminjam\n");
        }
        
        printf("\n");
        i++;
    }
}

void freeBukuArray(Bukuarray buku[], int count) {
    int i = 0;
    while (i < count) {
        free(buku[i].info);
        DeAlokasiArray(&(buku[i].Q.head));
        i++;
    }
}