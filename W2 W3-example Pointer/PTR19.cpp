/* --------------------------------------------------------------------------------------------------------- */
/* File Program : PTR19.CPP */
/* Deskripsi : Program array dinamis dan statis : mengisi dengan input, menulis, dan increment nilai elemen */
/* --------------------------------------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

/* Definisi tabel integer menggunakan array dinamis */
typedef struct
{
    int *tab; /* array integer dinamis */
    int N;    /* Ukuran efektif */
} tabint;

/* Prototype */
void incTab(tabint *T);  /* Increment setiap elemen tabel */
void printTab(tabint T); /* Print tabel */

int main()
{ 
    /* Kamus */
    tabint T; // Struct T menyimpan pointer array dinamis dan integer N
    int i; // Variabel iterasi loop
    
    /* Program */
    T.tab = (int *)malloc(sizeof(int)); // Alokasi memori untuk array dinamis
    T.N = 3; // Ukuran efektif tabel adalah 3
    printf("Isi dan print tabel untuk indeks 0..2 \n");
    
    for (i = 0; i < T.N; i++)
    {   /* Input data ke dalam array */
        printf("Input tabel ke -[%d] = ", i);
        scanf("%d", &(T.tab[i])); // Mengisi 3 elemen pertama dari array dinamis
    }
    
    /* Heap (Memori Dinamis) setelah input, contoh:
    ----------------------------------
    |  tab[0]  |  tab[1]  |  tab[2]  |
    |    5     |    10    |    15    |
    ----------------------------------
    */
    
    printTab(T); /* Print tabel menggunakan passing by value */
    
    /* Increment: menggunakan passing by reference (&T), sehingga perubahan terjadi langsung di heap */
    incTab(&T);
    
    printTab(T);
    
    free(T.tab); // Dealokasi memori setelah selesai digunakan untuk mencegah memory leak
    
    return 0;
}

/* Body prototype */
void incTab(tabint *T) 
/* Increment setiap elemen tabel */
/* F.S setelah incTab dipanggil:
----------------------------------
|  tab[0]  |  tab[1]  |  tab[2]  |
|    6     |    11    |    16    |
----------------------------------
*/
{
    /* Kamus lokal */
    int i;
    /* Program */
    for (i = 0; i < (*T).N; i++)
    {
        (*T).tab[i] = (*T).tab[i] + 1; // Menambahkan 1 ke setiap elemen array di heap
    }
}

void printTab(tabint T) 
/* Print setiap elemen tabel */
{
    /* Kamus lokal */
    int i;
    /* Program */
    for (i = 0; i < T.N; i++)
    {
        printf("T[%d] = %d \n", i, T.tab[i]); // Menampilkan nilai setiap elemen array
    }
}