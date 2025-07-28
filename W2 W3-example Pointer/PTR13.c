/* ------------------------------------------------------------------------------------------------------------------ */
/* File : PTR13.c */
/* Deskripsi : Pointer ke function (Procedure dengan parameter input/output sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ------------------------------------------------------------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h> //untuk malloc

/* Kamus Global */
int N; /* ukuran efektif */
enum MyType{
	bulat, karakter}; //bulat 1 (int), karakter 2 (char)

/* Prototype, fungsi yang diberikan sebagai parameter aktual */
void succI (int *i); /* suksessor, berupa procedure by ref */
void predI (int *i); /* predesessor */
void succC (char *c); /* suksessor, berupa procedure by ref */
void predC (char *c); /* predesessor */

/* print tabel yang belum ketahuan typenya */
void printtab (void *T, enum MyType Ty);
/*
Fungsi ini mencetak isi array tanpa mengetahui tipe datanya secara langsung.
void *T adalah pointer umum (generic pointer).*/

/* Prosedur dengan parameter sebuah fungsi */
void geser (void *TT, void (*f) (void *), enum MyType Ty);
/*
void *TT → Generic pointer ke array.
void (*f) (void *) → Pointer ke fungsi, yang bisa menunjuk ke succI, predI, succC, atau predC.
enum MyType Ty → Menentukan apakah array bertipe integer atau karakter.
*/

/* Program Utama */
int main(){
	/* kamus lokal */
	//void *MyTabInt;
	int *MyTabInt; //MyTabInt → Pointer untuk menyimpan array integer.
	//void *MyTabC;	
	char *MyTabC; //MyTabC → Pointer untuk menyimpan array karakter.
	int i;

	/* program */
	N = 10;
	MyTabInt = (int *) malloc (N * sizeof(int));
	MyTabC = (char *) malloc (N * sizeof(char));
	//*MyTabInt = 1;
	
	//Loop ini mengisi array dengan data awal:
	for (i = 0; i < N; i++){
		*(MyTabInt + i) = i; //MyTabInt → [0] [1] [2] [3] [4] [5] [6] [7] [8] [9]
		*(MyTabC + i) = 'Z';} //MyTabC  → ['Z'] ['Z'] ['Z'] ['Z'] ['Z'] ['Z'] ['Z'] ['Z'] ['Z'] ['Z']

	printf("Isi tabel dalam main sebelum pemanggilan : \n");
	printf(" Tabel integer \n");
	printtab ((int *) MyTabInt, 0); //Fungsi ini mencetak isi array dengan mengetahui tipe data apa yang dipanggil
	printf(" Tabel charakter \n");
	printtab ((char *) MyTabC, 1); //Fungsi ini mencetak isi array dengan mengetahui tipe data apa yang dipanggil
	printf("\n");

	/* Pakai geser dengan parameter succ */
	printf("Geser dengan succ \n");
	geser ((int *) MyTabInt, (void *) succI, 0); //Fungsi succI menambah 1 ke setiap elemen MyTabInt → [1] [2] [3] ... [10].
	geser ((char *) MyTabC, (void *) succC, 1); //Fungsi succC menambah 1 ke setiap elemen MyTabC → ['['] ['['] ['['] ... '[''].
	printf(" dalam main \n");
	printf(" Tabel integer \n");
	printtab ((int *) MyTabInt, 0); //Fungsi ini mencetak isi array dengan mengetahui tipe data apa yang dipanggil
	printf(" Tabel charakter \n");
	printtab ((char *) MyTabC, 1);//Fungsi ini mencetak isi array dengan mengetahui tipe data apa yang dipanggil
	printf("\n");
	/* Pakai geser dengan parameter pred*/
	printf("Geser dengan pred \n");
	geser ((int *) MyTabInt, (void *) predI, 0); //MyTabInt dikurangi 1 → Kembali ke nilai awal [0] [1] [2] ... [9].
	geser ((char *) MyTabC, (void *) predC, 1); //MyTabC dikurangi 1 → Kembali ke 'Z'.
	printf(" dalam main \n");
	printf(" Tabel integer \n");
	printtab ((int *) MyTabInt, 0);//Fungsi ini mencetak isi array dengan mengetahui tipe data apa yang dipanggil
	printf(" Tabel charakter \n");
	printtab ((char *) MyTabC, 1);//Fungsi ini mencetak isi array dengan mengetahui tipe data apa yang dipanggil
	printf("\n");
	return 0;}

/* Body Function */
void succI (int *i){
	//printf("%d ", *i);
	*i = *i+1;
	//printf("%d\n", *i);}
	}
void predI (int *i){
	*i = *i-1;}

void succC (char *c){
	*c = *c+1;}

void predC (char *c){
	*c = *c-1;}

void geser (void *TT, void (*f) (void *), enum MyType Ty){
	/*
	Mengecek tipe data menggunakan switch(Ty).
	Melakukan konversi void * menjadi tipe yang sesuai (int * atau char *).
	Memanggil fungsi yang diterima melalui pointer (f menunjuk ke succI, predI, succC, atau predC).*/
	int i;
	printf(" dalam geser \n");
	for (i = 0; i < N; i++){
		
		switch(Ty){
			case bulat : f (((int *)TT + i));printf(" %d ", *((int *)TT + i)); break;
			/*
			case bulat :
			Jika Ty == bulat, maka berarti TT menunjuk ke array int.
			f (((int *)TT + i));

			TT adalah void *, yang berarti tipe data tidak diketahui secara spesifik.
			((int *)TT) mengubah TT menjadi pointer ke int, agar bisa diakses sebagai array int.
			((int *)TT + i) menunjuk ke elemen ke-i dari array integer. Ini sama seperti &TT[i] dalam bentuk pointer.
			f(...) berarti kita memanggil fungsi f dengan parameter &TT[i].
			Jika f adalah succI, maka TT[i] akan ditambah 1.
			Jika f adalah predI, maka TT[i] akan dikurangi 1.
			printf(" %d ", *((int *)TT + i));

			*((int *)TT + i) mengambil nilai dari elemen i dalam array integer.
			%d digunakan untuk mencetak angka dalam format integer.*/
			case karakter : f (((char *)TT + i));printf(" %c ", *((char *)TT+i)); break;
			/*
			case karakter :
			Jika Ty == karakter, berarti TT menunjuk ke array char.
			f (((char *)TT + i));

			((char *)TT) mengubah TT menjadi pointer ke char, agar bisa diakses sebagai array char.
			((char *)TT + i) menunjuk ke elemen ke-i dari array karakter.
			f(...) memanggil fungsi f, yang bisa berupa succC atau predC.
			Jika f adalah succC, maka TT[i] akan bergeser ke huruf berikutnya (misalnya 'A' jadi 'B').
			Jika f adalah predC, maka TT[i] akan bergeser ke huruf sebelumnya (misalnya 'B' jadi 'A').
			printf(" %c ", *((char *)TT + i));

			*((char *)TT + i) mengambil nilai dari elemen i dalam array karakter.
			%c digunakan untuk mencetak karakter.*/
		}
	}
	printf("\n");}

void printtab (void *T, enum MyType Ty){
	int i;
	for (i = 0; i < N; i ++){
		switch (Ty){
			case bulat : printf("%d ", *((int *)T + i)); break;
			case karakter : printf("%c ", *((char *)T + i)); break;}
		}
	printf("\n");
	}