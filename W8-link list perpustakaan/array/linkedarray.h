#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conventionarray.h"
#include "historyarray.h"

typedef struct tElmtListArray {
    infotype info;
    int level;
    struct tElmtListArray *next;
    Stackhistoryarray history;
} Anggotaarray;

typedef char* infotype;
typedef struct tElmtListArray *addressarray;

boolean isEmptyarray(addressarray p);
void CreateEmptyarray(addressarray *q);
void Create_Nodearray(addressarray *p);
void Isi_Nodearray(addressarray *p, infotype nilai, int prior);
addressarray SetNodeArray(infotype *nilai, int lvl);
char* InsertTitleArray();
char* insertNamaArray();
void Tampil_ListArray(addressarray p);
void Ins_AwalArray(addressarray *p, addressarray PNew);
void Ins_AkhirArray(addressarray *p, addressarray PNew);
addressarray SearchArray(addressarray p, infotype nilai);
void InsertAfterArray(addressarray *pBef, addressarray PNew);
void Del_AwalArray(addressarray *p, infotype *X);
void Del_AkhirArray(addressarray *p, infotype *X);
boolean DeleteValueArray(addressarray *p, infotype target, infotype *X);
void DeAlokasiArray(addressarray *p);
int NbElmtArray(addressarray p);
void ModifyStringArray(infotype *str);
void modifiedIns_AkhirArray(addressarray *p, addressarray PNew);
int initlevelArray();

#endif