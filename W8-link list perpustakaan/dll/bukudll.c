#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bukudll.h"

void initBukudll(addrBukudll *B) {
    *B = NULL;
}

addrBukudll createBukudll(char *judul, int jumlah) {
    addrBukudll newBuku = (addrBukudll)malloc(sizeof(Bukudll));
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
    createinitQueuedll(&(newBuku->Q));
    newBuku->next = NULL;
    
    return newBuku;
}

void addBukudll(addrBukudll *head, char *judul, int jumlah) {
    if (jumlah <1){
        printf ("stock tidak memenuhi persyaratan, buku tidak dibuat");
        return;
    }
    
    addrBukudll newBuku = createBukudll(judul, jumlah);
    
    if (newBuku == NULL) {
        return;
    }
    
    if (*head == NULL) {
        *head = newBuku;
    } else {
        addrBukudll temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBuku;
    }
}

addrBukudll findBukudll(addrBukudll head, char *judul) {
    addrBukudll temp = head;
    while (temp != NULL) {
        if (strcmp(temp->info, judul) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void displayBukudll(addrBukudll head) {
    if (head == NULL) {
        printf("Tidak ada buku\n");
        return;
    }
    
    addrBukudll temp = head;
    while (temp != NULL) {
        int queueLength = 0;
        addressdll waitlistHead = temp->Q.head;
        while (waitlistHead != NULL) {
            queueLength++;
            waitlistHead = waitlistHead->next;
        }
        
        printf("Buku: %s (Tersedia: %d, Antrian: %d)\n", 
               temp->info, temp->stock, queueLength);
        temp = temp->next;
    }
}

void displayBukuanggotadll(addrBukudll head) {
    if (head == NULL) {
        printf("Tidak ada buku\n");
        return;
    }
    
    addrBukudll temp = head;
    while (temp != NULL) {
        int queueLength = 0;
        addressdll waitlistHead = temp->Q.head;
        
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

void prosesbukudll(addrBukudll head, addressdll *allAnggota) {
    if (head == NULL) {
        printf("Buku tidak ditemukan\n");
        return;
    }
    
    if (isEmptydll(head->Q.head)) {
        printf("Tidak ada anggota dalam antrian peminjaman\n");
        return;
    }
    
    if (head->stock > 0) {
        infotype info;
        addressdll peminjam = head->Q.head;
        dequeuedll(&head->Q, &info);
        printf("Buku \"%s\" berhasil dipinjam oleh: %s\n", head->info, info);
        head->stock--;

        addressdll found = Searchdll(*allAnggota, info);
        if (found == NULL) {
            addressdll newNode = SetNodedll(&info, peminjam->level);
            Ins_Akhirdll(allAnggota, newNode);
            found=newNode;
        }

        addHistorydll(found, head->info, 'b', 's', head);
    } else {
        printf("Stock buku \"%s\" sedang kosong\n", head->info);

        if (!isEmptydll(head->Q.head)) {
            addressdll peminjam = head->Q.head;
            addressdll found = Searchdll(*allAnggota, peminjam->info);
            if (found != NULL) {
                addHistorydll(found, head->info, 'b', 'f', head);
            }
        }
    }
}

void freeBukudll(addrBukudll *head) {
    addrBukudll temp;
    
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        
        DeAlokasidll(&(temp->Q.head));
        free(temp);
    }
}

void returnBukudll(addrBukudll head, infotype peminjam, addressdll *allAnggota) {
    if (head == NULL) {
        printf("Buku tidak ditemukan\n");
        return;
    }
    
    head->stock++;
    
    printf("Buku \"%s\" telah dikembalikan oleh: %s\n", head->info, peminjam);
    printf("Stock buku \"%s\" sekarang: %d\n", head->info, head->stock);

    addressdll found = Searchdll(*allAnggota, peminjam);
    if (found == NULL) {
        infotype peminjamCopy = strdup(peminjam);
        addressdll newNode = SetNodedll(&peminjamCopy, 3);
        Ins_Akhirdll(allAnggota, newNode);
        found = newNode;
    }

    addHistorydll(found, head->info, 'r', 's', head);
    
    // Jika ada antrian dan stok sudah ada, berikan informasi tentang peminjam berikutnya
    if (!isEmptydll(head->Q.head) && head->stock > 0) {
        printf("Peminjam berikutnya untuk buku \"%s\" adalah: %s (Prioritas: %d)\n", 
               head->info, head->Q.head->info, head->Q.head->level);
    }
}

// addrBukudll findNextAvailableBukudll(addrBukudll head) {
//     addrBukudll temp = head;
//     while (temp != NULL) {
//         if (temp->stock > 0 && !isEmptydll(temp->headQueue)) {
//             return temp;
//         }
//         temp = temp->next;
//     }
//     return NULL;
// }