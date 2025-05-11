#ifndef nbtrees_h
#define nbtrees_h

#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Maksimal node yang dapat ditampung dalam array
#define jml_maks 20
//Arah traversal
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil 0

#define printcmd 0
#define printgraph 1

/***************************/
/* Type data */
/***************************/
/* Indeks dalam bahasa C dimulai dengan 0; tetapi indeks 0 tidak
dipakai */
/* Kamus */
typedef char infotype;
typedef struct elmttree *address;

typedef struct elmttree{ 
    infotype info;
    address left, right, parent;
} nbtree;

/***************************/
/* S P E S I F I K A S I */
/***************************/
address Create_node (infotype info);
void Create_tree(address *root);
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array address dengan pola Level Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input

bool IsEmpty (address P);
/* Mengirimkan true jika address KOSONG */

/***** Traversal *****/
// void PreOrder (address P, address curr);
/* Traversal PreOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : parent,
fs, nb */
void InOrder (address P);
/* Traversal InOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, parent,
Sisa anak lain */
// void PostOrder (address P, address curr);
/* Traversal PostOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PostOrder : fs, nb,
parent */
// void Level_order(address X, int Maks_node);
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */
void PrintTree (address P, const char* filenameinput, const char* filenameoutput);
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */
// /***** Search *****/
// bool Search (address P, infotype X);
// /* Mengirimkan true jika ada node dari P yang bernilai X *
// /***** Fungsi Lain *****/
// int nbElmt (address P);
// /* Mengirimkan banyak elemen (node) di pohon non biner P */
// int nbDaun (address P);
// /* Mengirimkan banyak daun (node) pohon non biner P */
// int Level (address P, infotype X);
// /* Mengirimkan level dari node X yang merupakan salah satu simpul */
// /* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */
// int Depth (address P);
// /* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari
// Pohon */
// /* Basis : Pohon Kosong, tingginya Nol */
// int Max (infotype Data1, infotype Data2);
// /* Mengirimkan Nilai terbesar dari dua data */

void initialize_tree(address *root);
void ClearTree (address *root);
// void convertstring (address P, char *str);
void txtstringtomorse (address head);
void stringtomorse (address root, address p, char *str, char *hasil);
void toupperstring (char *str);

#endif
