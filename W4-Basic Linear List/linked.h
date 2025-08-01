#ifndef linked_H
#define linked_H
#define nil NULL
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

boolean isEmpty(address p);
void Create_Node(address *p);
void Isi_Node(address *p, infotype nilai);
void Tampil_List(address p);
void Ins_Awal(address *p, address PNew);
void Ins_Akhir(address *p, address PNew);
address Search(address p, infotype nilai);
void InsertAfter(address *pBef, address PNew);
void Del_Awal(address *p, infotype *X);
void Del_Akhir(address *p, infotype *X);
void DeleteValue (address *p, infotype target, infotype *X);
void DeAlokasi(address *p);
int NbElmt(address p);

#endif
