/* -------------------------------------------------- */
/* File Program : PTR9.CPP */
/* Deskripsi : pointer yang menunjuk pointer */
/* -------------------------------------------------- */
#include <stdio.h>
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
int var_x = 273; //anggap disimpan di alamat 1000
int *ptr1; /* ptr1 adl pointer yang menunjuk ke objek bertipe integer */
/* (Boleh disebut pointer integer saja) */
int **ptr2; /* ptr2 adl pointer yang menunjuk ke pointer yang menunjuk */
/* ke objek bertipe integer (Boleh disebut : pointer menunjuk ke pointer integer

saja) */
ptr1 = &var_x;//anggap ptr1 berada di alamat 2000, lalu ptr1 sekarang menyimpan alamat var_x (misalnya 1000). 
ptr2 = &ptr1; //anggap ptr2 berada di alamat 3000, lalu ptr2 sekarang menyimpan alamat ptr1 (misalnya 2000).
/* Mengakses nilai var_x melalui ptr1 dan ptr2 */
printf("Nilai var_x = %d\n", *ptr1); //*ptr1 berarti akses nilai yang disimpan di alamat ptr1, yaitu 273.
printf("Nilai var_x = %d\n", **ptr2); 
        //*ptr2 → ambil isi ptr2, yaitu alamat ptr1 (2000).
        //**ptr2 → ambil isi dari *ptr2, yaitu *ptr1, yang menunjuk ke var_x (273).
        //oleh karena itu hasil 273
return 0;
}
/* STUDI KASUS : */
/* Eksekusi dan pahami maksud program ini dan */
/* komentari setiap baris programnya (mulai dari baris ptr1= &var_x; ) */

/*
+------------+------------+
|  var_x     |    273     |  <-- Data integer
+------------+------------+
       ▲
       | (disimpan di alamat 1000)
       |
+------------+------------+
|  ptr1      |   1000     |  <-- Pointer menunjuk ke var_x
+------------+------------+
       ▲
       | (disimpan di alamat 2000)
       |
+------------+------------+
|  ptr2      |   2000     |  <-- Pointer ke pointer menunjuk ke ptr1
+------------+------------+
(disimpan di alamat 3000)
*/