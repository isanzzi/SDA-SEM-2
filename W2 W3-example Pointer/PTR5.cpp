/* --------------------------------------------------------------------------------------------- */
/* File Program : PTR5.CPP */
/* Deskripsi : pointer ke type dasar, mendeklarasikan & alokasi variabel dinamik */
/* --------------------------------------------------------------------------------------------- */
#include <stdlib.h> //untuk malloc dan free
#include <stdio.h>
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
int i = 5, j;  //alamat i=DF1=5, J=DF2
char c = 'X'; //alamat c=DF3=x
int *Ptri = (int *) malloc(4); //al1 utk alokasi ruang. Dp1 utk alamat ptri. alokasi memory 4 byte utk int, pointer ptri menunjuk ke sana
int *Ptrj = (int *) malloc(sizeof(int)); // al2 utk alokasi ruang. Dp2 utk alamat ptrj., pointer ptrj menunjuk ke sana
float *fx = (float *) malloc(sizeof(float)); //al3 utk alokasi ruang. Dp3 utk alamat fx., pointer fx menunjuk ke sana
int A[5]; //alamat a=DF4
float f = 7.23; //float F=D5=7.23
/* program */
*Ptri = 8; //isi memori yg ditunjuk ptri di set ke 8
*Ptrj = 0;//isi memori yg ditunjuk ptrj di set ke 0
*fx = 3; //isi memori yg ditunjuk fx di set ke 3.0
printf("Alamat i = %x \n", &i); //df1
printf("Nilai i = %d \n", i); //5
printf("Ukuran int = %d byte\n\n", sizeof(int)); //4 byte
printf("Alamat j = %x \n", &j); //DF2
printf("Nilai j = %d \n", j); //garbage value
printf("Alamat c = %x \n", &c);//df3
printf("Nilai c = %c \n", c); //c
printf("Ukuran char = %d byte\n\n", sizeof(char)); //1 byte
printf("Alamat Ptri = %x \n", &Ptri); //al1
printf("Isi var Ptri = %x \n", Ptri); //8
printf("Nilai yang ditunjuk oleh Ptri = %d \n", *Ptri); //dp1
printf("Ukuran pointer int = %d byte\n\n", sizeof(int *)); //al1
printf("Alamat Ptrj = %x \n", &Ptrj); //dp2
printf("Isi var Ptrj = %x \n", Ptrj); //al2
printf("Nilai yang ditunjuk oleh Ptrj = %d \n", *Ptrj); //krn sdh diisi 0
Ptrj = Ptri; //ptrj diisi ptri
printf("Isi var Ptrj sekarang = %x \n", Ptrj); //dp1
printf("Nilai yang ditunjuk oleh Ptrj sekarang = %d \n", *Ptrj); //8
printf("Alamat A = %x \n", &A); //df4
printf("Isi var A = %x \n", A[0]); 
printf("Ukuran array A = %d byte\n\n", sizeof(A));
printf("Alamat f = %x \n", &f);
printf("Nilai f = %f \n", f);
printf("Ukuran float = %d byte\n\n", sizeof(float));
return 0;
}