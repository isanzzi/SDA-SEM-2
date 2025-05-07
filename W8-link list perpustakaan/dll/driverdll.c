#include "driverdll.h"

void otomatisdll(addrBukudll *daftarBuku, addressdll *allAnggota) {

    addBukudll(daftarBuku, "Buku1", 1);
    addBukudll(daftarBuku, "Buku2", 1);
    
    printf("Daftar Buku:\n");
    displayBukudll(*daftarBuku);
    printf("\n");
    
    addrBukudll buku1 = findBukudll(*daftarBuku, "Buku1");
    addrBukudll buku2 = findBukudll(*daftarBuku, "Buku2");
    
    char *anggota1 = strdup("anggota1");
    addressdll node1 = SetNodedll(&anggota1, mahasiswa);
    enqueuedll(&buku1->Q, node1);
    
    char *dosen1 = strdup("dosen1");
    addressdll node2 = SetNodedll(&dosen1, dosen);
    enqueuedll(&buku1->Q, node2);
    
    char *umum1 = strdup("umum1");
    addressdll node3 = SetNodedll(&umum1, umum);
    enqueuedll(&buku1->Q, node3);
    
    printf("Daftar anggota pada antrian Buku1:\n");
    displayBukuanggotadll(buku1);
    printf("\n");
    
    char *umum1_buku2 = strdup("Umum1");
    addressdll nodeUmum2 = SetNodedll(&umum1_buku2, 3);
    enqueuedll(&buku2->Q, nodeUmum2);

    printf("Daftar anggota pada antrian Buku2:\n");
    displayBukuanggotadll(buku2);
    printf("\n");

    printf("=== Scenario F: Processing Buku1 Borrowing ===\n");
    printf("Sebelum peminjaman:\n");
    displayBukuanggotadll(buku1);

    printf("\nProses peminjaman berjalan:\n");
    prosesbukudll(buku1, allAnggota);
    
    printf("\nSetelah peminjaman:\n");
    displayBukuanggotadll(buku1);
    
    printf("\n=== SKENARIO G: Pengembalian Buku1 oleh Dosen1 ===\n");
    printf("Sebelum pengembalian (stock: %d):\n", buku1->stock);
    displayBukuanggotadll(buku1);
    
    returnBukudll(buku1, "Dosen1", allAnggota);
    
    printf("\nSetelah pengembalian:\n");
    displayBukuanggotadll(buku1);
    printf("Anggota1 sekarang yang memiliki prioritas tertinggi dalam antrean\n\n");
    
    printf("=== SKENARIO H: Pembatalan Peminjaman oleh Umum1 di Buku2 ===\n");
    printf("Sebelum pembatalan:\n");
    displayBukuanggotadll(buku2);
}