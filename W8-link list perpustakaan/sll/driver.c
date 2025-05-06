#include "driver.h"
#include "linked.h"

void otomatisdll(address *daftarBuku, address *allAnggota) {
    addBuku((addrBuku*)daftarBuku, strdup("Buku1"), 1);
    addBuku((addrBuku*)daftarBuku, strdup("Buku2"), 1);
    printf("Daftar Buku:\n");
    displayBuku(*(addrBuku*)daftarBuku);
    printf("\n");

    addrBuku buku1 = findBuku(*(addrBuku*)daftarBuku, "Buku1");
    addrBuku buku2 = findBuku(*(addrBuku*)daftarBuku, "Buku2");
    if (!buku1 || !buku2) {
        printf("Error: Books not found\n");
        return;
    }

    PairBukuAnggota* pair1 = findOrCreatePairBukuAnggotaByAddr(buku1);
    PairBukuAnggota* pair2 = findOrCreatePairBukuAnggotaByAddr(buku2);
    if (!pair1 || !pair2) {
        printf("Error: Failed to create pairs\n");
        return;
    }

    char *anggota1 = strdup("Anggota1");
    address node1 = SetNode(&anggota1, 2);
    if (node1) {
        enqueue(&pair1->Q, node1, buku1);
        Ins_Awal(allAnggota, node1);
    }

    char *dosen1 = strdup("Dosen1");
    address node2 = SetNode(&dosen1, 1);
    if (node2) {
        enqueue(&pair1->Q, node2, buku1);
        Ins_Awal(allAnggota, node2);
    }

    char *umum1 = strdup("Umum1");
    address node3 = SetNode(&umum1, 3);
    if (node3) {
        enqueue(&pair1->Q, node3, buku1);
        Ins_Awal(allAnggota, node3);
    }

    printf("Daftar anggota pada antrian Buku1:\n");
    displayBukuanggota(buku1);
    printf("\n");

    char *umum1_buku2 = strdup("Umum1");
    address nodeUmum2 = SetNode(&umum1_buku2, 3);
    if (nodeUmum2) {
        enqueue(&pair2->Q, nodeUmum2, buku2);
        Ins_Awal(allAnggota, nodeUmum2);
    }

    printf("Daftar anggota pada antrian Buku2:\n");
    displayBukuanggota(buku2);
    printf("\n");

    printf("=== Scenario F: Processing Buku1 Borrowing ===\n");
    printf("Sebelum peminjaman:\n");
    displayBukuanggota(buku1);
    printf("\nProses peminjaman berjalan:\n");
    prosesbuku(buku1, allAnggota);
    printf("\nSetelah peminjaman:\n");
    displayBukuanggota(buku1);

    printf("\n=== SKENARIO G: Pengembalian Buku1 oleh Dosen1 ===\n");
    printf("Sebelum pengembalian (stock: %d):\n", buku1->priority);
    displayBukuanggota(buku1);
    returnBuku(buku1, "Dosen1", allAnggota);
    printf("\nSetelah pengembalian:\n");
    displayBukuanggota(buku1);

    printf("\n=== SKENARIO H: Pembatalan Peminjaman oleh Umum1 di Buku2 ===\n");
    printf("Sebelum pembatalan:\n");
    displayBukuanggota(buku2);
    infotype canceledInfo;
    PairBukuAnggota* cancelPair = findOrCreatePairBukuAnggotaByAddr(buku2);
    if (cancelPair && DeleteValue(&cancelPair->Q.head, "Umum1", &canceledInfo)) {
        address found = Search(*allAnggota, "Umum1");
        if (found) {
            addHistory(found, buku2->info, 'c', 's', buku2);
            printf("Pemesanan oleh Umum1 dibatalkan.\n");
        }
    }
    printf("Setelah pembatalan:\n");
    displayBukuanggota(buku2);
}