#include "kota.h"

boolean isEmptynm(kt k){
    return (k.info[0] == '\0' && k.elekt == nil);
}

boolean isCityInitialized(kt k) {
    return (k.info[0] != '\0');  // Hanya cek apakah string kosong
}

boolean isEmptykt (kt *k){
    return (k==nil);
}

void Initkt(kt *k){
    k->info[0] = '\0';  // Set string kosong
    k->nextkt = nil;
    k->elekt = nil;
}

void Createkt (addrkt *k){
    *k = (addrkt) malloc (sizeof (kt));
}

void Isikt(addrkt *k, infotype nilai) {
    if (*k != nil) {
        strcpy((*k)->info, nilai);
        (*k)->nextkt = nil;
    }
}

addrkt SetKota(infotype *nilai) {
    addrkt k;
    Createkt(&k);
    if (isEmptykt(k)) {
        printf("malloc failed\n");
        return nil;
    }
    strcpy(k->info, *nilai);
    k->nextkt = nil;
    return k;
}

void TampilKota(addrkt k){
    if (isEmptykt(k)){
        printf("empty list\n");
        return;
    } 
    else if (k->info[0] == '\0') { // Ganti pengecekan isEmptynm
        printf("no people\n");
        return;
    } 
    else {
        printf("%s", k->info);
    }
}