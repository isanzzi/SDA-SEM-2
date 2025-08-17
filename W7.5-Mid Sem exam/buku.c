#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buku.h"

void initBuku(addrBuku *B) {
    *B = NULL;
}

addrBuku createBuku(char *judul, int jumlah) {
    addrBuku newBuku = (addrBuku)malloc(sizeof(Buku));
    if (newBuku == NULL) {
        return NULL;
    }
    
    strcpy(newBuku->info, judul);
    newBuku->jml = jumlah;
    newBuku->headQueue = NULL;
    newBuku->next = NULL;
    
    return newBuku;
}

void addBuku(addrBuku *head, char *judul, int jumlah) {
    addrBuku newBuku = createBuku(judul, jumlah);
    
    if (newBuku == NULL) {
        return;
    }
    
    if (*head == NULL) {
        *head = newBuku;
    } else {
        addrBuku temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBuku;
    }
}

addrBuku findBuku(addrBuku head, char *judul) {
    addrBuku temp = head;
    while (temp != NULL) {
        if (strcmp(temp->info, judul) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void displayBuku(addrBuku head) {
    if (head == NULL) {
        printf("Tidak ada buku\n");
        return;
    }
    
    addrBuku temp = head;
    while (temp != NULL) {
        int queueLength = 0;
        address waitlistHead = temp->headQueue;
        while (waitlistHead != NULL) {
            queueLength++;
            waitlistHead = waitlistHead->next;
        }
        
        printf("Buku: %s (Tersedia: %d, Antrian: %d)\n", 
               temp->info, temp->jml, queueLength);
        temp = temp->next;
    }
}

addrBuku findNextAvailableBuku(addrBuku head) {
    addrBuku temp = head;
    while (temp != NULL) {
        if (temp->jml > 0 && !isEmpty(temp->headQueue)) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void freeBuku(addrBuku *head) {
    addrBuku temp;
    
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        
        DeAlokasi(&(temp->headQueue));
        free(temp);
    }
}
