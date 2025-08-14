#include "kota.h"

boolean isEmptynm (kt k){
    return (k.info == nil && k.elekt == nil);
}

boolean isCityInitialized(kt k) {
    return (k.info != nil);
}

boolean isEmptykt (kt *k){
    return (k==nil);
}

void Initkt (kt *k){
    k->info = nil;
    k->nextkt = nil;
    k->elekt = nil; // Inisialisasi elekt sebagai nil dulu
}

void Createkt (addrkt *k){
    *k = (addrkt) malloc (sizeof (kt));
}

void Addkt (addrkt *k, addrkt knew){
    if (isEmptykt(*k)) {
        *k = knew;
    } else {
        nextkt(knew) = *k;
        *k = knew;
    }
}

void Isikt (addrkt *k, infotype nilai){
    if (*k != nil){
        nm(*k)=nilai;
        nextkt(*k)=nil;
    }
}

addrkt SetKota (infotype *nilai){
    addrkt k;
    Createkt (&k);
    if (isEmptykt(k)){
        printf ("malloc failed\n");
        return nil;
    }
    nm(k)=*nilai;
    nextkt(k)=nil;
    return k;
}

void TampilKota (addrkt k){
    if (isEmptykt(k)){
        printf ("empty list\n");
        return;
    } 
    else if (isEmptynm(*k)) {
        printf ("no people\n");
        return;
    } 
    else {
        printf ("%s", nm(k));
    }
}

void Tampil_ListKota (addrkt k){
    if (isEmptykt(k)){
        printf ("\nempty list\n");
        return;
    } 
    else if (isEmptynm(*k)) {
        printf ("\nno people\n");
        return;
    } 
    else {
        printf ("\n");
        addrkt temp=k;
        int i=0;
        while (temp!=nil){
            printf ("city-%d (%s)\n", (i+1), nm(temp));
            temp=nextkt(temp);
            i++;
        }
        printf ("\n");
    }
}

addrkt ByNumberInput(addrkt k, int maxkota) {
    int kotake, i = 1;
    printf("Masukkan nomor kota: ");
    scanf("%d", &kotake);
       
    addrkt temp = k;
    if (kotake > 0 && kotake <= maxkota) {
        if (!isCityInitialized(*temp)) {
            printf("City not initialized. Please initialize city first\n");
            return nil;
        }
        while (i < kotake && temp != nil) {
            temp = nextkt(temp);
            i++;
        }
        return temp;
    } 
    else {
        printf("Invalid city number\n");
        return nil;
    }
}

addrkt BySearchKota(addrkt k) {
    char *cari = InsertTitle();
    addrkt compare = k;
       
    while (compare != nil) {
        if (strcmp(compare->info, cari) == 0) {
            printf("Data ditemukan!\n");
            free(cari);
            return compare;
        }
        compare = nextkt(compare);
    }
       
    printf("Data tidak ditemukan\n");
    free(cari);
    return nil;
}

void DeAlokasiKota(addrkt *k){
    addrkt temp;
    while (*k != nil){
        temp = *k;
        *k = nextkt(temp);
        // Free infotype string sebelum membebaskan node
        if (temp->info != NULL) {
            free(temp->info);
        }
        // Dealokasi linked list elemen di dalam kota
        if (temp->elekt != nil) {
            DeAlokasi(&(temp->elekt));
        }
        free(temp);
    }
}

void DeleteKotaByNumber(addrkt *k, int *maxkota, int *kotake) {
    if (*k == nil) {
        printf("Tidak ada kota yang tersedia\n");
        return;
    }
    
    if (*kotake <= 0 || *kotake > *maxkota) {
        printf("Nomor kota tidak valid\n");
        return;
    }
    
    // Cari kota yang akan dihapus
    addrkt current = *k;
    addrkt prev = nil;
    int i = 1;
    
    while (i < *kotake && current != nil) {
        prev = current;
        current = nextkt(current);
        i++;
    }
    
    if (current == nil) {
        printf("Kota tidak ditemukan\n");
        return;
    }
    
    // Hapus kota dari linked list
    if (prev == nil) {
        // Hapus kota pertama
        *k = nextkt(current);
    } else {
        // Hapus kota di tengah/akhir
        nextkt(prev) = nextkt(current);
    }
    
    // Dealokasi elemen dalam kota
    if (current->elekt != nil) {
        DeAlokasi(&(current->elekt));
    }
    
    // Bebaskan info kota
    if (current->info != NULL) {
        free(current->info);
    }
    
    // Bebaskan struktur kota
    free(current);
    
    // Kurangi jumlah kota
    (*maxkota)--;
    
    printf("Kota berhasil dihapus\n");
}

void DeleteKotaByName(addrkt *k, int *maxkota, char *nama) {
    if (*k == nil) {
        printf("Tidak ada kota yang tersedia\n");
        return;
    }
    
    addrkt current = *k;
    addrkt prev = nil;
    boolean found = false;
    
    while (current != nil && !found) {
        if (strcmp(current->info, nama) == 0) {
            found = true;
        } else {
            prev = current;
            current = nextkt(current);
        }
    }
    
    if (!found) {
        printf("Kota tidak ditemukan\n");
        return;
    }
    
    // Hapus kota dari linked list
    if (prev == nil) {
        // Hapus kota pertama
        *k = nextkt(current);
    } else {
        // Hapus kota di tengah/akhir
        nextkt(prev) = nextkt(current);
    }
    
    // Dealokasi elemen dalam kota
    if (current->elekt != nil) {
        DeAlokasi(&(current->elekt));
    }
    
    // Bebaskan info kota
    if (current->info != NULL) {
        free(current->info);
    }
    
    // Bebaskan struktur kota
    free(current);
    
    // Kurangi jumlah kota
    (*maxkota)--;
    
    printf("Kota %s berhasil dihapus\n", nama);
}