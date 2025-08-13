#ifndef KOTA_H
#define KOTA_H
#include "linked.h"
#include "convention.h"

typedef struct kota *addrkt;
typedef struct kota{
    infotype info;
    address elekt; //pointer ke telmt list
    addrkt nextkt;
}kt;

boolean isEmptynm(kt k);
boolean isCityInitialized(kt k);
boolean isEmptykt (kt *k);
void Initkt(kt *k);
void Createkt (addrkt *k);
void Isikt(addrkt *k, infotype nilai);
addrkt SetKota(infotype *nilai);
void TampilKota(addrkt k);

#endif