/* ---------------------------------------------------------------------------------------------------------------- */
/* File Program : PTR16CPP */
/* Deskripsi : Array of string : Pendefinisian dan pengaksesan. Perhatikanlah permasalahannya */
/* ---------------------------------------------------------------------------------------------------------------- */

#include<stdio.h>  // Mengimpor pustaka standar input/output untuk fungsi printf dan scanf
#include <stdlib.h> // Mengimpor pustaka untuk fungsi alokasi memori seperti malloc

#define STRING char * // Mendefinisikan alias STRING sebagai char *, yaitu pointer ke karakter

int main()
{
    /* kamus */
    /* Definisi array yang elemennya string, statik dan sekaligus mengisi */
    static STRING s[3] = {"the", "time", "is"}; 
    /*
     - 's' adalah array statis yang menyimpan tiga string.
     - STRING didefinisikan sebagai char *, sehingga ini sama dengan:
       static char *s[3] = {"the", "time", "is"};
     - Setiap elemen dari 's' menyimpan alamat string literal yang berada di area read-only memory.
    */

    /* Definisi array yang elemennya string, dinamik */
    STRING (*TabStr); 
    /*
     - 'TabStr' adalah pointer ke pointer karakter (char **), yang artinya TabStr akan menunjuk ke 
       array dari string yang dialokasikan secara dinamis.
     - Sama dengan menulis: char **TabStr;
    */

    int i; // Variabel untuk iterasi dalam loop

    /* program */
    for (i = 0; i < 3; i++)
    { 
        // Loop untuk mencetak setiap elemen dari array statis 's'
        printf("%s\n", s[i]); // Mencetak string yang ada di array 's' pada indeks i
    }

    /* Alokasi TabStr sebanyak 3 */
    TabStr = (STRING *)malloc(3 * sizeof(STRING)); 
    /*
     - Mengalokasikan memori untuk 3 elemen string (pointer ke karakter) menggunakan alias STRING.
     - Sama dengan menulis: TabStr = (char **)malloc(3 * sizeof(char *));
     - 'malloc' mengembalikan pointer void (void *), jadi perlu di-cast ke 'STRING *' (char **).
    */

    for (i = 0; i < 3; i++)
    {
        /* Alokasi string yang merupakan elemen tabel */
        *(TabStr + i) = (STRING)malloc(5 * sizeof(char)); 
        /*
         - Mengalokasikan memori untuk menyimpan string dengan maksimal 4 karakter + 1 untuk '\0'.
         - Sama dengan menulis: TabStr[i] = (char *)malloc(5 * sizeof(char));
         - Perlu cast ke 'STRING' (char *), karena malloc mengembalikan void *.
        */

        printf("\nInput Str[%d], maksimum 5 karakter : ", i);
        // Meminta pengguna untuk memasukkan string dengan maksimum 5 karakter.

        scanf("%5s", *(TabStr + i)); 
        /*
         - Membaca input string dari pengguna dan menyimpannya di lokasi yang dialokasikan.
         - '%5s' membatasi input hingga 5 karakter untuk mencegah buffer overflow.
        */

        printf("\n Nilai Str[%d] : %5s\n ", i, *(TabStr + i));
        // Mencetak string yang baru saja dimasukkan oleh pengguna.
    }

    /* Dealokasi memori untuk menghindari memory leak */
    for (i = 0; i < 3; i++)
    {
        free(*(TabStr + i)); // Membebaskan memori yang dialokasikan untuk setiap string
    }
    free(TabStr); // Membebaskan memori yang dialokasikan untuk array pointer

    return 0; // Mengembalikan 0 menandakan bahwa program telah selesai dengan sukses.
}
