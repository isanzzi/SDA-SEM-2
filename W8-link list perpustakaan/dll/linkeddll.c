#include "linkeddll.h"

boolean isEmptydll(addressdll p) {
    if (p==nil){
        return true;
    } else{
        return false;
    }
}

void CreateEmptydll(addressdll *q) {
    *q = nil;
}

void Create_Nodedll(addressdll *p) {
    *p = (addressdll)malloc(sizeof(Anggotadll));
}

void Isi_Nodedll(addressdll *p, infotype nama, int prior) {
    if (*p != nil) {
        info(*p) = nama;
        lvl(*p) = prior;
        next(*p) = nil;
        (*p)->history.top = NULL;
    }
}

char* InsertTitledll(){
    char *P = (char*) malloc (50 *sizeof(char));
    if (P == nil){
        printf ("allocation title failed\n");
        return nil;
    }
    printf ("Masukkan judul buku : ");
    scanf (" %[^\n]s", P);
    return P;
}

char* insertNamadll(){
    char *P = (char*) malloc (50 *sizeof(char));
    if (P == nil){
        printf ("allocation name failed\n");
        return nil;
    }
    printf ("input nama: ");
    scanf (" %[^\n]s", P);
    return P;
}

addressdll SetNodedll(infotype *nilai, int prior){
    addressdll P;
    Create_Nodedll(&P);
    if (P == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    info(P) = *nilai;
    next(P) = nil;
    lvl(P) = prior;
    return P;
}

void Tampil_Listdll(addressdll p) {
    if (isEmptydll(p)) {
        printf("Empty List\n");
        return;
    }
    
    addressdll temp = p;
    while (temp != nil) {
        printf("%s", info(temp));
        if (next(temp) != nil) {
            printf(" -> ");
        }
        temp = next(temp);
    }
    printf("\n");
}

addressdll Searchdll(addressdll p, infotype nilai) {
    while (p != nil) {
        if (nilai != NULL && info(p) != NULL && strcmp(info(p), nilai) == 0) {
            return p;
        }
        p = next(p);
    }
    return nil;
}

void Ins_Awaldll(addressdll *p, addressdll PNew) {
    if (isEmptydll(*p)) {
        *p = PNew;
    } else {
        next(PNew) = *p;
        *p = PNew;
    }
}

void Ins_Akhirdll(addressdll *p, addressdll PNew) {
    if (isEmptydll(*p)) {
        *p = PNew;
    } else {
        addressdll temp = *p;
        while (next(temp) != nil) {
            temp = next(temp);
        }
        next(temp) = PNew;
    }
}

void modifiedIns_Akhirdll(addressdll *p, addressdll PNew) {
    if (isEmptydll(*p)) {
        *p = PNew;
        next(PNew) = NULL;
        return;
    }
    
    if (lvl(PNew) < lvl(*p)) {
        next(PNew) = *p;
        *p = PNew;
        return;
    }
    
    addressdll current = *p;
    addressdll prev = NULL;
    
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

void InsertAfterdll(addressdll *pBef, addressdll PNew) {
    if (*pBef != nil) {
        next(PNew) = next(*pBef);
        next(*pBef) = PNew;
    }
}

void Del_Awaldll(addressdll *p, infotype *X) {
    if (!isEmptydll(*p)) {
        addressdll temp = *p;
        *X = info(temp);
        *p = next(temp);
        free(temp);
    }
}

void Del_Akhirdll(addressdll *p, infotype *X) {
    if (isEmptydll(*p)) return;

    if (next(*p) == nil) {
        *X = info(*p);
        free(*p);
        *p = nil;
    } else {
        addressdll temp = *p;
        while (next(next(temp)) != nil) {
            temp = next(temp);
        }
        *X = info(next(temp));
        free(next(temp));
        next(temp) = nil;
    }
}

boolean DeleteValuedll(addressdll *p, infotype target, infotype *X) {
    if (*p == nil) {
        return false;
    }

    if (strcmp(info(*p), target) == 0) {
        *X = info(*p);
        addressdll temp = *p;
        *p = next(temp);
        next(temp) = nil; // Disconnect from list
        return true;
    }

    addressdll prev = *p;
    addressdll temp = next(prev);

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

void DeAlokasidll(addressdll *p) {
    addressdll temp;
    while (*p != nil) {
        temp = *p;
        *p = next(temp);
        if (info(temp) != NULL) {
            free(info(temp));
        }
        free(temp);
    }
}

int NbElmtdll(addressdll p) {
    if (p == nil) return 0;
    return 1 + NbElmtdll(next(p));
}

void ModifyStringdll(infotype *str) {
    printf("Current string: %s\n", *str);
    free(*str);  // Free old string
    *str = InsertTitledll();  // Allocate and assign new string
}

int initleveldll(){
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