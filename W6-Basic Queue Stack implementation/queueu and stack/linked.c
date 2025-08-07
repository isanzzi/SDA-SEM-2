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
    *p = (address)malloc(sizeof(ElmtList));
}

void Isi_Node(address *p, infotype nilai) {
    if (*p != nil) {
        info(*p) = nilai;
        next(*p) = nil;
    }
}

char* InsertTitle (){
    char *P = (char*) malloc (50 *sizeof(char));
    if (P!=nil){
        printf ("Inser title of song : ");
        scanf (" %[^\n]s", P);
        return P;
    } else {
        printf ("allocation title failed");
        return nil;
    }
}

address SetNode (infotype *nilai){
    address P;
    Create_Node (&P);
    info(P) = *nilai;
    next(P) = nil;
    return P;
}

void Tampil_List(address p) {
    if (isEmpty(p)) {
        printf("List Kosong\n");
        return;
    }
    while (p != nil) {
        printf("%s -> ", info(p));
        p = next(p);
    }
    printf("null\n");
}

address Search(address p, infotype nilai) {
    while (p != nil) {
        if (info(p) == nilai) {
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

void DeleteValue(address *p, infotype target, infotype *X) {
    if (*p == nil) {
        return;
    }

    if (info(*p) == target) {
        Del_Awal(p, X);
        return;
    }

    address prev = *p;
    address temp = next(prev);

    while (temp != nil && info(temp) != target) {
        prev = temp;
        temp = next(temp);
    }

    if (temp != nil) {
        *X = info(temp);
        next(prev) = next(temp);
        free(temp);
    }
}

void DeAlokasi(address *p) {
    address temp;
    while (*p != nil) {
        temp = *p;
        *p = next(temp);
        free(temp);
    }
}

int NbElmt(address p) {
    if (p == nil) return 0;
    return 1 + NbElmt(next(p));
}