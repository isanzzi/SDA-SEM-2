#include<stdio.h>

int main()
{
    int x,y;//inisialisasi integer x dan y
    int *px;//deklarasi bahwa px adalah pointer ke int

    x=87; //x diinisiasi dgn nilai 87

    px = &x; //pointer px sekarang menunjuk ke address yang sama dengan x
    y=*px;// integer y mengambil nilai dari address px

    printf("Alamat x = %p\n", &x);//%p adalah print alamat yang ditunjuk oleh pointer
    printf("Isi px=%d\n", x);   //isi dari px adalah 87 karena menunjuk address x
    printf("Nilai yang ditunjuk oleh px = %d\n", *px);// nilai yang ditunjuk adalah 87 karena menunjuk address x
    printf("Nilai y = %d\n", y); //nilai y adalah 87 karena dapat dari address px dan address px menunjuk ke x
    printf("Alamat variable y %p karena yang disalin hanya nilainya bukan alamatnya\n", &y);


    return 0;
}