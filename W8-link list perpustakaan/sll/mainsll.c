#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"
#include "stack.h"
#include "queue.h"
#include "driver.h"

void showMenu() {
    printf("\n===== SISTEM PERPUSTAKAAN =====\n");
    printf("1. Tambah Buku\n");
    printf("2. Tampilkan Semua Buku\n");
    printf("3. Tambah Anggota ke Antrian Buku\n");
    printf("4. Proses Peminjaman Buku\n");
    printf("5. Kembalikan Buku\n");
    printf("6. Tampilkan Detail Buku dan Antriannya\n");
    printf("7. Cari Buku\n");
    printf("8. Tampilkan Riwayat Anggota\n");
    printf("0. Keluar\n");
    printf("Pilihan Anda: ");
}

int mainsll() {
    addrBuku headbuku = NULL;
    address allanggota = NULL;
    initPairList();

    printf("Apakah anda ingin otomatis mengisi test case? (y/n)\nMasukkan jawaban anda: ");
    char otomatis;
    scanf("%c", &otomatis);
    getchar();
    
    if (otomatis == 'y') {
        otomatissll(&headbuku, &allanggota);
        printf("Apakah anda ingin mereset ulang semua buku? (y/n)\nMasukkan jawaban anda: ");
        char reset;
        scanf("%c", &reset);
        getchar();
        if (reset == 'y') {
            freeBuku(&headbuku);
            headbuku = NULL;
        }
    }

    int input1;
    while (1) {
        showMenu();
        if (scanf("%d", &input1) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid. Masukkan angka 0-8.\n");
            continue;
        }
        getchar();
        
        switch (input1) {
            case 1: {
                char* judul = InsertTitle();
                if (judul == NULL) break;
                int stock = initStock();
                addBuku(&headbuku, judul, stock);
                break;
            }
            case 2: {
                displayBuku(headbuku);
                break;
            }
            case 3: {
                char* judul = InsertTitle();
                if (judul == NULL) break;
                PairBukuAnggota* pair = findOrCreatePairBukuAnggotaByTitle(judul, headbuku);
                if (pair == NULL) {
                    printf("Buku tidak ditemukan!\n");
                    free(judul);
                    break;
                }
                free(judul);
                char* nama = insertNama();
                if (nama == NULL) break;
                address nodePeminjam = Search(allanggota, nama);
                if (nodePeminjam == NULL) {
                    printf("Anggota baru, ");
                    int level = initlevel();
                    char* namaCopy = strdup(nama);
                    if (namaCopy == NULL) {
                        printf("Memory allocation failed\n");
                        free(nama);
                        break;
                    }
                    nodePeminjam = SetNode(&namaCopy, level);
                    if (nodePeminjam) {
                        Ins_Awal(&allanggota, nodePeminjam);
                        printf("Anggota baru ditambahkan.\n");
                    } else {
                        free(namaCopy);
                        free(nama);
                        break;
                    }
                }
                if (nodePeminjam) {
                    char* queueInfo = strdup(nodePeminjam->info);
                    if (queueInfo == NULL) {
                        printf("Memory allocation failed\n");
                        free(nama);
                        break;
                    }
                    address queueNode = SetNode(&queueInfo, nodePeminjam->priority);
                    if (queueNode) {
                        enqueue(&pair->Q, queueNode, pair->buku);
                        addHistory(nodePeminjam, pair->bookTitle, 'c', 's', pair->buku);
                        printf("Pemesanan berhasil ditambahkan!\n");
                    } else {
                        free(queueInfo);
                    }
                }
                free(nama);
                break;
            }
            case 4: {
                char* judul = InsertTitle();
                if (judul == NULL) break;
                PairBukuAnggota* pair = findOrCreatePairBukuAnggotaByTitle(judul, headbuku);
                if (pair == NULL) {
                    printf("Buku tidak ditemukan!\n");
                    free(judul);
                    break;
                }
                free(judul);
                prosesbuku(pair->buku, &allanggota);
                break;
            }
            case 5: {
                char* judul = InsertTitle();
                if (judul == NULL) break;
                PairBukuAnggota* pair = findOrCreatePairBukuAnggotaByTitle(judul, headbuku);
                if (pair == NULL) {
                    printf("Buku tidak ditemukan!\n");
                    free(judul);
                    break;
                }
                free(judul);
                char* nama = insertNama();
                if (nama == NULL) break;
                returnBuku(pair->buku, nama, &allanggota);
                free(nama);
                break;
            }
            case 6: {
                displayBukuanggota(headbuku);
                break;
            }
            case 7: {
                infotype judul = InsertTitle();
                addrBuku buku = findBuku(headbuku, judul);
                if (buku == NULL) {
                    printf("Buku tidak ditemukan\n");
                } else {
                    printf("Buku ditemukan!\n");
                    printf("Judul: %s\n", buku->info);
                    printf("Stock: %d\n", buku->priority);
                    PairBukuAnggota* pair = findOrCreatePairBukuAnggotaByAddr(buku);
                    int queueLength = pair ? NbElmt(pair->Q.head, pair->buku) : 0;
                    printf("Antrian peminjam:\n");
                    if (pair && pair->Q.head != NULL && queueLength > 0) {
                        address current = pair->Q.head;
                        int pos = 1;
                        while (current != NULL && current != pair->buku) {
                            printf("%d. %s (Prioritas: %d)\n", pos++, current->info, current->priority);
                            current = current->next;
                        }
                    } else {
                        printf("Tidak ada antrian\n");
                    }
                }
                free(judul);
                break;
            }
            case 8: {
                char* nama = insertNama();
                if (nama == NULL) break;
                address anggota = Search(allanggota, nama);
                if (anggota == NULL) {
                    printf("Anggota tidak ditemukan!\n");
                    free(nama);
                    break;
                }
                displayHistory(anggota);
                free(nama);
                break;
            }
            case 0: {
                printf("Terima kasih telah menggunakan sistem perpustakaan.\n");
                freeBuku(&headbuku);
                DeAlokasi(&allanggota);
                clearAllPairs();
                return 0;
            }
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}

int main(){
    mainsll();
    return 0;
}