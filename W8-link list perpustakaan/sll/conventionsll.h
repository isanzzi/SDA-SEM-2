#ifndef convention_H
#define convention_H

#define nil NULL
#define true 1
#define false 0
#define dosen 1
#define mahasiswa 2
#define umum 3

typedef char* infotypesll;
typedef int booleansll;

struct tElmtListsll;
typedef struct tElmtListsll *addresssll, *addrBukusll;

#define info(P) (P)->info
#define next(P) (P)->next
#define level(P) (P)->priority
#define stock(P) (P)->priority
#define lvl(P) (P)->priority
#define nilai(Q) (Q)->info
#define History(P) (P)->history

#endif