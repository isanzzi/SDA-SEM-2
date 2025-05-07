#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conventiondll.h"
#include "historydll.h"

// Complete definition of the Anggota struct
typedef struct tElmtList {
    infotype info;
    int level;
    struct tElmtList *next;
    Stackhistorydll history;
} Anggotadll;

typedef char* infotype;
typedef struct tElmtList *addressdll;

boolean isEmptydll(addressdll p);
void CreateEmptydll(addressdll *q);
void Create_Nodedll(addressdll *p);
void Isi_Nodedll(addressdll *p, infotype nilai, int prior);
addressdll SetNodedll(infotype *nilai, int lvl);
char* InsertTitledll();
char* insertNamadll();
void Tampil_Listdll(addressdll p);
void Ins_Awaldll(addressdll *p, addressdll PNew);
void Ins_Akhirdll(addressdll *p, addressdll PNew);
addressdll Searchdll(addressdll p, infotype nilai);
void InsertAfterdll(addressdll *pBef, addressdll PNew);
void Del_Awaldll(addressdll *p, infotype *X);
void Del_Akhirdll(addressdll *p, infotype *X);
boolean DeleteValuedll(addressdll *p, infotype target, infotype *X);
void DeAlokasidll(addressdll *p);
int NbElmtdll(addressdll p);
void ModifyStringdll(infotype *str);
void modifiedIns_Akhirdll(addressdll *p, addressdll PNew);
int initleveldll();

#endif