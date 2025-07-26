/* -------------------------------------------------------------------------------- */
/* File Program : PTR8a.CPP */
/* (Pointer dan String bagian ke-2) */
/* Deskripsi : menukar isi dua buah string TANPA pemakaian pointer */
/* ------------------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>
#define PANJANG 20
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
char nama1[PANJANG] = "DEWI SARTIKA"; //deklarasi array of char nama1 berisi "Dewi Sartika"
char nama2[PANJANG] = "SULTAN HASANUDDIN"; //deklarasi array of char nama2 berisi "Sultan Hasanuddin"
char namaX[PANJANG]; //deklarasi array of char namax
puts("Nama semula : "); //printf dengan \n
printf("Nama 1 --> %s\n", nama1); //print string nama1
printf("Nama 2 --> %s\n", nama2);//print string nama2
/* Pertukaran string */
strcpy(namaX, nama1); //salin string satu persatu dari nama1 ke namax
strcpy(nama1, nama2); //salin string satu persatu dari nama2 ke nama1
strcpy(nama2, namaX); //salin string satu persatu dari namax ke nama2
puts("Nama sekarang : "); //printf dengan \n
printf("Nama 1 --> %s\n", nama1); //print string nama1
printf("Nama 2 --> %s\n", nama2); //print string nama2
return 0;
}