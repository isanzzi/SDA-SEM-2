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



boolean isEmptynm (kt k);
boolean isCityInitialized(kt k);
boolean isEmptykt (kt *k);

void Initkt (kt *k);
void Createkt (addrkt *k);
void Addkt (addrkt *k, addrkt knew);
void Isikt (addrkt *k, infotype nilai);
void Tampil_ListKota (addrkt k);
addrkt SetKota (infotype *nilai);
addrkt ByNumberInput(addrkt k, int maxkota);
addrkt BySearchKota(addrkt k);
void DeleteKotaByNumber(addrkt *k, int *maxkota, int *kotake);
void DeleteKotaByName(addrkt *k, int *maxkota, char *nama);

void TampilKota (addrkt k);
void DeAlokasiKota(addrkt *k);
#endif