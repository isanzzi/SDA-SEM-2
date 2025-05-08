#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedsll.h"
#include "stacksll.h"
#include "queuesll.h"

void showMenusll() {
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
    addrBukusll headbuku = NULL;
    addresssll allanggota = NULL;
    initPairListsll();
    int input1;
    while (1) {
        showMenusll();
        if (scanf("%d", &input1) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid. Masukkan angka 0-8.\n");
            continue;
        }
        getchar();
        
        switch (input1) {
            case 1: {
                char* judul = InsertTitlesll();
                if (judul == NULL) break;
                int stock = initStocksll();
                addBukusll(&headbuku, judul, stock);
                break;
            }
            case 2: {
                displayBukusll(headbuku);
                break;
            }
            case 3: {
                char* judul = InsertTitlesll();
                if (judul == NULL) break;
                PairBukuAnggotasll* pair = findOrCreatePairBukuAnggotaByTitlesll(judul, headbuku);
                if (pair == NULL) {
                    printf("Buku tidak ditemukan!\n");
                    free(judul);
                    break;
                }
                free(judul);
                char* nama = insertNamasll();
                if (nama == NULL) break;
                addresssll nodePeminjam = Searchsll(allanggota, nama);
                if (nodePeminjam == NULL) {
                    printf("Anggota baru, ");
                    int level = initlevelsll();
                    char* namaCopy = strdup(nama);
                    if (namaCopy == NULL) {
                        printf("Memory allocation failed\n");
                        free(nama);
                        break;
                    }
                    nodePeminjam = SetNodesll(&namaCopy, level);
                    if (nodePeminjam) {
                        Ins_Awalsll(&allanggota, nodePeminjam);
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
                    addresssll queueNode = SetNodesll(&queueInfo, nodePeminjam->priority);
                    if (queueNode) {
                        enqueuesll(&pair->Q, queueNode, pair->buku);
                        addHistorysll(nodePeminjam, pair->bookTitle, 'c', 's', pair->buku);
                        printf("Pemesanan berhasil ditambahkan!\n");
                    } else {
                        free(queueInfo);
                    }
                }
                free(nama);
                break;
            }
            case 4: {
                char* judul = InsertTitlesll();
                if (judul == NULL) break;
                PairBukuAnggotasll* pair = findOrCreatePairBukuAnggotaByTitlesll(judul, headbuku);
                if (pair == NULL) {
                    printf("Buku tidak ditemukan!\n");
                    free(judul);
                    break;
                }
                free(judul);
                prosesbukusll(pair->buku, &allanggota);
                break;
            }
            case 5: {
                char* judul = InsertTitlesll();
                if (judul == NULL) break;
                PairBukuAnggotasll* pair = findOrCreatePairBukuAnggotaByTitlesll(judul, headbuku);
                if (pair == NULL) {
                    printf("Buku tidak ditemukan!\n");
                    free(judul);
                    break;
                }
                free(judul);
                char* nama = insertNamasll();
                if (nama == NULL) break;
                returnBukusll(pair->buku, nama, &allanggota);
                free(nama);
                break;
            }
            case 6: {
                displayBukuanggotasll(headbuku);
                break;
            }
            case 7: {
                infotypesll judul = InsertTitlesll();
                addrBukusll buku = findBukusll(headbuku, judul);
                if (buku == NULL) {
                    printf("Buku tidak ditemukan\n");
                } else {
                    printf("Buku ditemukan!\n");
                    printf("Judul: %s\n", buku->info);
                    printf("Stock: %d\n", buku->priority);
                    PairBukuAnggotasll* pair = findOrCreatePairBukuAnggotaByAddrsll(buku);
                    int queueLength = pair ? NbElmtsll(pair->Q.head, pair->buku) : 0;
                    printf("Antrian peminjam:\n");
                    if (pair && pair->Q.head != NULL && queueLength > 0) {
                        addresssll current = pair->Q.head;
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
                char* nama = insertNamasll();
                if (nama == NULL) break;
                addresssll anggota = Searchsll(allanggota, nama);
                if (anggota == NULL) {
                    printf("Anggota tidak ditemukan!\n");
                    free(nama);
                    break;
                }
                displayHistorysll(anggota);
                free(nama);
                break;
            }
            case 0: {
                printf("Terima kasih telah menggunakan sistem perpustakaan.\n");
                freeBukusll(&headbuku);
                DeAlokasisll(&allanggota);
                clearAllPairssll();
                printf("\nAnda telah selesai menggunakan perpustakaan bertipe single linked list\n sekarang kembali ke menu");
                return 0;
            }
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}
