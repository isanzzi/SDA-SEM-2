#include <stdlib.h>
#include <stdio.h>

int main() {
    /* Kamus Data */
    int *tab; // Deklarasi pointer yang akan digunakan sebagai array dinamis
    int N, i; // Variabel untuk ukuran array dan iterator

    /* Program Utama */
    printf("Contoh mengisi array dinamis berukuran 0..N : \n");
    printf("N = ");
    scanf("%d", &N); // Input ukuran array dari user
    
    printf("Alokasi setelah mengetahui ukuran array \n");
    tab = (int *) malloc((N+1) * sizeof(int)); // Alokasi memori untuk array dinamis
    
    if (tab != NULL) { // Mengecek apakah alokasi memori berhasil
        for (i = 0; i <= N; i++) {
            printf("i=%d tab[i]=%d \n", i, *(tab + i)); // Menampilkan isi array (belum diinisialisasi)
        }
        
        printf("Akhir program \n");
        free(tab); // Dealokasi memori setelah digunakan
        return 0;
    } else {
        printf("Alokasi gagal ... \n"); // Menampilkan pesan jika alokasi gagal
        return 1;
    }
}
