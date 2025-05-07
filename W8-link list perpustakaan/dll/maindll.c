#include "conventiondll.h"
#include "driverdll.h"
#include "bukudll.h"
#include "linkeddll.h"
#include "historydll.h"

char* insertTitledll() {
    return InsertTitledll();
}

int initstockdll() {
    int stock;
    printf("Input stock: ");
    scanf("%d", &stock);
    getchar();
    return stock;
}

void maindll() {
	addrBukudll headbuku=NULL;
	addressdll allanggota=NULL;
	initBukudll(&headbuku);
    printf("apakah anda ingin otomatis mengisi test case? (y/n)\nMasukkan jawaban anda : ");
    char otomatis;
    scanf("%c", &otomatis);
	getchar();
    if (otomatis=='y'){
        otomatisdll(&headbuku, &allanggota); // Pass addresses agar bisa lanjut kalau mau lanjut
		printf("apakah anda ingin mereset ulang semua buku? (y/n)\nMasukkan jawaban anda : ");
		char reset;
		scanf("%c", &reset);
		getchar();
		if (reset=='y'){
            addressdll temp;
            while (allanggota != NULL) {
                temp = allanggota;
                allanggota = allanggota->next;
                freeHistorydll(&temp->history);
                free(temp);
            }
            allanggota = NULL;
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
			case 1:
				addBukudll(&headbuku, insertTitledll(), initstockdll());
				break;
            case 2: {
                char* newName = insertNamadll();
                
                // Check if member already exists
                addressdll existingMember = Searchdll(allanggota, newName);
                if (existingMember != NULL) {
                    printf("Anggota dengan nama '%s' sudah terdaftar (level: %d).\n", 
                           newName, existingMember->level);
                    free(newName); // Free the name jika sudah ada
                    break;
                }
                
                // If not found, create a new member
                addressdll newAnggota = SetNodedll(&newName, initleveldll());
                if (allanggota == NULL) {
                    allanggota = newAnggota;
                } else {
                    Ins_Awaldll(&allanggota, newAnggota);
                }
                
                printf("Anggota berhasil ditambahkan!\n");
                break;
            }
            
			case 3: {
            addrBukudll bukuDipesan = findBukudll(headbuku, insertTitledll());
            if (bukuDipesan == NULL) {
                printf("Buku tidak ditemukan!\n");
                break;
            }
            
            char* peminjamName = insertNamadll();
            addressdll nodePeminjam = NULL;
            
            // cek jika anggota sudah pernah ada
            nodePeminjam = Searchdll(allanggota, peminjamName);
            
            if (nodePeminjam == NULL) { // jika member tidak ditemukan
                printf("Anggota baru, ");
                int level = initleveldll();
                char* peminjamCopy = strdup(peminjamName);
                nodePeminjam = SetNodedll(&peminjamCopy, level);
                
                // Add to the global member list
                Ins_Awaldll(&allanggota, nodePeminjam);
                printf("Anggota baru telah ditambahkan ke sistem.\n");
            } else {
                printf("Menggunakan data anggota yang sudah ada (level: %d).\n", nodePeminjam->level);
            }
            
            free(peminjamName);
            
            // Instead of creating a completely new node, just add the member's reference to the queue
            // We still need to create a queue node since we don't want to remove the member from allanggota
            addressdll queueNode = SetNodedll(&(nodePeminjam->info), nodePeminjam->level);
            
            // Add the member to the book's queue
            enqueuedll(&bukuDipesan->Q, queueNode);
            
            // Add this booking to the member's history
            addHistorydll(nodePeminjam, bukuDipesan->info, 'c', 's', bukuDipesan);
            
            printf("Pemesanan berhasil ditambahkan ke antrian!\n");
            break;
            }
			
			case 4: {
				addrBukudll bukuDiproses = findBukudll(headbuku, insertTitledll());
				if (bukuDiproses == NULL) {
					printf("Buku tidak ditemukan!\n");
					break;
				}
				prosesbukudll(bukuDiproses, &allanggota);
				break;
			}
			
			case 5: {
				addrBukudll bukuDikembalikan = findBukudll(headbuku, insertTitledll());
				if (bukuDikembalikan == NULL) {
					printf("Buku tidak ditemukan!\n");
					break;
				}

				returnBukudll(bukuDikembalikan, insertNamadll(), &allanggota);
				break;
			}
			
			case 6:
				printf("\n=== DAFTAR BUKU ===\n");
				displayBukuanggotadll(headbuku);
				break;
			
			case 7:
				printf("\n=== DAFTAR ANGGOTA ===\n");
				if (allanggota == NULL) {
					printf("Tidak ada anggota terdaftar\n");
				} else {
					Tampil_Listdll(allanggota);
				}
				break;
			
			case 8: {
				addrBukudll buku = findBukudll(headbuku, insertTitledll());
				if (buku == NULL) {
					printf("Buku tidak ditemukan!\n");
					break;
				}
					
				char* canceledName = insertNamadll();
				infotype canceledInfo;
					
				if (DeleteValuedll(&buku->Q.head, canceledName, &canceledInfo)) {
					// Find member in allAnggota or create if not exists
					addressdll found = Searchdll(allanggota, canceledName);
					if (found == NULL) {
						addressdll newAnggota = SetNodedll(&canceledName, 3);
						Ins_Akhirdll(&allanggota, newAnggota);
						found = newAnggota;
					}
						
					// Add cancellation to history
					addHistorydll(found, buku->info, 'c', 's', buku);
						
					printf("Pemesanan oleh %s dibatalkan dan catatan disimpan.\n", canceledName);
				} else {
					printf("Peminjam tidak ditemukan dalam antrian buku ini.\n");
				}
				break;
			}
			
			case 9: {
				char* nama = insertNamadll();
				addressdll member = Searchdll(allanggota, nama);
				if (member == NULL) {
					printf("Anggota dengan nama %s tidak ditemukan.\n", nama);
				} else {
					displayHistorydll(member);
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
    
    freeBukudll(&headbuku);
    
    // Bersihkan list anggota
    addressdll temp;
    while (allanggota != NULL) {
        temp = allanggota;
        allanggota = allanggota->next;
        freeHistorydll(&temp->history);
        free(temp);
    }
}