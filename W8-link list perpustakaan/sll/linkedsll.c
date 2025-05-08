#include "linkedsll.h"

extern PairBukuAnggotasll* pairListHeadsll;

booleansll isEmptysll(addresssll p) {
    return p == NULL;
}

void CreateEmptysll(addresssll *q) {
    *q = NULL;
}

addresssll SetNodesll(infotypesll *nama, int prior) {
    addresssll P = (addresssll)malloc(sizeof(Anggotasll));
    if (P == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    P->info = *nama;
    P->next = NULL;
    P->priority = prior;
    createinitStacksll(&P->history);
    printf("Created node: %s, priority=%d\n", P->info, P->priority);
    return P;
}

char* InsertTitlesll() {
    char *P = (char*)malloc(50 * sizeof(char));
    if (P == NULL) {
        printf("Allocation title failed\n");
        return NULL;
    }
    printf("Masukkan judul buku: ");
    scanf(" %[^\n]s", P);
    return P;
}

char* insertNamasll() {
    char *P = (char*)malloc(50 * sizeof(char));
    if (P == NULL) {
        printf("Allocation name failed\n");
        return NULL;
    }
    printf("Input nama: ");
    scanf(" %[^\n]s", P);
    return P;
}

int initlevelsll() {
    printf("Masukkan level prioritas (1=Dosen, 2=Mahasiswa, 3=Umum): ");
    int level;
    scanf("%d", &level);
    getchar();
    while (level < 1 || level > 3) {
        printf("Level tidak valid!\n");
        scanf("%d", &level);
        getchar();
    }
    return level;
}

int initStocksll() {
    printf("Masukkan stock buku: ");
    int stock;
    scanf("%d", &stock);
    getchar();
    while (stock < 1) {
        printf("Stock tidak valid! Masukkan angka positif.\n");
        scanf("%d", &stock);
        getchar();
    }
    return stock;
}

void Tampil_Listsll(addresssll p) {
    if (isEmptysll(p)) {
        printf("Empty List\n");
        return;
    }
    addresssll temp = p;
    while (temp != NULL) {
        printf("%s (Level: %d)\n", temp->info, temp->priority);
        temp = temp->next;
    }
}

addresssll Searchsll(addresssll p, infotypesll nilai) {
    while (p != NULL) {
        if (nilai != NULL && p->info != NULL && strcmp(p->info, nilai) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void Ins_Awalsll(addresssll *p, addresssll PNew) {
    if (PNew == NULL) return;
    PNew->next = *p;
    *p = PNew;
}

void modifiedIns_Akhirsll(addresssll *p, addresssll PNew) {
    if (p == NULL || PNew == NULL) {
        printf("Error: Invalid pointers\n");
        return;
    }
    if (isEmptysll(*p)) {
        *p = PNew;
        PNew->next = NULL;
        return;
    }
    addresssll current = *p;
    addresssll prev = NULL;
    while (current != NULL && current->priority <= PNew->priority) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        PNew->next = *p;
        *p = PNew;
    } else {
        prev->next = PNew;
        PNew->next = current;
    }
}

booleansll DeleteValuesll(addresssll *p, infotypesll target, infotypesll *X) {
    if (p == NULL || *p == NULL) return false;
    if (strcmp((*p)->info, target) == 0) {
        *X = (*p)->info;
        addresssll temp = *p;
        *p = temp->next;
        temp->next = NULL;
        free(temp);
        return true;
    }
    addresssll prev = *p;
    addresssll temp = prev->next;
    while (temp != NULL && strcmp(temp->info, target) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        *X = temp->info;
        prev->next = temp->next;
        temp->next = NULL;
        free(temp);
        return true;
    }
    return false;
}

void DeAlokasisll(addresssll *p) {
    addresssll temp;
    while (*p != NULL) {
        temp = *p;
        *p = temp->next;
        if (temp->info != NULL) {
            free(temp->info);
        }
        ExitStacksll(&temp->history);
        free(temp);
    }
}

int NbElmtsll(addresssll head, addresssll tail) {
    if (head == NULL || tail == NULL) return 0;
    int count = 1; // Start with tail
    addresssll current = tail;
    while (current != head && current != NULL) {
        count++;
        // Find previous node
        addresssll temp = head;
        while (temp != NULL && temp->next != current) {
            temp = temp->next;
        }
        current = temp;
    }
    return count;
}

void initBukusll(addrBukusll *B) {
    *B = NULL;
}

addrBukusll createBukusll(char *judul, int jumlah) {
    addrBukusll newBuku = (addrBukusll)malloc(sizeof(Bukusll));
    if (newBuku == NULL) return NULL;
    newBuku->info = strdup(judul);
    if (newBuku->info == NULL) {
        free(newBuku);
        return NULL;
    }
    newBuku->priority = jumlah;
    newBuku->next = NULL;
    createinitStacksll(&newBuku->history);
    printf("Created book: %s, stock=%d\n", newBuku->info, newBuku->priority);
    return newBuku;
}

void addBukusll(addrBukusll *head, char *judul, int jumlah) {
    if (jumlah < 1) {
        printf("Stock tidak memenuhi persyaratan\n");
        free(judul);
        return;
    }
    addrBukusll existing = findBukusll(*head, judul);
    if (existing != NULL) {
        existing->priority += jumlah;
        printf("Buku %s sudah ada, stock ditambah menjadi %d\n", judul, existing->priority);
        free(judul);
        return;
    }
    addrBukusll newBuku = createBukusll(judul, jumlah);
    if (newBuku == NULL) {
        free(judul);
        return;
    }
    char* titleCopy = strdup(judul);
    if (titleCopy == NULL) {
        free(newBuku->info);
        free(newBuku);
        free(judul);
        return;
    }
    PairBukuAnggotasll* pair = createPairBukuAnggotasll(newBuku, titleCopy);
    if (pair == NULL) {
        free(newBuku->info);
        free(newBuku);
        free(titleCopy);
        free(judul);
        return;
    }
    pair->next = pairListHeadsll;
    pairListHeadsll = pair;
    if (*head == NULL) {
        *head = newBuku;
    } else {
        addrBukusll temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBuku;
    }
    free(judul);
}

addrBukusll findBukusll(addrBukusll head, char* judul) {
    addrBukusll temp = head;
    while (temp != NULL) {
        if (temp->info != NULL && strcmp(temp->info, judul) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void displayBukusll(addrBukusll head) {
    if (head == NULL) {
        printf("Tidak ada buku\n");
        return;
    }
    addrBukusll temp = head;
    while (temp != NULL) {
        PairBukuAnggotasll* pair = findOrCreatePairBukuAnggotaByAddrsll(temp);
        int queueLength = pair ? NbElmtsll(pair->Q.head, pair->Q.tail) : 0;
        printf("Buku: %s (Tersedia: %d, Antrian: %d)\n", 
               temp->info, temp->priority, queueLength);
        temp = temp->next;
    }
}

void displayBukuanggotasll(addrBukusll head) {
    if (head == NULL) {
        printf("Tidak ada buku\n");
        return;
    }
    addrBukusll temp = head;
    while (temp != NULL) {
        PairBukuAnggotasll* pair = findOrCreatePairBukuAnggotaByAddrsll(temp);
        int queueLength = pair ? NbElmtsll(pair->Q.head, pair->Q.tail) : 0;
        printf("Buku: %s (Tersedia: %d)\n", temp->info, temp->priority);
        if (pair && pair->Q.head != NULL && queueLength > 0) {
            printf("  Antrian Peminjam:\n");
            addresssll current = pair->Q.head;
            int pos = 1;
            while (current != NULL && current->next != pair->buku) {
                printf("  %d. %s (Prioritas: %d)\n", pos++, current->info, current->priority);
                current = current->next;
            }
            if (current != NULL && current->next == pair->buku) {
                printf("  %d. %s (Prioritas: %d)\n", pos++, current->info, current->priority);
            }
            printf("  Total dalam antrian: %d\n", queueLength);
        } else {
            printf("  Tidak ada antrian peminjam\n");
        }
        printf("\n");
        temp = temp->next;
    }
}

void prosesbukusll(addrBukusll head, addresssll *allAnggota) {
    if (head == NULL) {
        printf("Buku tidak ditemukan\n");
        return;
    }
    PairBukuAnggotasll* pair = findOrCreatePairBukuAnggotaByAddrsll(head);
    if (pair == NULL) {
        printf("Kesalahan saat mencari pasangan buku-anggota\n");
        return;
    }
    if (isEmptysll(pair->Q.head)) {
        printf("Tidak ada anggota dalam antrian\n");
        return;
    }
    if (head->priority <= 0) {
        printf("Stok buku habis\n");
        return;
    }
    infotypesll peminjamNama = NULL;
    dequeuesll(&pair->Q, &peminjamNama);
    if (peminjamNama == NULL) {
        printf("Gagal memproses antrian\n");
        return;
    }
    head->priority--;
    addresssll peminjam = Searchsll(*allAnggota, peminjamNama);
    if (peminjam == NULL) {
        printf("Anggota tidak ditemukan, ditambahkan sebagai anggota baru\n");
        infotypesll namaCopy = strdup(peminjamNama);
        addresssll newNode = SetNodesll(&namaCopy, 3);
        if (newNode) {
            Ins_Awalsll(allAnggota, newNode);
            peminjam = newNode;
        } else {
            free(peminjamNama);
            return;
        }
    }
    addHistorysll(peminjam, head->info, 'b', 's', head);
    printf("Buku \"%s\" berhasil dipinjam oleh %s\n", head->info, peminjamNama);
    printf("Sisa stok buku: %d\n", head->priority);
    free(peminjamNama);
}

void returnBukusll(addrBukusll head, infotypesll peminjam, addresssll *allAnggota) {
    if (head == NULL || peminjam == NULL) {
        printf("Buku atau nama peminjam tidak valid\n");
        return;
    }

    head->priority++;
    printf("Buku \"%s\" telah dikembalikan oleh: %s\n", head->info, peminjam);
    printf("Stock buku \"%s\" sekarang: %d\n", head->info, head->priority);

    // cari member, kalau gaada buat baru
    addresssll found = Searchsll(*allAnggota, peminjam);
    if (found == NULL) {
        infotypesll peminjamCopy = strdup(peminjam);
        if (peminjamCopy == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        found = SetNodesll(&peminjamCopy, 3);
        if (found == NULL) {
            free(peminjamCopy);
            printf("Failed to create new member node\n");
            return;
        }
        Ins_Awalsll(allAnggota, found);
    }

    addHistorysll(found, head->info, 'r', 's', head);

    PairBukuAnggotasll* pair = findOrCreatePairBukuAnggotaByAddrsll(head);
    if (pair == NULL) {
        printf("Failed to find or create book-member pair\n");
        return;
    }

    if (!isEmptysll(pair->Q.head) && head->priority > 0) {
        printf("Peminjam berikutnya: %s (Prioritas: %d)\n", 
               pair->Q.head->info, pair->Q.head->priority);
    }
}

void freeBukusll(addrBukusll *head) {
    addrBukusll temp;
    while (*head != NULL) {
        temp = *head;
        *head = temp->next;
        // PairBukuAnggotasll* pair = findPairBukuAnggotaByAddrsll(temp);
        // if (pair) {
        //     ExitQueuesll(&pair->Q);
        // }
        if (temp != NULL) {
            ExitStacksll(&temp->history);
            if (temp->info != NULL) {
                free(temp->info);
                temp->info = NULL;
            }
            free(temp);
        }
    }
    clearAllPairssll();
}
