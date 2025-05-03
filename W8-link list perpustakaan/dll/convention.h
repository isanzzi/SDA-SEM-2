#ifndef convention_H
#define convention_H

#define nil NULL
#define MAX_TITLE 50

#define true 1
#define false 0

#define dosen 1
#define mahasiswa 2
#define umum 3

typedef char* infotype;

struct tElmtList;
struct bukuNode;
struct riwayat;

typedef struct tElmtList *address;
typedef struct bukuNode *addrBuku;
typedef struct riwayat *addresshistory;

// Common macros
#define info(P) (P)->info
#define next(P) (P)->next
#define level(P) (P)->level
#define nilai(Q) (Q)->info
#define nextkt(k) (k)->nextkt
#define nm(k) (k)->info
#define lvl(P) (P)->level
#define History(P) (P)->history

typedef int boolean;

#endif