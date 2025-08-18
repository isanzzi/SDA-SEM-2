#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stack.h"
#include "buku.h"
#include <ctype.h>

int isDosen(const char *str) {
    char temp[100];
    strcpy(temp, str);
    for (int i = 0; temp[i]; i++) {
        temp[i] = tolower(temp[i]);
    }
    return (strstr(temp, "dosen") != NULL);
}

int main() {
    addrBuku daftarBuku;
    
    initBuku(&daftarBuku);
    
    addBuku(&daftarBuku, "Buku1", 1);
    addBuku(&daftarBuku, "Buku2", 1);
    
    printf("Daftar Buku:\n");
    displayBuku(daftarBuku);
    
    addrBuku buku1 = findBuku(daftarBuku, "Buku1");
    addrBuku buku2 = findBuku(daftarBuku, "Buku2");
    
    char *anggota1 = strdup("anggota1");
    address node1 = SetNode(&anggota1);
    buku1->headQueue = node1;
    
    char *dosen1 = strdup("dosen1");
    address node2 = SetNode(&dosen1);
    Ins_Akhir(&buku1->headQueue, node2);
    
    char *umum1_buku1 = strdup("umum1");
    address node3 = SetNode(&umum1_buku1);
    Ins_Akhir(&buku1->headQueue, node3);
    
    char *umum1_buku2 = strdup("umum1");
    address node4 = SetNode(&umum1_buku2);
    buku2->headQueue = node4;
    
    // Cek antrian awal di buku1
    address current = buku1->headQueue;
    printf("Antrian buku1: ");
    while (current != NULL) {
        printf("%s ", current->info);
        current = current->next;
    }
    printf("\n");
    
    // Proses peminjaman buku1
    // Cari peminjam dosen (prioritas)
    address prev = NULL;
    current = buku1->headQueue;
    address dosenNode = NULL;
    address dosenPrev = NULL;
    
    while (current != NULL) {
        if (isDosen(current->info)) {
            dosenNode = current;
            dosenPrev = prev;
            break;
        }
        prev = current;
        current = current->next;
    }
    
    // Proses peminjaman dengan prioritas dosen
    infotype nilai;
    if (dosenNode != NULL) {
        if (dosenPrev == NULL) {
            // Dosen di awal antrian
            Del_Awal(&buku1->headQueue, &nilai);
        } else {
            // Dosen di tengah antrian
            nilai = dosenNode->info;
            dosenPrev->next = dosenNode->next;
            free(dosenNode);
        }
        
        // Kurangi jumlah buku
        buku1->jml--;
        
        printf("Peminjaman berhasil: %s\n", nilai);
        free(nilai);
    }
    
    // Cek antrian setelah pemrosesan
    printf("Antrian buku1 setelah pemrosesan: ");
    current = buku1->headQueue;
    while (current != NULL) {
        printf("%s ", current->info);
        current = current->next;
    }
    printf("\n");
    
    // Verifikasi bahwa anggota1 masih di awal antrian
    if (buku1->headQueue != NULL) {
        printf("Orang pertama di antrian: %s\n", buku1->headQueue->info);
    }
    
    // Cleanup
    freeBuku(&daftarBuku);
    displayBuku(daftarBuku);
    
    return 0;
}