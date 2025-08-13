#ifndef linked_H
#define linked_H
#define nil NULL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convention.h"

typedef char infotype[50];  // Changed from char* to static array
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

boolean isEmpty(address p);
void CreateEmpty(address *q);
void Create_Node(address *p);
void Isi_Node(address *p, infotype nilai);
address SetNode (infotype *nilai);
void InsertTitle(infotype nilai); // Changed from char* to void with parameter
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
void ModifyString(infotype str); // Add new function

#endif