#include "linked.h"

extern PairBukuAnggota* pairListHead;

boolean isEmpty(address p) {
    return p == NULL;
}

void CreateEmpty(address *q) {
    *q = NULL;
}

address SetNode(infotype *nama, int prior) {
    address P = (address)malloc(sizeof(Anggota));
    if (P == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    P->info = *nama;
    P->next = NULL;
    P->priority = prior;
    createinitStack(&P->history);
    printf("Created node: %s, priority=%d\n", P->info, P->priority);
    return P;
}

char* InsertTitle() {
    char *P = (char*)malloc(50 * sizeof(char));
    if (P == NULL) {
        printf("Allocation title failed\n");
        return NULL;
    }
    printf("Masukkan judul buku: ");
    scanf(" %[^\n]s", P);
    return P;
}

char* insertNama() {
    char *P = (char*)malloc(50 * sizeof(char));
    if (P == NULL) {
        printf("Allocation name failed\n");
        return NULL;
    }
    printf("Input nama: ");
    scanf(" %[^\n]s", P);
    return P;
}

int initlevel() {
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

int initStock() {
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

void Tampil_List(address p) {
    if (isEmpty(p)) {
        printf("Empty List\n");
        return;
    }
    address temp = p;
    while (temp != NULL) {
        printf("%s (Level: %d)\n", temp->info, temp->priority);
        temp = temp->next;
    }
}

address Search(address p, infotype nilai) {
    while (p != NULL) {
        if (nilai != NULL && p->info != NULL && strcmp(p->info, nilai) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void Ins_Awal(address *p, address PNew) {
    if (PNew == NULL) return;
    PNew->next = *p;
    *p = PNew;
}

void modifiedIns_Akhir(address *p, address PNew) {
    if (p == NULL || PNew == NULL) {
        printf("Error: Invalid pointers\n");
        return;
    }
    if (isEmpty(*p)) {
        *p = PNew;
        PNew->next = NULL;
        return;
    }
    address current = *p;
    address prev = NULL;
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

boolean DeleteValue(address *p, infotype target, infotype *X) {
    if (p == NULL || *p == NULL) return false;
    if (strcmp((*p)->info, target) == 0) {
        *X = (*p)->info;
        address temp = *p;
        *p = temp->next;
        temp->next = NULL;
        free(temp);
        return true;
    }
    address prev = *p;
    address temp = prev->next;
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

void DeAlokasi(address *p) {
    address temp;
    while (*p != NULL) {
        temp = *p;
        *p = temp->next;
        if (temp->info != NULL) free(temp->info);
        ExitStack(&temp->history);
        free(temp);
    }
}

int NbElmt(address head, address tail) {
    if (head == NULL || tail == NULL) return 0;
    int count = 1; // Start with tail
    address current = tail;
    while (current != head && current != NULL) {
        count++;
        // Find previous node
        address temp = head;
        while (temp != NULL && temp->next != current) {
            temp = temp->next;
        }
        current = temp;
    }
    return count;
}

void initBuku(addrBuku *B) {
    *B = NULL;
}

addrBuku createBuku(char *judul, int jumlah) {
    addrBuku newBuku = (addrBuku)malloc(sizeof(Buku));
    if (newBuku == NULL) return NULL;
    newBuku->info = strdup(judul);
    if (newBuku->info == NULL) {
        free(newBuku);
        return NULL;
    }
    newBuku->priority = jumlah;
    newBuku->next = NULL;
    createinitStack(&newBuku->history);
    printf("Created book: %s, stock=%d\n", newBuku->info, newBuku->priority);
    return newBuku;
}

void addBuku(addrBuku *head, char *judul, int jumlah) {
    if (jumlah < 1) {
        printf("Stock tidak memenuhi persyaratan\n");
        free(judul);
        return;
    }
    addrBuku existing = findBuku(*head, judul);
    if (existing != NULL) {
        existing->priority += jumlah;
        printf("Buku %s sudah ada, stock ditambah menjadi %d\n", judul, existing->priority);
        free(judul);
        return;
    }
    addrBuku newBuku = createBuku(judul, jumlah);
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
    PairBukuAnggota* pair = createPairBukuAnggota(newBuku, titleCopy);
    if (pair == NULL) {
        free(newBuku->info);
        free(newBuku);
        free(titleCopy);
        free(judul);
        return;
    }
    pair->next = pairListHead;
    pairListHead = pair;
    if (*head == NULL) {
        *head = newBuku;
    } else {
        addrBuku temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBuku;
    }
    free(judul);
}

addrBuku findBuku(addrBuku head, char* judul) {
    addrBuku temp = head;
    while (temp != NULL) {
        if (temp->info != NULL && strcmp(temp->info, judul) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void displayBuku(addrBuku head) {
    if (head == NULL) {
        printf("Tidak ada buku\n");
        return;
    }
    addrBuku temp = head;
    while (temp != NULL) {
        PairBukuAnggota* pair = findOrCreatePairBukuAnggotaByAddr(temp);
        int queueLength = pair ? NbElmt(pair->Q.head, pair->Q.tail) : 0;
        printf("Buku: %s (Tersedia: %d, Antrian: %d)\n", 
               temp->info, temp->priority, queueLength);
        temp = temp->next;
    }
}

void displayBukuanggota(addrBuku head) {
    if (head == NULL) {
        printf("Tidak ada buku\n");
        return;
    }
    addrBuku temp = head;
    while (temp != NULL) {
        PairBukuAnggota* pair = findOrCreatePairBukuAnggotaByAddr(temp);
        int queueLength = pair ? NbElmt(pair->Q.head, pair->Q.tail) : 0;
        printf("Buku: %s (Tersedia: %d)\n", temp->info, temp->priority);
        if (pair && pair->Q.head != NULL && queueLength > 0) {
            printf("  Antrian Peminjam:\n");
            address current = pair->Q.head;
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

void prosesbuku(addrBuku head, address *allAnggota) {
    if (head == NULL) {
        printf("Buku tidak ditemukan\n");
        return;
    }
    PairBukuAnggota* pair = findOrCreatePairBukuAnggotaByAddr(head);
    if (pair == NULL) {
        printf("Kesalahan saat mencari pasangan buku-anggota\n");
        return;
    }
    if (isEmpty(pair->Q.head)) {
        printf("Tidak ada anggota dalam antrian\n");
        return;
    }
    if (head->priority <= 0) {
        printf("Stok buku habis\n");
        return;
    }
    infotype peminjamNama = NULL;
    dequeue(&pair->Q, &peminjamNama);
    if (peminjamNama == NULL) {
        printf("Gagal memproses antrian\n");
        return;
    }
    head->priority--;
    address peminjam = Search(*allAnggota, peminjamNama);
    if (peminjam == NULL) {
        printf("Anggota tidak ditemukan, ditambahkan sebagai anggota baru\n");
        infotype namaCopy = strdup(peminjamNama);
        address newNode = SetNode(&namaCopy, 3);
        if (newNode) {
            Ins_Awal(allAnggota, newNode);
            peminjam = newNode;
        } else {
            free(peminjamNama);
            return;
        }
    }
    addHistory(peminjam, head->info, 'b', 's', head);
    printf("Buku \"%s\" berhasil dipinjam oleh %s\n", head->info, peminjamNama);
    printf("Sisa stok buku: %d\n", head->priority);
    free(peminjamNama);
}

void returnBuku(addrBuku head, infotype peminjam, address *allAnggota) {
    if (head == NULL) {
        printf("Buku tidak ditemukan\n");
        return;
    }
    head->priority++;
    printf("Buku \"%s\" telah dikembalikan oleh: %s\n", head->info, peminjam);
    printf("Stock buku \"%s\" sekarang: %d\n", head->info, head->priority);
    address found = Search(*allAnggota, peminjam);
    if (found == NULL) {
        infotype peminjamCopy = strdup(peminjam);
        address newNode = SetNode(&peminjamCopy, 3);
        if (newNode) {
            Ins_Awal(allAnggota, newNode);
            found = newNode;
        }
    }
    if (found) {
        addHistory(found, head->info, 'r', 's', head);
    }
    PairBukuAnggota* pair = findOrCreatePairBukuAnggotaByAddr(head);
    if (pair && !isEmpty(pair->Q.head) && head->priority > 0) {
        printf("Peminjam berikutnya: %s (Prioritas: %d)\n", 
               pair->Q.head->info, pair->Q.head->priority);
    }
}

void freeBuku(addrBuku *head) {
    addrBuku temp;
    while (*head != NULL) {
        temp = *head;
        *head = temp->next;
        PairBukuAnggota* pair = findOrCreatePairBukuAnggotaByAddr(temp);
        if (pair) {
            ExitQueue(&pair->Q);
            free(pair->bookTitle);
        }
        ExitStack(&temp->history);
        free(temp->info);
        free(temp);
    }
    clearAllPairs();
}