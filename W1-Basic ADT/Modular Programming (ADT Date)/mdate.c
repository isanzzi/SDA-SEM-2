/* Nama Program : mdate.c
	Deskripsi : Driver untuk menggunakan unit ADT Date
			yang ada di date.h dan date.c
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "date.h"

/* P R O G R A M   U T A M A   */
int main(){
	 date D1, D2, D3;
	 char lagi = 'y';

	/* Algoritma : Procedure yang isi bodynya call thd semua feature yang ada */
	for (;;){
		system("cls"); //lakukan clear screen;
		CreateDate (&D1);
		printf ("\nmaka D1 bernilai : ");
		PrintObj (D1);

		ReadDate(&D2);//lakukan set tanggal, bulan, dan tahun, simpan hasil ke var D2
		while(!isValid(D2)){
			printf("tanggal tidak valid\n");
			ReadDate(&D2);
		}
		printf("\nmaka D2 bernilai:");
		PrintObj (D2);//tampilkan D2
		if(isKabisat(D2)){
			printf("%d", GetThn(D2));
			printf(" adalah tahun Kabisat\n");
		}

		DateBefore(D2);
		NextDate(D2);

		ReadDate(&D3);
		while(!isValid(D3)){
			printf("tanggal tidak valid\n");
			ReadDate(&D3);
		}

		printf("setelah perintah BacaDate(&D3), maka d3 bernilai : ");
		PrintObj(D3);
		
		printf("selisih antara");
		PrintObj(D2);
		printf(" dan ");
		PrintObj(D3);
		printf("adalah\n");

		DifferenceDate(D2,D3);
		//dan seterusnya uji semua modul yang ada di file body 
		//spesification-nya (date.cpp) dengan cara memanggil dari driver 
		//(modul main) ini
		
		printf("Coba lagi? (y/t)");
		if(_getch()!=lagi){
		break;
		}
	}
	return 0;
}