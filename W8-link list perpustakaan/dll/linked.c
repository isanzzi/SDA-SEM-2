#include "linked.h"

boolean isEmpty(address p) {
    if (p==nil){
        return true;
    } else{
        return false;
    }
}

void CreateEmpty(address *q) {
    *q = nil;
}

void Create_Node(address *p) {
    *p = (address)malloc(sizeof(Anggota));
}

void Isi_Node(address *p, infotype nama, int prior) {
    if (*p != nil) {
        info(*p) = nama;
        lvl(*p) = prior;
        next(*p) = nil;
        (*p)->history.top = NULL;
    }
}

char* InsertTitle(){
    char *P = (char*) malloc (50 *sizeof(char));
    if (P == nil){
        printf ("allocation title failed\n");
        return nil;
    }
    printf ("Masukkan judul buku : ");
    scanf (" %[^\n]s", P);
    return P;
}

char* insertNama(){
    char *P = (char*) malloc (50 *sizeof(char));
    if (P == nil){
        printf ("allocation name failed\n");
        return nil;
    }
    printf ("input nama: ");
    scanf (" %[^\n]s", P);
    return P;
}

address SetNode (infotype *nilai, int prior){
    address P;
    Create_Node (&P);
    if (P == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    info(P) = *nilai;
    next(P) = nil;
    lvl(P) = prior;
    return P;
}

void Tampil_List(address p) {
    if (isEmpty(p)) {
        printf("Empty List\n");
        return;
    }
    
    address temp = p;
    while (temp != nil) {
        printf("%s", info(temp));
        if (next(temp) != nil) {
            printf(" -> ");
        }
        temp = next(temp);
    }
    printf("\n");
}

address Search(address p, infotype nilai) {
    while (p != nil) {
        if (nilai != NULL && info(p) != NULL && strcmp(info(p), nilai) == 0) {
            return p;
        }
        p = next(p);
    }
    return nil;
}

void Ins_Awal(address *p, address PNew) {
    if (isEmpty(*p)) {
        *p = PNew;
    } else {
        next(PNew) = *p;
        *p = PNew;
    }
}

void Ins_Akhir(address *p, address PNew) {
    if (isEmpty(*p)) {
        *p = PNew;
    } else {
        address temp = *p;
        while (next(temp) != nil) {
            temp = next(temp);
        }
        next(temp) = PNew;
    }
}

void modifiedIns_Akhir(address *p, address PNew) {
    if (isEmpty(*p)) {
        *p = PNew;
        next(PNew) = NULL;
        return;
    }
    
    if (lvl(PNew) < lvl(*p)) {
        next(PNew) = *p;
        *p = PNew;
        return;
    }
    
    address current = *p;
    address prev = NULL;
    
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

void InsertAfter(address *pBef, address PNew) {
    if (*pBef != nil) {
        next(PNew) = next(*pBef);
        next(*pBef) = PNew;
    }
}

void Del_Awal(address *p, infotype *X) {
    if (!isEmpty(*p)) {
        address temp = *p;
        *X = info(temp);
        *p = next(temp);
        free(temp);
    }
}

void Del_Akhir(address *p, infotype *X) {
    if (isEmpty(*p)) return;

    if (next(*p) == nil) {
        *X = info(*p);
        free(*p);
        *p = nil;
    } else {
        address temp = *p;
        while (next(next(temp)) != nil) {
            temp = next(temp);
        }
        *X = info(next(temp));
        free(next(temp));
        next(temp) = nil;
    }
}

boolean DeleteValue(address *p, infotype target, infotype *X) {
    if (*p == nil) {
        return false;
    }

    if (strcmp(info(*p), target) == 0) {
        *X = info(*p);
        address temp = *p;
        *p = next(temp);
        next(temp) = nil; // Disconnect from list
        return true;
    }

    address prev = *p;
    address temp = next(prev);

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

void DeAlokasi(address *p) {
    address temp;
    while (*p != nil) {
        temp = *p;
        *p = next(temp);
        if (info(temp) != NULL) {
            free(info(temp));
        }
        free(temp);
    }
}

int NbElmt(address p) {
    if (p == nil) return 0;
    return 1 + NbElmt(next(p));
}

void ModifyString(infotype *str) {
    printf("Current string: %s\n", *str);
    free(*str);  // Free old string
    *str = InsertTitle();  // Allocate and assign new string
}

int initlevel(){
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