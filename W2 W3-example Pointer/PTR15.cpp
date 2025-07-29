/* ---------------------------------------------------------------------------------------------------------------- */
/* File Program : PTR15.CPP */
/* Deskripsi : Array of string : Pendefinisian dan pengaksesan. Perhatikanlah permasalahannya */
/* ---------------------------------------------------------------------------------------------------------------- */
#include<stdio.h> // Mengimpor pustaka standar input/output untuk fungsi printf dan scanf
#include <stdlib.h> // Mengimpor pustaka untuk fungsi alokasi memori seperti malloc

int main()
{
    /* kamus */
    /* Definisi array yang elemennya string, statik dan sekaligus mengisi */
    static char *s[3] = {"the", "time", "is"}; 
    // Mendefinisikan array statis 's' yang berisi 3 string. 
    // 'static' berarti array ini memiliki waktu hidup yang sama dengan program dan tidak akan dihapus setelah keluar dari scope.

    /* Definisi array yang elemennya string, dinamik */
    char *(*TabStr); 
    // Mendeklarasikan 'TabStr' sebagai pointer ke pointer karakter (array dari string).
    // Ini akan digunakan untuk menyimpan alamat string yang dialokasikan secara dinamis.

    int i; // Variabel untuk iterasi dalam loop

    /* program */
    for (i = 0; i < 3; i++)
    { 
        // Loop untuk mencetak setiap elemen dari array statis 's'
        printf("%s\n", s[i]); // Mencetak string yang ada di array 's' pada indeks i
    }

    /* Alokasi TabStr sebanyak 3 */
    TabStr = (char **)malloc(3 * sizeof(char *)); 
    // Mengalokasikan memori untuk 3 elemen string (pointer ke karakter).
    // 'malloc' mengembalikan pointer void, jadi perlu di-cast ke 'char **'.
    // Ini adalah alokasi dinamis, sehingga memori harus dibebaskan nanti.

    for (i = 0; i < 3; i++)
    {
        /* Alokasi string yang merupakan elemen tabel */
        *(TabStr + i) = (char *)malloc(5 * sizeof(char)); 
        // Mengalokasikan memori untuk setiap string yang akan disimpan di 'TabStr'.
        // Setiap string dapat menyimpan maksimum 4 karakter + 1 untuk karakter null ('\0').

        printf("\nInput Str[%d], maksimum 5 karakter : ", i);
        // Meminta pengguna untuk memasukkan string dengan maksimum 5 karakter.

        scanf("%5s", *(TabStr + i)); 
        // Membaca input string dari pengguna dan menyimpannya di lokasi yang dialokasikan.
        // '%5s' membatasi input hingga 5 karakter untuk mencegah buffer overflow.

        printf("\n Nilai Str[%d] : %5s\n ", i, *(TabStr + i));
        // Mencetak string yang baru saja dimasukkan oleh pengguna.
    }

    // Di sini seharusnya ada kode untuk membebaskan memori yang dialokasikan
    // untuk menghindari memory leak, tetapi tidak ada dalam kode ini.

    return 0; // Mengembalikan 0 menandakan bahwa program telah selesai dengan sukses.
}