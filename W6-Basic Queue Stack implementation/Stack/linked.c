#include "linked.h"

boolean isEmpty(address p) {
    return p == nil;
}

void CreateEmpty(address *q) {
    *q = nil;
}

void Create_Node(address *p) {
    *p = (address)malloc(sizeof(ElmtList));
}

void Isi_Node(address *p, infotype nilai) {
    if (*p != nil) {
        (*p)->info = nilai;
        (*p)->next = nil;
    }
}

void Tampil_List(address p) {
    while (p != nil) {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("null\n");
}

address Search(address p, infotype nilai) {
    while (p != nil) {
        if (p->info == nilai) {
            return p;
        }
        p = p->next;
    }
    return nil;
}

void Ins_Awal(address *p, address PNew) {
    if (isEmpty(*p)) {
        *p = PNew;
    } else {
        PNew->next = *p;
        *p = PNew;
    }
}

void Ins_Akhir(address *p, address PNew) {
    if (isEmpty(*p)) {
        *p = PNew;
    } else {
        address temp = *p;
        while (temp->next != nil) {
            temp = temp->next;
        }
        temp->next = PNew;
    }
}

void InsertAfter(address *pBef, address PNew) {
    if (*pBef != nil) {
        PNew->next = (*pBef)->next;
        (*pBef)->next = PNew;
    }
}

void Del_Awal(address *p, infotype *X) {
    if (!isEmpty(*p)) {
        address temp = *p;
        *X = temp->info;
        *p = temp->next;
        free(temp);
    }
}

void Del_Akhir(address *p, infotype *X) {
    if (isEmpty(*p)) return;

    if ((*p)->next == nil) {
        *X = (*p)->info;
        free(*p);
        *p = nil;
    } else {
        address temp = *p;
        while (temp->next->next != nil) {
            temp = temp->next;
        }
        *X = temp->next->info;
        free(temp->next);
        temp->next = nil;
    }
}

void DeleteValue(address *p, infotype target, infotype *X) {
    if (*p == nil) {
        return;
    }

    if ((*p)->info == target) {
        Del_Awal(p, X);
        return;
    }

    address prev = *p;
    address temp = prev->next;

    while (temp != nil && temp->info != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != nil) {
        *X = temp->info;
        prev->next = temp->next;
        free(temp);
    }
}



void DeAlokasi(address *p) {
    address temp;
    while (*p != nil) {
        temp = *p;
        *p = (*p)->next;
        free(temp);
    }
}

int NbElmt(address p) {
    if (p == nil) return 0;
    return 1 + NbElmt(p->next);
}