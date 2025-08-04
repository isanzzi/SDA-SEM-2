#include "mahasiswa.h"
#include <string.h>

// Creator/Constructor
mahasiswa DataMahasiswa(char *nama, int nilai) {
    mahasiswa mhsw;
    mhsw.nama = strdup(nama); // Uses strdup instead of malloc + strcpy
    if (!mhsw.nama) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    mhsw.nilai = nilai;
    return mhsw;
}

// Validator
boolean isSameName(mahasiswa mhs1, mahasiswa mhs2) {
    if (mhs1.nama == NULL || mhs2.nama == NULL) {
        return false;
    }
    return (strcmp(mhs1.nama, mhs2.nama) == 0);
}

boolean isHigherGrade(mahasiswa mhs1, mahasiswa mhs2) {
    return mhs1.nilai > mhs2.nilai;
}

// Getter
char *getNama(mahasiswa mhsw) {
    return mhsw.nama;
}

int getNilai(mahasiswa mhsw) {
    return mhsw.nilai;
}

// Setter
void modifyNama(mahasiswa *mhsw, char *newNama) {
    if (mhsw->nama != NULL) {
        free(mhsw->nama);
    }
    
    mhsw->nama = (char*)malloc(strlen(newNama) + 1);
    if (mhsw->nama == NULL) {
        fprintf(stderr, "Memory allocation failed for new nama\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(mhsw->nama, newNama);
}

void modifyNilai(mahasiswa *mhsw, int newNilai) {
    mhsw->nilai = newNilai;
}

// PrintObject
void printMahasiswa(mahasiswa mhsw) {
    printf("Nama: %s, Nilai UTS SDA: %d\n", mhsw.nama, mhsw.nilai);
}

// Destructor for mahasiswa
void freeMahasiswa(mahasiswa *mhsw) {
    if (mhsw->nama != NULL) {
        free(mhsw->nama);
        mhsw->nama = NULL;
    }
}