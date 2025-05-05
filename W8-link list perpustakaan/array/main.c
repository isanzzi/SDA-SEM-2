#include "convention.h"
#include "buku.h"
#include "linked.h"
#include "history.h"
#include "queue.h"
#include "stack.h"

addrBuku headbuku = NULL;
address allanggota = NULL;
int bukuCount = 0;

void otomatisarray(Buku buku[], address *allAnggota, int *pBukuCount, int maxBuku);

char* insertTitle() {
    return InsertTitle();
}

int initstock() {
    int stock;
    printf("Input stock: ");
    scanf("%d", &stock);
    getchar();
    return stock;
}

void mainarray(Buku buku[], int maxbuku) {
    printf("apakah anda ingin otomatis mengisi test case? (y/n)\nMasukkan jawaban anda : ");
    char otomatis;
    scanf(" %c", &otomatis);
    getchar();
    
    if (otomatis=='y'){
        printf("Menjalankan test case otomatis...\n");
        otomatisarray(buku, &allanggota, &bukuCount, maxbuku);
        
        printf("\nApakah Anda ingin melanjutkan dengan data dari test case? (y/n)\nMasukkan jawaban anda : ");
        char lanjutData;
        scanf("%c", &lanjutData);
        getchar();
        
        if (lanjutData == 'n') {
            // hapus test case
            int i = 0;
            while (i < bukuCount) {
                if (buku[i].info != NULL) {
                    free(buku[i].info);
                    buku[i].info = NULL;
                }
                buku[i].stock = 0;
                DeAlokasi(&(buku[i].Q.head));
                createinitQueue(&buku[i].Q);
                i++;
            }
            
            // Reset bukuCount
            bukuCount = 0;
            
            // Reset members list
            address temp;
            while (allanggota != NULL) {
                temp = allanggota;
                allanggota = allanggota->next;
                freeHistory(&temp->history);
                free(temp);
            }
            allanggota = NULL;
            
            printf("Data telah direset.\n");
        }
    }

    boolean lanjut=true;
    while (lanjut == true){
        printf("\n===== MENU PERPUSTAKAAN =====\n");
        printf("1. Tambah buku\n");
        printf("2. Tambah anggota\n");
        printf("3. Pesan buku\n");
        printf("4. Proses buku\n");
        printf("5. Kembalikan buku\n");
        printf("6. Lihat daftar buku\n");
        printf("7. Lihat daftar anggota\n");
        printf("8. Batalkan pemesanan buku\n");
        printf("9. Lihat riwayat anggota\n");
        printf("10. Keluar\n");
        printf("Masukkan pilihan: ");
        
        int input1;
        if (scanf("%d", &input1) != 1) {
            // Clear input buffer
            while (getchar() != '\n');
            printf("\nInput tidak valid. Masukkan angka 1-10.\n");
            continue;
        }
        getchar(); // Clear newline after number

        switch (input1){
            case 1: {
                char* title = insertTitle();
                int stock = initstock();
                addBukuArray(buku, title, stock, &bukuCount, maxbuku);
                break;
            }
            case 2: {
                char* newName = insertNama();

                // cek apakah nama sudah ada
                address existingMember = Search(allanggota, newName);
                if (existingMember != NULL) {
                    printf("Anggota dengan nama '%s' sudah terdaftar (level: %d).\n", 
                           newName, existingMember->level);
                    free(newName); // Free nama tadi jika sudah ada
                    break;
                }
                
                // jika nama belum ada
                address newAnggota = SetNode(&newName, initlevel());
                if (allanggota == NULL) {
                    allanggota = newAnggota;
                } else {
                    Ins_Awal(&allanggota, newAnggota);
                }
                
                printf("Anggota berhasil ditambahkan!\n");
                break;
            }
            
            case 3: {
                char* title = insertTitle();
                addrBuku bukuDipesan = findBukuArray(buku, title, bukuCount);
                free(title); // setelah ditemukan free
                
                if (bukuDipesan == NULL) {
                    printf("Buku tidak ditemukan!\n");
                    break;
                }
                
                char* peminjamName = insertNama();
                address nodePeminjam = NULL;
                
                // cek apakah member sudah ada
                nodePeminjam = Search(allanggota, peminjamName);
                
                if (nodePeminjam == NULL) { // jika member belum ada
                    printf("Anggota baru, ");
                    int level = initlevel();
                    char* peminjamCopy = strdup(peminjamName);
                    nodePeminjam = SetNode(&peminjamCopy, level);
                    
                    // tambahkan ke list allanggota
                    Ins_Awal(&allanggota, nodePeminjam);
                    printf("Anggota baru telah ditambahkan ke sistem.\n");
                } else {
                    printf("Menggunakan data anggota yang sudah ada (level: %d).\n", nodePeminjam->level);
                }
                
                free(peminjamName);
                
                // bikin queue
                address queueNode = SetNode(&(nodePeminjam->info), nodePeminjam->level);
                
                //tambah member di queue
                enqueue(&bukuDipesan->Q, queueNode);
                
                // update history
                addHistory(nodePeminjam, bukuDipesan->info, 'c', 's', bukuDipesan);
                
                printf("Pemesanan berhasil ditambahkan ke antrian!\n");
                break;
            }
            
            case 4: {
                char* title = insertTitle();
                addrBuku bukuDiproses = findBukuArray(buku, title, bukuCount);
                free(title);
                
                if (bukuDiproses == NULL) {
                    printf("Buku tidak ditemukan!\n");
                    break;
                }
                
                if (bukuDiproses->stock > 0 && !isEmpty(bukuDiproses->Q.head)) {
                    infotype info;
                    address peminjam = bukuDiproses->Q.head;
                    dequeue(&bukuDiproses->Q, &info);
                    printf("Buku \"%s\" berhasil dipinjam oleh: %s\n", bukuDiproses->info, info);
                    bukuDiproses->stock--;

                    address found = Search(allanggota, info);
                    if (found == NULL) {
                        address newNode = SetNode(&info, peminjam->level);
                        Ins_Akhir(&allanggota, newNode);
                        found = newNode;
                    }

                    addHistory(found, bukuDiproses->info, 'b', 's', bukuDiproses);
                } else if (bukuDiproses->stock <= 0) {
                    printf("Stock buku \"%s\" sedang kosong\n", bukuDiproses->info);

                    if (!isEmpty(bukuDiproses->Q.head)) {
                        address peminjam = bukuDiproses->Q.head;
                        address found = Search(allanggota, peminjam->info);
                        if (found != NULL) {
                            addHistory(found, bukuDiproses->info, 'b', 'f', bukuDiproses);
                        }
                    }
                } else {
                    printf("Tidak ada anggota dalam antrian peminjaman\n");
                }
                break;
            }
            
            case 5: {
                char* title = insertTitle();
                addrBuku bukuDikembalikan = findBukuArray(buku, title, bukuCount);
                free(title);
                
                if (bukuDikembalikan == NULL) {
                    printf("Buku tidak ditemukan!\n");
                    break;
                }
                
                char* peminjam = insertNama();
                bukuDikembalikan->stock++;
                
                printf("Buku \"%s\" telah dikembalikan oleh: %s\n", bukuDikembalikan->info, peminjam);
                printf("Stock buku \"%s\" sekarang: %d\n", bukuDikembalikan->info, bukuDikembalikan->stock);

                address found = Search(allanggota, peminjam);
                if (found == NULL) {
                    char* peminjamCopy = strdup(peminjam);
                    address newNode = SetNode(&peminjamCopy, 3);
                    Ins_Akhir(&allanggota, newNode);
                    found = newNode;
                }

                addHistory(found, bukuDikembalikan->info, 'r', 's', bukuDikembalikan);
                free(peminjam);
                
                // If there are members in queue and stock is available
                if (!isEmpty(bukuDikembalikan->Q.head) && bukuDikembalikan->stock > 0) {
                    printf("Peminjam berikutnya untuk buku \"%s\" adalah: %s (Prioritas: %d)\n", 
                           bukuDikembalikan->info, bukuDikembalikan->Q.head->info, bukuDikembalikan->Q.head->level);
                }
                break;
            }
            
            case 6:
                printf("\n=== DAFTAR BUKU ===\n");
                displayBukuArray(buku, bukuCount);
                break;
            
            case 7:
                printf("\n=== DAFTAR ANGGOTA ===\n");
                if (allanggota == NULL) {
                    printf("Tidak ada anggota terdaftar\n");
                } else {
                    Tampil_List(allanggota);
                }
                break;
            
            case 8: {
                char* title = insertTitle();
                addrBuku bukuTemp = findBukuArray(buku, title, bukuCount);
                free(title);
                
                if (bukuTemp == NULL) {
                    printf("Buku tidak ditemukan!\n");
                    break;
                }
                    
                char* canceledName = insertNama();
                infotype canceledInfo;
                    
                if (DeleteValue(&bukuTemp->Q.head, canceledName, &canceledInfo)) {
                    // cari di allanggota atau buat ulang
                    address found = Search(allanggota, canceledName);
                    if (found == NULL) {
                        address newAnggota = SetNode(&canceledName, 3);
                        Ins_Akhir(&allanggota, newAnggota);
                        found = newAnggota;
                    } else {
                        free(canceledName);
                    }
                        
                    // update history
                    addHistory(found, bukuTemp->info, 'c', 's', bukuTemp);
                        
                    printf("Pemesanan oleh %s dibatalkan dan catatan disimpan.\n", canceledInfo);
                } else {
                    printf("Peminjam tidak ditemukan dalam antrian buku ini.\n");
                    free(canceledName);
                }
                break;
            }
            
            case 9: {
                char* nama = insertNama();
                address member = Search(allanggota, nama);
                if (member == NULL) {
                    printf("Anggota dengan nama %s tidak ditemukan.\n", nama);
                } else {
                    displayHistory(member);
                }
                free(nama);
                break;
            }
            
            case 10:{
                printf("\nTerima kasih telah menggunakan sistem perpustakaan!\n");
                lanjut = false;
                break;
            }
                
            default:{
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
                break;
            }
        }
    }
    
    freeBukuArray(buku, bukuCount);

    address temp;
    while (allanggota != NULL) {
        temp = allanggota;
        allanggota = allanggota->next;
        freeHistory(&temp->history);
        free(temp);
    }
}

