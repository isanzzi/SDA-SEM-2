/* ----------------------------------------------------- */
/* File Program : PTR6.CPP */
/* Deskripsi : pointer yang menunjuk ke array */
/* ---------------------------------------------------- */

//tujuan : cara agar pointer menunjuk ke setiap isi di aray lalu print

#include <stdio.h>

int main(){
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    static int tgl_lahir[] = {18, 6, 1989};//array tanggal lahir
    int *ptgl; //pointer ptgl terhadap integer

    ptgl = tgl_lahir;//pointer menunjuk ke elemen pertama array
    int size = sizeof(tgl_lahir) / sizeof(tgl_lahir[0]);//(3elemen*4byte)/4byte =3

    int i=0; //untuk perulangan
    while (i<size){//dari indeks 0 sampai akhir
        printf("Nilai yang ditunjuk oleh ptgl = %d\n", *(ptgl+i)); //print nilai pointer yg menunjuk aray
        printf("Nilai dari tgl_lahir[%d] = %d\n",i+1, tgl_lahir[i]); //mengakses elemen aray secara langsung 
    i++;// untuk increment i
    }
    return 0;
}
/* STUDI KASUS : */
/* Eksekusi dan pahami maksud program ini (tulis tujuan program ini) */
/* Modifikasi program tersebut agar bisa menampilkan seluruh elemen array tgl_lahir !*/