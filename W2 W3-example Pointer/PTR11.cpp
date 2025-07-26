/* ----------------------------------------------------------------------------- */
/* File : PTR11.cpp */
/* Deskripsi : Pointer ke function (Function sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ----------------------------------------------------------------------------- */
#include <stdio.h>
/* Kamus Global */
int N; /* ukuran efektif */
/* Prototype, fungsi yang diberikan sebagai parameter aktual */
int succ(int i); /* succ -> singkatan dari suksessor. Nantinya fungsi mengembalikan nilai i+1 */
int pred(int i); /* pred -> singkatan dari predesessor. Nantinya fungsi mengembalikan nilai i-1*/
/* Prosedur dengan parameter sebuah fungsi */
void geser(int *TT, int (*f)(int)); // TT adalah pointer ke aray, sedangkan (*F) (int) adalah pointer ke fungsi
/* Program Utama */
int main()
{
    /* kamus lokal */
    int MyTab[10]; //arr of integer mytab 10 elemen
    int i;
    /* program */
    N = 10;
    for (i = 0; i < N; i++)
    {
        MyTab[i] = i;// isi array mytab dari 0 sampai 9
    }
    printf("Isi tabel dalam main sebelum pemanggilan : \n");
    for (i = 0; i < N; i++)
    {
        printf(" %d ", MyTab[i]); // print seluruh elemen mytab sebelum perubahan
    }
    printf("\n");
    /* Pakai geser dengan parameter succ */
    printf("Geser dengan succ \n");
    geser(MyTab, succ); //Mytab = array, succ function mengembalikan i+1 
    printf(" dalam main \n");
    for (i = 0; i < N; i++)

    {
        printf(" %d ", MyTab[i]);// print seluruh elemen setelah perubahan
    }
    printf("\n");
    /* Pakai geser dengan parameter pred */
    printf("Geser dengan pred \n");
    geser(MyTab, pred);//Mytab = array, pred function mengembalikan i+1
    printf(" dalam main setelah aplikasi pred \n");
    for (i = 0; i < N; i++)
    {
        printf(" %d ", MyTab[i]); //print seluruh elemen setelah perubahan
    }
    printf("\n");
    return 0;
}
/* Body Function */
int succ(int i)
{
    return (i + 1);//menambah 1 nilai pada i
}
int pred(int i)
{
    return (i - 1);//mengurangi 1 nilai i
}
void geser(int *TT, int (*f)(int))
{
    int i;
    printf(" dalam geser \n");
    for (i = 0; i < N; i++)
    {
        TT[i] = f(TT[i]); 
        /*
        TT[i] yaitu pointer yang menunjuk ke aray
        f dalah pointer ke fungsi succ/pred
        sehingga saat dijalankan aray indeks 0, indeks 0 dilakukan succ menjadi 1
        selanjutnya aray indeks 1, isi indeks1 dilakukan succ menjadi 2
        dst
        */
        printf(" %d ", TT[i]);
    }
    printf("\n");
}