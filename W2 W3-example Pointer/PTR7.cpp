/* ----------------------------------------------------------- */
/* File Program : PTR7.CPP */
/* (Pointer dan String bagian ke-1) */
/* Deskripsi : pointer yang menunjuk ke data string */
/* ---------------------------------------------------------- */
#include <stdio.h>
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
char *pkota = "BANDUNG";
puts(pkota);
return 0;
}

/* STUDI KASUS :
Apa perbedaan deklarasi variabel char *pkota='BANDUNG'; dengan char kota[]='BANDUNG' ?

Untuk char *pkota="BANDUNG"
char *pkota = "BANDUNG"; disimpan di text segment (read-only memory)
*pkota adalah pointer yang menunjuk ke alamat awal string "BANDUNG", yaitu B.

Kalau char kota[]='BANDUNG'
kota adalah array yang menyimpan karakter "BANDUNG" secara langsung dalam stack.
Bisa dimodifikasi karena setiap karakter disimpan dalam variabel array
*/