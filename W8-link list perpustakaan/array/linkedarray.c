#include "linkedarray.h"

boolean isEmptyarray(addressarray p) {
    if (p==nil){
        return true;
    } else{
        return false;
    }
}

void CreateEmptyarray(addressarray *q) {
    *q = nil;
}

void Create_Nodearray(addressarray *p) {
    *p = (addressarray)malloc(sizeof(Anggotaarray));
}

void Isi_Nodearray(addressarray *p, infotype nama, int prior) {
    if (*p != nil) {
        info(*p) = nama;
        lvl(*p) = prior;
        next(*p) = nil;
        (*p)->history.top = NULL;
    }
}

char* InsertTitleArray(){
    char *P = (char*) malloc (50 *sizeof(char));
    if (P == nil){
        printf ("allocation title failed\n");
        return nil;
    }
    printf ("Masukkan judul buku : ");
    scanf (" %[^\n]s", P);
    return P;
}

char* insertNamaArray(){
    char *P = (char*) malloc (50 *sizeof(char));
    if (P == nil){
        printf ("allocation name failed\n");
        return nil;
    }
    printf ("input nama: ");
    scanf (" %[^\n]s", P);
    return P;
}

addressarray SetNodeArray (infotype *nilai, int prior){
    addressarray P;
    Create_Nodearray (&P);
    if (P == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    info(P) = *nilai;
    next(P) = nil;
    lvl(P) = prior;
    return P;
}

void Tampil_ListArray(addressarray p) {
    if (isEmptyarray(p)) {
        printf("Empty List\n");
        return;
    }
    
    addressarray temp = p;
    while (temp != nil) {
        printf("%s", info(temp));
        if (next(temp) != nil) {
            printf(" -> ");
        }
        temp = next(temp);
    }
    printf("\n");
}

addressarray SearchArray(addressarray p, infotype nilai) {
    while (p != nil) {
        if (nilai != NULL && info(p) != NULL && strcmp(info(p), nilai) == 0) {
            return p;
        }
        p = next(p);
    }
    return nil;
}

void Ins_AwalArray(addressarray *p, addressarray PNew) {
    if (isEmptyarray(*p)) {
        *p = PNew;
    } else {
        next(PNew) = *p;
        *p = PNew;
    }
}

void Ins_AkhirArray(addressarray *p, addressarray PNew) {
    if (isEmptyarray(*p)) {
        *p = PNew;
    } else {
        addressarray temp = *p;
        while (next(temp) != nil) {
            temp = next(temp);
        }
        next(temp) = PNew;
    }
}

void modifiedIns_AkhirArray(addressarray *p, addressarray PNew) {
    if (isEmptyarray(*p)) {
        *p = PNew;
        next(PNew) = NULL;
        return;
    }
    
    if (lvl(PNew) < lvl(*p)) {
        next(PNew) = *p;
        *p = PNew;
        return;
    }
    
    addressarray current = *p;
    addressarray prev = NULL;
    
    while (current != NULL && lvl(current) <= lvl(PNew)) {
        if (lvl(current) > lvl(PNew)) {
            break;
        }
        prev = current;
        current = next(current);
    }
    
    next(prev) = PNew;
    next(PNew) = current;
}

void InsertAfterArray(addressarray *pBef, addressarray PNew) {
    if (*pBef != nil) {
        next(PNew) = next(*pBef);
        next(*pBef) = PNew;
    }
}

void Del_AwalArray(addressarray *p, infotype *X) {
    if (!isEmptyarray(*p)) {
        addressarray temp = *p;
        *X = info(temp);
        *p = next(temp);
        free(temp);
    }
}

void Del_AkhirArray(addressarray *p, infotype *X) {
    if (isEmptyarray(*p)) return;

    if (next(*p) == nil) {
        *X = info(*p);
        free(*p);
        *p = nil;
    } else {
        addressarray temp = *p;
        while (next(next(temp)) != nil) {
            temp = next(temp);
        }
        *X = info(next(temp));
        free(next(temp));
        next(temp) = nil;
    }
}

boolean DeleteValueArray(addressarray *p, infotype target, infotype *X) {
    if (*p == nil) {
        return false;
    }

    if (strcmp(info(*p), target) == 0) {
        *X = info(*p);
        addressarray temp = *p;
        *p = next(temp);
        next(temp) = nil; // Disconnect from list
        return true;
    }

    addressarray prev = *p;
    addressarray temp = next(prev);

    while (temp != nil && strcmp(info(temp), target) != 0) {
        prev = temp;
        temp = next(temp);
    }

    if (temp != nil) {
        *X = info(temp);
        next(prev) = next(temp);
        next(temp) = nil; // Disconnect from list
        return true;
    }
    
    return false; // Not found
}

void DeAlokasiArray(addressarray *p) {
    addressarray temp;
    while (*p != nil) {
        temp = *p;
        *p = next(temp);
        free(temp);
    }
}

int NbElmtArray(addressarray p) {
    if (p == nil) return 0;
    return 1 + NbElmtArray(next(p));
}

void ModifyStringArray(infotype *str) {
    printf("Current string: %s\n", *str);
    free(*str);  // Free old string
    *str = InsertTitleArray();  // Allocate and assign new string
}

int initlevelArray(){
    printf("Masukkan level prioritas (1=Dosen, 2=Mahasiswa, 3=Umum): ");
    int level;
    scanf("%d", &level);
    getchar();
    
    while (level <1 && level >3){
        printf("Level tidak valid!\n");
        scanf("%d", &level);
        getchar();
    }

    return level;
}