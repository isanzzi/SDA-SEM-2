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
    
    newBuku->info = (char*)malloc(MAX_TITLE * sizeof(char));
    if (newBuku->info == NULL) {
        free(newBuku);
        return NULL;
    }
    
    strcpy(newBuku->info, judul);
    newBuku->stock = jumlah;
    createinitQueue(&(newBuku->Q));
    newBuku->next = NULL;
    
    return newBuku;
}

void addBuku(addrBuku *head, char *judul, int jumlah) {
    if (jumlah <1){
        printf ("stock tidak memenuhi persyaratan, buku tidak dibuat");
        return;
    }
    
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
        address waitlistHead = temp->Q.head;
        while (waitlistHead != NULL) {
            queueLength++;
            waitlistHead = waitlistHead->next;
        }
        
        printf("Buku: %s (Tersedia: %d, Antrian: %d)\n", 
               temp->info, temp->stock, queueLength);
        temp = temp->next;
    }
}

void displayBukuanggota(addrBuku head) {
    if (head == NULL) {
        printf("Tidak ada buku\n");
        return;
    }
    
    addrBuku temp = head;
    while (temp != NULL) {
        int queueLength = 0;
        address waitlistHead = temp->Q.head;
        
        printf("Buku: %s (Tersedia: %d)\n", temp->info, temp->stock);
        
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
        temp = temp->next;
    }
}

void prosesbuku(addrBuku head, address *allAnggota) {
    if (head == NULL) {
        printf("Buku tidak ditemukan\n");
        return;
    }
    
    if (isEmpty(head->Q.head)) {
        printf("Tidak ada anggota dalam antrian peminjaman\n");
        return;
    }
    
    if (head->stock > 0) {
        infotype info;
        address peminjam = head->Q.head;
        dequeue(&head->Q, &info);
        printf("Buku \"%s\" berhasil dipinjam oleh: %s\n", head->info, info);
        head->stock--;

        address found = Search(*allAnggota, info);
        if (found == NULL) {
            address newNode = SetNode(&info, peminjam->level);
            Ins_Akhir(allAnggota, newNode);
            found=newNode;
        }

        addHistory(found, head->info, 'b', 's', head);
    } else {
        printf("Stock buku \"%s\" sedang kosong\n", head->info);

        if (!isEmpty(head->Q.head)) {
            address peminjam = head->Q.head;
            address found = Search(*allAnggota, peminjam->info);
            if (found != NULL) {
                addHistory(found, head->info, 'b', 'f', head);
            }
        }
    }
}

void freeBuku(addrBuku *head) {
    addrBuku temp;
    
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        
        DeAlokasi(&(temp->Q.head));
        free(temp);
    }
}

void returnBuku(addrBuku head, infotype peminjam, address *allAnggota) {
    if (head == NULL) {
        printf("Buku tidak ditemukan\n");
        return;
    }
    
    head->stock++;
    
    printf("Buku \"%s\" telah dikembalikan oleh: %s\n", head->info, peminjam);
    printf("Stock buku \"%s\" sekarang: %d\n", head->info, head->stock);

    address found = Search(*allAnggota, peminjam);
    if (found == NULL) {
        infotype peminjamCopy = strdup(peminjam);
        address newNode = SetNode(&peminjamCopy, 3);
        Ins_Akhir(allAnggota, newNode);
        found = newNode;
    }

    addHistory(found, head->info, 'r', 's', head);
    
    // Jika ada antrian dan stok sudah ada, berikan informasi tentang peminjam berikutnya
    if (!isEmpty(head->Q.head) && head->stock > 0) {
        printf("Peminjam berikutnya untuk buku \"%s\" adalah: %s (Prioritas: %d)\n", 
               head->info, head->Q.head->info, head->Q.head->level);
    }
}

// addrBuku findNextAvailableBuku(addrBuku head) {
//     addrBuku temp = head;
//     while (temp != NULL) {
//         if (temp->stock > 0 && !isEmpty(temp->headQueue)) {
//             return temp;
//         }
//         temp = temp->next;
//     }
//     return NULL;
// }