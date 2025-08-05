#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"
#include "mahasiswa.h"

int main() {
    List L1, L2;
    
    printf("1 & 2) Membuat ADT Link-List Mahasiswa (L1 dan L2)\n");
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    printf("List L1 dan L2 berhasil dibuat\n\n");
    
    printf("3) Mengisi List L1 dengan data mahasiswa (terurut ascending nama)\n");
    InsertAscending(&L1, DataMahasiswa("Budi", 75));
    InsertAscending(&L1, DataMahasiswa("Ani", 85));
    InsertAscending(&L1, DataMahasiswa("Dodi", 60));
    InsertAscending(&L1, DataMahasiswa("Citra", 90));
    InsertAscending(&L1, DataMahasiswa("Eko", 55));
    InsertAscending(&L1, DataMahasiswa("Aldo", 72));
    InsertAscending(&L1, DataMahasiswa("Zainab", 95));
    printf("Data mahasiswa berhasil dimasukkan ke L1\n\n");
    
    printf("4) Menampilkan List L1 (terurut ascending nama)\n");
    PrintInfo(L1);
    
    printf("5) Menampilkan List L1 (terurut descending nilai)\n");
    PrintInfoDescendingByNilai(L1);
    
    printf("6) Menghitung jumlah mahasiswa dalam List L1\n");
    int count = NbElmt(L1);
    printf("Jumlah mahasiswa dalam List L1: %d\n\n", count);
    
    printf("7) Menyalin mahasiswa dengan nilai > 70 ke List L2\n");
    CopyGreaterThan(L1, &L2, 70);
    printf("Mahasiswa dengan nilai > 70 berhasil disalin ke L2\n\n");
    
    printf("8) Menampilkan List L2\n");
    PrintInfo(L2);
    
    printf("Menambahkan data duplikat ke L2 untuk pengujian\n");
    InsertAscending(&L2, DataMahasiswa("Budi", 85));
    InsertAscending(&L2, DataMahasiswa("Citra", 92));
    printf("Data duplikat berhasil ditambahkan ke L2\n\n");
    
    printf("Menampilkan List L2 setelah penambahan duplikat:\n");
    PrintInfo(L2);
    
    printf("9) Menghapus nama duplikat dari List L2\n");
    RemoveDuplicates(&L2);
    printf("Nama duplikat berhasil dihapus dari L2\n\n");
    
    printf("10) Menampilkan List L2 setelah penghapusan duplikat\n");
    PrintInfo(L2);
    
    printf("11) Menghapus List L1 dan L2\n");
    DeAlokasi(&L1);
    DeAlokasi(&L2);
    printf("List L1 dan L2 berhasil dihapus\n\n");
    
    printf("Verifikasi List L1 setelah dihapus: %s\n", isEmpty(L1) ? "Kosong" : "Tidak Kosong");
    printf("Verifikasi List L2 setelah dihapus: %s\n", isEmpty(L2) ? "Kosong" : "Tidak Kosong");
    
    return 0;
}