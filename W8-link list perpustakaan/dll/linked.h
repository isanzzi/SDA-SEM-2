#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convention.h"
#include "history.h"

typedef struct tElmtList {
    infotype info;
    int level;
    struct tElmtList *next;
    Stackhistory history;
} Anggota;

typedef char* infotype;
typedef struct tElmtList *address;

boolean isEmpty(address p);
void CreateEmpty(address *q);
void Create_Node(address *p);
void Isi_Node(address *p, infotype nilai, int prior);
address SetNode(infotype *nilai, int lvl);
char* InsertTitle();
char* insertNama();
void Tampil_List(address p);
void Ins_Awal(address *p, address PNew);
void Ins_Akhir(address *p, address PNew);
address Search(address p, infotype nilai);
void InsertAfter(address *pBef, address PNew);
void Del_Awal(address *p, infotype *X);
void Del_Akhir(address *p, infotype *X);
boolean DeleteValue(address *p, infotype target, infotype *X);
void DeAlokasi(address *p);
int NbElmt(address p);
void ModifyString(infotype *str);
void modifiedIns_Akhir(address *p, address PNew);
int initlevel();

#endif
