/* --------------------------------------------------------------------------------------------------------- */
/* File Program : PTR17.CPP */
/* Deskripsi : Array dengan def type:mengisi dg assignment, menulis */
/* --------------------------------------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h> //untuk malloc
int main()
{
    /* kamus */ /* Definisi tabel integer */
    typedef struct //adt
    {
        int *T; /* pointer ke array integer yang dinamis */
        int N;  /* Ukuran efektif (jumlah elemen yang digunakan)*/
    } tabint;
    tabint MyTab; //struct dideklarasikan dengan mytab
    int i;

    /* program */
    printf("Tentukan ukuran tabel, maks 10 = ");
    scanf("%d", &(MyTab.N)); //assign input user kedalam struct mytab subvar N
    MyTab.T = (int *)malloc(MyTab.N * sizeof(int)); 
    //mengalokasikan blok memori integer sebanyak n, lalu pointer menunjuk ke paling kiri
    /* Ilustrasi memori setelah alokasi (misal N = 5)
    Heap (alokasi malloc)
    Alamat Memori | Nilai
    --------------|------
    0x1000        | (kosong)
    0x1004        | (kosong)
    0x1008        | (kosong)
    0x100C        | (kosong)
    0x1010        | (kosong)*/

    /* isi dengan assignment */
    for (i = 0; i < MyTab.N; i++)
    {
        *(MyTab.T + i) = i;
        printf("i = %d MyTab.T = %d \n", i, *(MyTab.T + i));
    };
    /* Ilustrasi memori (misal N = 5)
    Heap (alokasi malloc)
    Alamat Memori | Nilai
    --------------|------
    0x1000        | (0)
    0x1004        | (1)
    0x1008        | (2)
    0x100C        | (3)
    0x1010        | (4)*/
    return 0;
}