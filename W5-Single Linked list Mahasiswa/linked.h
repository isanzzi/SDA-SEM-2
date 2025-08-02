#ifndef linked_H
#define linked_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mahasiswa.h"

#define nil NULL

typedef mahasiswa infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address first;
} List;

// Creator/Constructor
void CreateEmpty(List *L);

// Destructor
void DeAlokasi(List *L);

// Validator
boolean isEmpty(List L);
boolean isOneElmt(List L);

// Get/Set functions
address First(List L);
address Next(address P);
infotype Info(address P);
int NbElmt(List L);

// PrintObject
void PrintInfo(List L);
void PrintInfoDescendingByNilai(List L);

void InsertAscending(List *L, infotype X);
void CopyGreaterThan(List source, List *dest, int threshold);
void RemoveDuplicates(List *L);

address Alokasi(infotype X);
void Dealokasi(address *P);
void InsVFirst(List *L, infotype X);
void InsVLast(List *L, infotype X);
void DelVFirst(List *L, infotype *X);
void DelVLast(List *L, infotype *X);

#endif