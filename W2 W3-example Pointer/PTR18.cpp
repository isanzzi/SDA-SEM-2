/* ------------------------------------------------------------------------------------------------------------- */
/* File Program : PTR18.CPP */
/* Deskripsi : program array dinamis dan statis : mengisi dgn baca, menulis (Modular, program */
/* passing parameter tabel/array */
/* ------------------------------------------------------------------------------------------------------------- */
//prosedur menggunakan parameter pointer yang merupakan subvar dari struct tabint

#include <stdio.h>
/* Definisi tabel integer */
typedef struct
{
    int tab[10]; /* array integernya */
    int N;       /* Ukuran efektif */
} tabint;
/* Prototype */
void incTab(tabint *T);  /* Increment setiap elemen tabel */
void printTab(tabint T); /* Print tabel */
int main()
{
    /* kamus */
    tabint T; //struct T menyimpan array tab[10] dan integer N
    int i; //untuk loop
    /* program */
    T.N = 3; //index 3
    printf("Isi dan print tabel untuk indeks 1..5 \n");
    /* isi dari pembacaan */
    for (i = 0; i < T.N; i++)
    {
        printf("Input tabel ke -[%d] = ", i);
        scanf("%d", &(T.tab[i])); //mengisi 3 elemen pertama tab
    };
    /* Stack (Variabel Lokal) contoh
    -----------------------------------------------------
    |  tab[0]  |  tab[1]  |  tab[2]  |  tab[3] ... tab[9] |
    |    5     |    10    |    15    |   ???  ...  ???   |
    -----------------------------------------------------
    */
   
    /* Print : perhatikan passing parameter by value */
    printTab(T);
    /* Increment : perhatikan passing parameter by reference */
    //Menggunakan passing by reference (&T), sehingga fungsi incTab() akan mengubah langsung isi array T.tab[] dalam memori.
    incTab(&T);
    printTab(T);
    return 0;
}
/* Body prototype */
void incTab(tabint *T) //Mengakses nilai asli dari struct T (karena pakai pointer).
/* Increment setiap elemen tabel */
/*f.s yg diharap
Stack (Setelah incTab dipanggil)
-----------------------------------------------------
|  tab[0]  |  tab[1]  |  tab[2]  |  tab[3] ... tab[9] |
|    6     |    11    |    16    |   ???  ...  ???   |
-----------------------------------------------------
*/
{
    /* Kamus lokal */
    int i;
    /* Program */
    for (i = 0; i < (*T).N; i++)
    {
        (*T).tab[i] = (*T).tab[i] + 1; //Menambahkan 1 ke setiap elemen array menggunakan pointer*/
    }
}

void printTab(tabint T) //Menerima struct T sebagai parameter by value (tidak mengubah isi aslinya).
/* Print setiap elemen tabel */
{ /* Kamus lokal */
    int i;
    /* Program untuk traversal print */
    for (i = 0; i < T.N; i++)
    {
        printf("T[%d] = %d \n", i, T.tab[i]); //Loop menampilkan nilai tiap elemen array yang digunakan (N elemen).
    }
}