int main() {
    int maxbuku;
    printf("maxbuku minimal 3\nMasukkan maxbuku : ");
    scanf("%d", &maxbuku);
    if (maxbuku < 3) {
        printf("Jumlah buku terlalu sedikit. Program berakhir.\n");
        return -1;
    }
    
    Buku buku[maxbuku];
    
    int i = 0;
    while (i < maxbuku) {
        buku[i].info = NULL;
        buku[i].stock = 0;
        createinitQueue(&buku[i].Q);
        i++;
    }
    
    printf("===== SISTEM PERPUSTAKAAN =====\n");
    bukuCount = 0;
    mainarray(buku, maxbuku);
    return 0;
}

void otomatisarray(Buku buku[], address *allAnggota, int *pBukuCount, int maxBuku) {
    printf("\n==== MENJALANKAN TEST CASE OTOMATIS ====\n");
    fflush(stdout);
    
    printf("Step 1: Menambahkan buku test case...\n");
    fflush(stdout);
    
    char *title1 = strdup("Buku1");
    char *title2 = strdup("Buku2");
    addBukuArray(buku, title1, 1, pBukuCount, maxBuku);
    addBukuArray(buku, title2, 1, pBukuCount, maxBuku);
    
    printf("\nDaftar Buku setelah penambahan:\n");
    fflush(stdout);
    displayBukuArray(buku, *pBukuCount);
    
    printf("\nStep 2: Menambahkan anggota ke antrian...\n");
    
    addrBuku buku1 = findBukuArray(buku, "Buku1", *pBukuCount);
    addrBuku buku2 = findBukuArray(buku, "Buku2", *pBukuCount);
    
    if (buku1 == NULL || buku2 == NULL) {
        printf("Error: Buku tidak ditemukan!\n");
        return;
    }
    
    printf("- Menambahkan anggota1 (Mahasiswa) ke antrian Buku1\n");
    char *anggota1 = strdup("anggota1");
    address node1 = SetNode(&anggota1, mahasiswa);
    enqueue(&buku1->Q, node1);
    
    printf("- Menambahkan dosen1 (Dosen) ke antrian Buku1\n");
    char *dosen1 = strdup("dosen1");
    address node2 = SetNode(&dosen1, dosen);
    enqueue(&buku1->Q, node2);
    
    printf("- Menambahkan umum1 (Umum) ke antrian Buku1\n");
    char *umum1 = strdup("umum1");
    address node3 = SetNode(&umum1, umum);
    enqueue(&buku1->Q, node3);
    
    printf("\nDaftar anggota pada antrian Buku1:\n");
    displayBukuArray(buku, *pBukuCount);
    
    printf("\n- Menambahkan Umum1 (Umum) ke antrian Buku2\n");
    char *umum1_buku2 = strdup("Umum1");
    address nodeUmum2 = SetNode(&umum1_buku2, 3);
    enqueue(&buku2->Q, nodeUmum2);

    printf("\nDaftar anggota pada antrian Buku2:\n");
    displayBukuArray(buku, *pBukuCount);
    
    printf("\n=== SKENARIO F: Memproses Peminjaman Buku1 ===\n");
    printf("Sebelum peminjaman:\n");
    displayBukuArray(buku, *pBukuCount);

    printf("\nProses peminjaman berjalan:\n");
    // Process book
    if (buku1->stock > 0 && !isEmpty(buku1->Q.head)) {
        infotype info;
        address peminjam = buku1->Q.head;
        dequeue(&buku1->Q, &info);
        printf("Buku \"%s\" berhasil dipinjam oleh: %s\n", buku1->info, info);
        buku1->stock--;

        address found = Search(*allAnggota, info);
        if (found == NULL) {
            address newNode = SetNode(&info, peminjam->level);
            Ins_Akhir(allAnggota, newNode);
            found = newNode;
            printf("- Anggota %s ditambahkan ke daftar global\n", info);
        }

        addHistory(found, buku1->info, 'b', 's', buku1);
        printf("- Riwayat peminjaman dicatat\n");
    } else {
        printf("Stock buku \"%s\" sedang kosong atau tidak ada anggota dalam antrian\n", buku1->info);
    }
    
    printf("\nSetelah peminjaman:\n");
    displayBukuArray(buku, *pBukuCount);
    
    printf("\n=== SKENARIO G: Pengembalian Buku1 oleh Dosen1 ===\n");
    printf("Sebelum pengembalian (stock: %d):\n", buku1->stock);
    displayBukuArray(buku, *pBukuCount);
    
    // Process book return
    buku1->stock++;
    printf("Buku \"%s\" telah dikembalikan oleh: %s\n", buku1->info, "Dosen1");
    printf("Stock buku \"%s\" sekarang: %d\n", buku1->info, buku1->stock);

    address found = Search(*allAnggota, "Dosen1");
    if (found == NULL) {
        char *peminjamCopy = strdup("Dosen1");
        address newNode = SetNode(&peminjamCopy, 3);
        Ins_Akhir(allAnggota, newNode);
        found = newNode;
        printf("- Anggota Dosen1 ditambahkan ke daftar global\n");
    }

    addHistory(found, buku1->info, 'r', 's', buku1);
    printf("- Riwayat pengembalian dicatat\n");
    
    if (!isEmpty(buku1->Q.head) && buku1->stock > 0) {
        printf("Peminjam berikutnya untuk buku \"%s\" adalah: %s (Prioritas: %d)\n", 
               buku1->info, buku1->Q.head->info, buku1->Q.head->level);
    }
    
    printf("\nSetelah pengembalian:\n");
    displayBukuArray(buku, *pBukuCount);
    printf("Anggota1 sekarang yang memiliki prioritas tertinggi dalam antrean\n\n");
    
    printf("=== SKENARIO H: Pembatalan Peminjaman oleh Umum1 di Buku2 ===\n");
    printf("Sebelum pembatalan:\n");
    displayBukuArray(buku, *pBukuCount);
    
    infotype canceledInfo;
    if (DeleteValue(&buku2->Q.head, "Umum1", &canceledInfo)) {
        printf("Pemesanan oleh %s dibatalkan.\n", canceledInfo);
        
        found = Search(*allAnggota, canceledInfo);
        if (found == NULL) {
            char *canceledCopy = strdup(canceledInfo);
            address newNode = SetNode(&canceledCopy, 3);
            Ins_Akhir(allAnggota, newNode);
            found = newNode;
            printf("- Anggota Umum1 ditambahkan ke daftar global\n");
        }
        
        addHistory(found, buku2->info, 'c', 's', buku2);
        printf("- Riwayat pembatalan dicatat\n");
    } else {
        printf("Peminjam tidak ditemukan dalam antrian.\n");
    }
    
    printf("\nSetelah pembatalan:\n");
    displayBukuArray(buku, *pBukuCount);
    
    printf("\n==== TEST CASE OTOMATIS SELESAI ====\n");
    fflush(stdout); // Ensure all output is displayed before continuing
    
    // Pause to let the user see the results
    printf("\nTekan Enter untuk melanjutkan ke menu...");
    getchar();
}