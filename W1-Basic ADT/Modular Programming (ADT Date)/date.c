/* File        : date.c */
/* Deskripsi   : Unit untuk keperluan ADT Date */

/***************************/
/*  BODY PRIMITIF DATE     */
/***************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "date.h"

/*********** Operasi Primitif ************/
/* Constructor Membentuk sebuah DATE, dengan nilai default adalah 01/01/1900 */
void CreateDate (date * D){
	SetTgl (01, &(* D));
	SetBln (01, &(* D));
	SetThn (1900, &(* D));
}

/******* Selector komponen **********/
/* Mengambil bagian Tgl dari date */
int GetTgl (date D){
	return(D.Tgl);
	
}

/* Mengambil bagian Bln dari date */
int GetBln (date D){
	return(D.Bln);
}

/* Mengambil bagian Thn dari date */
int GetThn (date D){
	return(D.Thn);
}


/****** Pengubah komponen ******/
/* Memberi nilai untuk Tgl */
void SetTgl (int NewTgl, date * D){
	(* D).Tgl = NewTgl;
}

/* Memberi nilai untuk Bln */
void SetBln (int NewBln, date * D){
	(* D).Bln = NewBln;
}

/* Memberi nilai untuk Thn */
void SetThn (int NewThn, date * D){
	(* D).Thn = NewThn;
}


/****** Kelompok Interaksi dengan I/O device, BACA/TULIS ******/
/* Membentuk DATE dari iTgl, iBln dan iThn yang dibaca dari keyboard */
void ReadDate (date * D){
	int ktgl,kbln,kthn;
	printf("Tanggal : ");
	scanf("%d", &ktgl);
	printf("Bulan : ");
	scanf("%d", &kbln);
	printf("Tahun : ");
	scanf("%d", &kthn);
	SetTgl(ktgl, D);
	SetBln(kbln, D);
	SetThn(kthn, D);
	getchar();
}

/* Memeriksa apakah suatu tanggal valid, yaitu dengan memperhatikan batas akhir per bulan */
boolean isValid(date D){
	if ((GetThn(D) < 1900)||(GetThn(D) > 30000)||(GetBln(D) < 1) ||(GetBln(D) > 12)||(GetTgl(D) < 1)||(GetTgl(D) > getEndDate(D)))
		return (false);
	else
		return (true);
}

/* Print nilai D dengan format dd/mm/yyyy */
void PrintObj (date D){
	printf ("%d/%d/%d\n", GetTgl(D), GetBln(D), GetThn(D));
}

/****** Operator Relasional ******/
/* Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan == 2 saja
Harusnya kabisat adalah thn yang habis dibagi 4, atau habis dibagi 100 dan 400, tapi implementasinya seringkali hanya menggunakan 4 sebagai pembagi */
boolean isKabisat (date D){
	if(D.Thn%4==0){
		return true;
	}
	else{
		return false;
	}
}

/***** Predikat lain *******/
/* Memberikan tanggal terakhir dari sebuah bulan */
int getEndDate (date D){
	int bulan=GetBln(D);
	int tahun=GetThn(D);
	if(bulan<=7){
		if(bulan==2){
			if(tahun%4==0){
				return 29;
			}
			else{
				return 28;
			}
		} else if(bulan%2==0){
			return 30;
		}else{
			return 31;
		}
	}
	else{
		if(bulan%2==0){
			return 31;
		}
		else{
			return 30;
		}
	}
}

/* Menampilkan tanggal sebelumnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal sebelumnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika jan, thn-1 */
void DateBefore (date D){
	printf("\nsebelum tanggal : ");
	PrintObj (D);
	printf("adalah tanggal ");
	D.Tgl-=1;
	if(D.Tgl==0){
	D.Bln-=1;
	D.Tgl=getEndDate(D);
	}
	if(D.Bln==0){
		D.Tgl=31;
		D.Bln=12;
		D.Thn-=1;
	}
	PrintObj(D);
}

/* Menampilkan tanggal berikutnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal berikutnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika des, thn+1 */
void NextDate (date D){
	printf("\nsetelah tanggal : ");
	PrintObj (D);
	printf("adalah tanggal ");
	int akhirbulan=getEndDate(D);
	D.Tgl+=1;
	if(D.Tgl>akhirbulan){
		D.Tgl=1;
		D.Bln+=1;
		if(D.Bln==13){
			D.Tgl=1;
			D.Bln=1;
			D.Thn+=1;
		}
	}
	PrintObj (D);
}

/* Menampilkan selisih dua tanggal
	I.S = 2 buah Tanggal tertentu diketahui
	F.S = Tampil selisih dua buah tanggal
	Asumsi : 1 tahun = 365 hari */
void DifferenceDate (date D1, date D2){
	if(D1.Thn<D2.Thn){
		date temp = D1;
		D1 = D2;
		D2 = temp;
	} else if (D1.Bln<D2.Bln){
		date temp = D1;
		D1 = D2;
		D2 = temp;
	} else if(D1.Tgl<D2.Tgl){
		date temp = D1;
		D1 = D2;
		D2 = temp;
	}

	int count=1;
	while(D1.Tgl!=D2.Tgl || D1.Bln!=D2.Bln || D1.Thn!=D2.Thn){
		D1.Tgl-=1;
		if(D1.Tgl==0){
			D1.Bln-=1;
			D1.Tgl=getEndDate(D1);
		}
		if(D1.Bln==0){
			D1.Tgl=31;
			D1.Bln=12;
			D1.Thn-=1;
		}
		count++;
	}
	printf("%d hari\n\n", count);
}