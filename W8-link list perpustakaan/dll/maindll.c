#include "convention.h"
#include "driver.h"
#include "buku.h"
#include "linked.h"
#include "history.h"

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

void maindll() {
	addrBuku headbuku=NULL;
	address allanggota=NULL;
	initBuku(&headbuku);
    printf("apakah anda ingin otomatis mengisi test case? (y/n)\nMasukkan jawaban anda : ");
    char otomatis;
    scanf("%c", &otomatis);
	getchar();
    if (otomatis=='y'){
        otomatisdll(&headbuku, &allanggota); // Pass addresses agar bisa lanjut kalau mau lanjut
        printf("Apakah Anda ingin melanjutkan dengan data dari test case? (y/n)\nMasukkan jawaban anda : ");
        char reset;
        scanf("%c", &reset);
        getchar();
        if (reset=='y'){
            address temp;
            while (allanggota != NULL) {
                temp = allanggota;
                allanggota = allanggota->next;
                freeHistory(&temp->history);
                free(temp);
            }
            allanggota = NULL;
        }
        if (reset == 'n') {
            return;
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
        getchar();

		switch (input1){
			case 1:
				addBuku(&headbuku, insertTitle(), initstock());
				break;
            case 2: {
                char* newName = insertNama();
                
                // Check if member already exists
                address existingMember = Search(allanggota, newName);
                if (existingMember != NULL) {
                    printf("Anggota dengan nama '%s' sudah terdaftar (level: %d).\n", 
                           newName, existingMember->level);
                    free(newName); // Free the name jika sudah ada
                    break;
                }
                
                // If not found, bikin baru
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
    addrBuku bukuDipesan = findBuku(headbuku, insertTitle());
    if (bukuDipesan == NULL) {
        printf("Buku tidak ditemukan!\n");
        break;
    }
    
    char* peminjamName = insertNama();
    address nodePeminjam = NULL;
    
    // cek jika anggota sudah pernah ada
    nodePeminjam = Search(allanggota, peminjamName);
    
    if (nodePeminjam == NULL) { // jika member tidak ditemukan
        printf("Anggota baru, ");
        int level = initlevel();
        char* peminjamCopy = strdup(peminjamName);
        nodePeminjam = SetNode(&peminjamCopy, level);
        
        // Add to the global member list yaitu allanggota
        Ins_Awal(&allanggota, nodePeminjam);
        printf("Anggota baru telah ditambahkan ke sistem.\n");
    } else {
        printf("Menggunakan data anggota yang sudah ada (level: %d).\n", nodePeminjam->level);
    }
    
    free(peminjamName);
    
    // Instead of creating a completely new node, just add the member's reference to the queue
    address queueNode = SetNode(&(nodePeminjam->info), nodePeminjam->level);
    
    // Add the member to the book's queue
    enqueue(&bukuDipesan->Q, queueNode);
    
    // Add this booking to the member's history
    addHistory(nodePeminjam, bukuDipesan->info, 'c', 's', bukuDipesan);
    
    printf("Pemesanan berhasil ditambahkan ke antrian!\n");
    break;
}
			
			case 4: {
				addrBuku bukuDiproses = findBuku(headbuku, insertTitle());
				if (bukuDiproses == NULL) {
					printf("Buku tidak ditemukan!\n");
					break;
				}
				prosesbuku(bukuDiproses, &allanggota);
				break;
			}
			
			case 5: {
				addrBuku bukuDikembalikan = findBuku(headbuku, insertTitle());
				if (bukuDikembalikan == NULL) {
					printf("Buku tidak ditemukan!\n");
					break;
				}

				returnBuku(bukuDikembalikan, insertNama(), &allanggota);
				break;
			}
			
			case 6:
				printf("\n=== DAFTAR BUKU ===\n");
				displayBukuanggota(headbuku);
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
				addrBuku buku = findBuku(headbuku, insertTitle());
				if (buku == NULL) {
					printf("Buku tidak ditemukan!\n");
					break;
				}
					
				char* canceledName = insertNama();
				infotype canceledInfo;
					
				if (DeleteValue(&buku->Q.head, canceledName, &canceledInfo)) {
					//cek apakah yg mau di delete ada di allanggota
					address found = Search(allanggota, canceledName);
					if (found == NULL) {
						address newAnggota = SetNode(&canceledName, 3);
						Ins_Akhir(&allanggota, newAnggota);
						found = newAnggota;
					}
						
					// Add cancellation to history
					addHistory(found, buku->info, 'c', 's', buku);
						
					printf("Pemesanan oleh %s dibatalkan dan catatan disimpan.\n", canceledName);
				} else {
					printf("Peminjam tidak ditemukan dalam antrian buku ini.\n");
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
    
    freeBuku(&headbuku);
    headbuku = NULL;
    address temp;
    while (allanggota != NULL) {
        temp = allanggota;
        allanggota = allanggota->next;
        freeHistory(&temp->history);
        free(temp);
    }
    allanggota = NULL;
}
