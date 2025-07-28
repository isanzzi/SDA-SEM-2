/* ------------------------------------------------------------------------------------------------------------------ */
/* File : PTR12.cpp */
/* Deskripsi : Pointer ke function (Procedure dengan parameter input/output sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ------------------------------------------------------------------------------------------------------------------ */
#include<stdio.h>
/* Kamus Global */
int N; /* ukuran efektif */
/* Prototype, fungsi yang diberikan sebagai parameter aktual */
void succ(int *i); /* suksessor, berupa procedure by ref */
void pred(int *i); /* predesessor */
/* Prosedur dengan parameter sebuah fungsi */
void geser(int *TT, void (*f)(int *));
/* Program Utama */

int main()
{
    /* kamus lokal */
    int MyTab[10];// Deklarasi array MyTab dengan 10 elemen
    int i;
    /* program */
    N = 10;
    for (i = 0; i < N; i++)
    {
        MyTab[i] = i; // isi array mytab dari 0 sampai 9
    }
    printf("Isi tabel dalam main sebelum pemanggilan : \n");
    for (i = 0; i < N; i++)
    {
        printf(" %d ", MyTab[i]);// print seluruh elemen mytab sebelum perubahan
    }
    printf("\n");
    /* Pakai geser dengan parameter succ */
    printf("Geser dengan succ \n");
    geser(MyTab, succ); 
    /*
    memanggil fungsi geser(), yang akan menerapkan succ() ke setiap elemen array.
    Mytab = array, succ adalah prosedure yang menerima alamat lalu mengubahnya 
    */
    printf(" dalam main \n");
    for (i = 0; i < N; i++)
    {
        printf(" %d ", MyTab[i]); // print seluruh elemen setelah perubahan
    }
    printf("\n");
    /* Pakai geser dengan parameter pred */
    printf("Geser dengan pred \n");
    geser(MyTab, pred); //Mytab = array, succ adalah prosedure yang menerima alamat lalu mengubahnya
    //memanggil fungsi geser(), yang akan menerapkan pred() ke setiap elemen array.
    printf(" dalam main setelah aplikasi pred \n");
    for (i = 0; i < N; i++)
    {
        printf(" %d ", MyTab[i]); // print seluruh elemen setelah perubahan
    }
    printf("\n");
    return 0;
}
/* Body Function */
void succ(int *i)
{
    *i = *i + 1; //mengambil alamat dari i lalu mengubahnya dengan menambahkannya dengan 1
}
void pred(int *i)
{
    *i = *i - 1; //mengambil alamat dari i lalu mengubahnya dengan menguranginya dengan 1
}
void geser(int *TT, void (*f)(int *))
{
    int i;
    printf(" dalam geser \n");
    for (i = 0; i < N; i++)

    {
        f(&TT[i]);
        /*
        TT[i] yaitu pointer yang menunjuk ke aray i
        f dalah pointer ke fungsi succ/pred
        sehingga saat dijalankan aray indeks 0, indeks 0 dilakukan succ menjadi 1
        selanjutnya aray indeks 1, isi indeks1 dilakukan succ menjadi 2
        dst
        */
        printf(" %d ", TT[i]);
    }
    printf("\n");
}