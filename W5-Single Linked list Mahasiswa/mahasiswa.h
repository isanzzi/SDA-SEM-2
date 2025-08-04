#ifndef mahasiswa_H
#define mahasiswa_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

typedef struct {
    char *nama; //string dengan alokasi dinamis
    int nilai;
} mahasiswa;

// Creator/Constructor
mahasiswa DataMahasiswa(char *nama, int nilai);

// Validator
boolean isSameName(mahasiswa mhs1, mahasiswa mhs2);
boolean isHigherGrade(mahasiswa mhs1, mahasiswa mhs2);

// Getter
char *getNama(mahasiswa mhsw);
int getNilai(mahasiswa mhsw);

// Setter
void modifyNama(mahasiswa *mhsw, char *newNama);
void modifyNilai(mahasiswa *mhsw, int newNilai);

// PrintObject
void printMahasiswa(mahasiswa mhsw);

// Destructor for mahasiswa
void freeMahasiswa(mahasiswa *mhsw);

#endif