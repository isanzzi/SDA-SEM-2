#include "driver.h"
#include "linked.h"

void otomatissll(addrBuku* headbuku, address* allanggota) {
    // a) Tambah Buku1 dan Buku2 dengan stok 1
    addBuku(headbuku, "Buku1", 1);
    addBuku(headbuku, "Buku2", 1);
    printf("Setelah menambahkan buku:\n");
    displayBuku(*headbuku);

    // b) Tambah Anggota1 sebagai mahasiswa ke antrian Buku1
    char* nama = "Anggota1";
    address nodePeminjam = Search(*allanggota, nama);
    if (nodePeminjam == NULL) {
        int level = 2; // mahasiswa
        char* namaCopy = strdup(nama);
        nodePeminjam = SetNode(&namaCopy, level);
        Ins_Awal(allanggota, nodePeminjam);
    }
    PairBukuAnggota* pair = findOrCreatePairBukuAnggotaByTitle("Buku1", *headbuku);
    if (pair != NULL) {
        char* queueInfo = strdup(nodePeminjam->info);
        address queueNode = SetNode(&queueInfo, nodePeminjam->priority);
        enqueue(&pair->Q, queueNode, pair->buku);
        addHistory(nodePeminjam, pair->bookTitle, 'c', 's', pair->buku);
    }

    // c) Tambah Dosen1 sebagai dosen ke antrian Buku1
    nama = "Dosen1";
    nodePeminjam = Search(*allanggota, nama);
    if (nodePeminjam == NULL) {
        int level = 1; // dosen
        char* namaCopy = strdup(nama);
        nodePeminjam = SetNode(&namaCopy, level);
        Ins_Awal(allanggota, nodePeminjam);
    }
    pair = findOrCreatePairBukuAnggotaByTitle("Buku1", *headbuku);
    if (pair != NULL) {
        char* queueInfo = strdup(nodePeminjam->info);
        address queueNode = SetNode(&queueInfo, nodePeminjam->priority);
        enqueue(&pair->Q, queueNode, pair->buku);
        addHistory(nodePeminjam, pair->bookTitle, 'c', 's', pair->buku);
    }

    // d) Tambah Umum1 sebagai masyarakat umum ke antrian Buku1
    nama = "Umum1";
    nodePeminjam = Search(*allanggota, nama);
    if (nodePeminjam == NULL) {
        int level = 3; // umum
        char* namaCopy = strdup(nama);
        nodePeminjam = SetNode(&namaCopy, level);
        Ins_Awal(allanggota, nodePeminjam);
    }
    pair = findOrCreatePairBukuAnggotaByTitle("Buku1", *headbuku);
    if (pair != NULL) {
        char* queueInfo = strdup(nodePeminjam->info);
        address queueNode = SetNode(&queueInfo, nodePeminjam->priority);
        enqueue(&pair->Q, queueNode, pair->buku);
        addHistory(nodePeminjam, pair->bookTitle, 'c', 's', pair->buku);
    }

    // e) Tambah Umum1 sebagai masyarakat umum ke antrian Buku2
    pair = findOrCreatePairBukuAnggotaByTitle("Buku2", *headbuku);
    if (pair != NULL) {
        char* queueInfo = strdup(nodePeminjam->info);
        address queueNode = SetNode(&queueInfo, nodePeminjam->priority);
        enqueue(&pair->Q, queueNode, pair->buku);
        addHistory(nodePeminjam, pair->bookTitle, 'c', 's', pair->buku);
    }

    printf("Setelah menambahkan anggota ke antrian:\n");
    displayBukuanggota(*headbuku);

    // f) Proses peminjaman Buku1 - Dosen1 diprioritaskan
    pair = findOrCreatePairBukuAnggotaByTitle("Buku1", *headbuku);
    if (pair != NULL) {
        prosesbuku(pair->buku, allanggota); // Dosen1 (prioritas 1) akan diproses
    }
    printf("Setelah proses peminjaman Buku1 (Dosen1 meminjam):\n");
    displayBukuanggota(*headbuku);

    // g) Proses pengembalian Buku1 oleh Dosen1
    pair = findOrCreatePairBukuAnggotaByTitle("Buku1", *headbuku);
    if (pair != NULL) {
        returnBuku(pair->buku, "Dosen1", allanggota);
    }
    printf("Setelah pengembalian Buku1 oleh Dosen1 (Anggota1 berikutnya):\n");
    displayBukuanggota(*headbuku);

    // h) Batalkan peminjaman Umum1 untuk Buku2
    pair = findOrCreatePairBukuAnggotaByTitle("Buku2", *headbuku);
    if (pair != NULL) {
        address current = pair->Q.head;
        address prev = NULL;
        while (current != NULL && current != pair->buku) {
            if (strcmp(current->info, "Umum1") == 0) {
                if (prev == NULL) {
                    pair->Q.head = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current->info);
                free(current);
                break;
            }
            prev = current;
            current = current->next;
        }
    }
    printf("Setelah pembatalan peminjaman Umum1 untuk Buku2:\n");
    displayBukuanggota(*headbuku);
}