#include "driver.h"

void otomatisdll(addrBuku *daftarBuku, address *allAnggota) {

    addBuku(daftarBuku, "Buku1", 1);
    addBuku(daftarBuku, "Buku2", 1);
    
    printf("Daftar Buku:\n");
    displayBuku(*daftarBuku);
    printf("\n");
    
    addrBuku buku1 = findBuku(*daftarBuku, "Buku1");
    addrBuku buku2 = findBuku(*daftarBuku, "Buku2");
    
    char *anggota1 = strdup("anggota1");
    address node1 = SetNode(&anggota1, mahasiswa);
    enqueue(&buku1->Q, node1);
    
    char *dosen1 = strdup("dosen1");
    address node2 = SetNode(&dosen1, dosen);
    enqueue(&buku1->Q, node2);
    
    char *umum1 = strdup("umum1");
    address node3 = SetNode(&umum1, umum);
    enqueue(&buku1->Q, node3);
    
    printf("Daftar anggota pada antrian Buku1:\n");
    displayBukuanggota(buku1);
    printf("\n");
    
    char *umum1_buku2 = strdup("Umum1");
    address nodeUmum2 = SetNode(&umum1_buku2, 3);
    enqueue(&buku2->Q, nodeUmum2);

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
    printf("Sebelum pengembalian (stock: %d):\n", buku1->stock);
    displayBukuanggota(buku1);
    
    returnBuku(buku1, "Dosen1", allAnggota);
    
    printf("\nSetelah pengembalian:\n");
    displayBukuanggota(buku1);
    printf("Anggota1 sekarang yang memiliki prioritas tertinggi dalam antrean\n\n");
    
    printf("=== SKENARIO H: Pembatalan Peminjaman oleh Umum1 di Buku2 ===\n");
    printf("Sebelum pembatalan:\n");
    displayBukuanggota(buku2);
}