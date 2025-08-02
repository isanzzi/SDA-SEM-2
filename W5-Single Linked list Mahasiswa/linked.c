#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"
#include "mahasiswa.h"

address First(List L) {
    return L.first;
}

address Next(address P) {
    return P->next;
}

infotype Info(address P) {
    return P->info;
}

void CreateEmpty(List *L) {
    L->first = nil;
}

boolean isEmpty(List L) {
    return (L.first == nil);
}

boolean isOneElmt(List L) {
    return (!isEmpty(L) && L.first->next == nil);
}

address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (!P) return nil;
    
    P->info.nama = strdup(X.nama);
    if (!P->info.nama) {
        free(P);
        return nil;
    }
    
    P->info.nilai = X.nilai;
    P->next = nil;
    return P;
}

void Dealokasi(address *P) {
    if (*P != nil) {
        if ((*P)->info.nama != nil) {
            free((*P)->info.nama);
            (*P)->info.nama = nil;
        }
        
        free(*P);
        *P = nil;
    }
}

// Insert functions
void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != nil) {
        P->next = L->first;
        L->first = P;
    }
}

void InsVLast(List *L, infotype X) {
    if (isEmpty(*L)) {
        InsVFirst(L, X);
    } else {
        address P = Alokasi(X);
        if (P != nil) {
            address last = L->first;
            while (last->next != nil) {
                last = last->next;
            }
            last->next = P;
        }
    }
}

// Delete functions
void DelVFirst(List *L, infotype *X) {
    if (!isEmpty(*L)) {
        address P = L->first;
        
        if (X != NULL) {
            X->nama = (char*)malloc(strlen(P->info.nama) + 1);
            if (X->nama != nil) {
                strcpy(X->nama, P->info.nama);
            }
            X->nilai = P->info.nilai;
        }
        
        L->first = P->next;
        
        free(P->info.nama);
        free(P);
    }
}

void DelVLast(List *L, infotype *X) {
    if (isOneElmt(*L)) {
        DelVFirst(L, X);
    } else if (!isEmpty(*L)) {
        address last = L->first;
        address precLast = nil;
        
        while (last->next != nil) {
            precLast = last;
            last = last->next;
        }
        
        if (X != NULL) {
            X->nama = (char*)malloc(strlen(last->info.nama) + 1);
            if (X->nama != nil) {
                strcpy(X->nama, last->info.nama);
            }
            X->nilai = last->info.nilai;
        }
        
        precLast->next = nil;
        
        free(last->info.nama);
        free(last);
    }
}

int NbElmt(List L) {
    int count = 0;
    address P = L.first;
    while (P != nil) {
        count++;
        P = P->next;
    }
    return count;
}

void PrintInfo(List L) {
    printf("List mahasiswa (ascending by nama):\n");
    if (isEmpty(L)) {
        printf("List kosong\n");
    } else {
        address P = L.first;
        int i = 1;
        while (P != nil) {
            printf("%d. %s, Nilai UTS SDA: %d\n", i, P->info.nama, P->info.nilai);
            P = P->next;
            i++;
        }
    }
    printf("\n");
}

void PrintInfoDescendingByNilai(List L) {
    printf("List mahasiswa (descending by nilai):\n");
    if (isEmpty(L)) {
        printf("List kosong\n");
    } else {
        // Buat list sementara
        List tempL;
        CreateEmpty(&tempL);
        
        // Salin semua node ke list sementara
        address P = L.first;
        while (P != nil) {
            mahasiswa mhs = DataMahasiswa(P->info.nama, P->info.nilai);
            InsVLast(&tempL, mhs);
            freeMahasiswa(&mhs);
            P = P->next;
        }
        
        // Bubble sort dengan menukar pointer
        int count = NbElmt(tempL);
        boolean swapped;
        
        for (int i = 0; i < count - 1; i++) {
            address prev = nil;
            address curr = tempL.first;
            swapped = false;
            
            for (int j = 0; j < count - i - 1; j++) {
                address next = curr->next;
                
                if (curr->info.nilai < next->info.nilai) {
                    // Swap nodes
                    if (prev == nil) {
                        // Swap first node
                        tempL.first = next;
                        curr->next = next->next;
                        next->next = curr;
                    } else {
                        // Swap dalam list
                        prev->next = next;
                        curr->next = next->next;
                        next->next = curr;
                    }
                    swapped = true;
                    prev = next;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }
            
            if (!swapped) {
                break;
            }
        }
        
        // Print hasil pengurutan
        P = tempL.first;
        int i = 1;
        while (P != nil) {
            printf("%d. %s, Nilai UTS SDA: %d\n", i, P->info.nama, P->info.nilai);
            P = P->next;
            i++;
        }
        
        // Dealokasi list sementara
        DeAlokasi(&tempL);
    }
    printf("\n");
}

// Additional functions for the assignment
void InsertAscending(List *L, infotype X) {
    if (isEmpty(*L) || strcmp(X.nama, L->first->info.nama) < 0) {
        InsVFirst(L, X);
    } else {
        address P = L->first;
        address Prec = nil;
        
        while (P != nil && strcmp(X.nama, P->info.nama) > 0) {
            Prec = P;
            P = P->next;
        }
        
        // Create new node
        address newNode = Alokasi(X);
        if (newNode != nil) {
            if (P == nil) {  // Insert at the end
                Prec->next = newNode;
            } else {  // Insert in the middle
                newNode->next = P;
                Prec->next = newNode;
            }
        }
    }
}

void CopyGreaterThan(List source, List *dest, int threshold) {
    // Inisialisasi list tujuan sebagai list kosong
    CreateEmpty(dest);
    
    // Mulai dari elemen pertama list sumber
    address current = source.first;
    
    // Iterasi setiap elemen dalam list sumber
    while (current != nil) {
        // Jika nilai mahasiswa lebih besar dari threshold
        if (current->info.nilai > threshold) {
            // Buat salinan data mahasiswa
            mahasiswa mhs;
            mhs.nama = strdup(current->info.nama);
            mhs.nilai = current->info.nilai;
            
            // Masukkan ke list tujuan
            InsVLast(dest, mhs);
            
            // Bersihkan salinan sementara
            free(mhs.nama);
        }
        // Lanjut ke elemen berikutnya
        current = current->next;
    }
}

void RemoveDuplicates(List *L) {
    if (!isEmpty(*L) && !isOneElmt(*L)) {
        address P = L->first;
        
        while (P != nil) {
            address Q = P->next;
            address PrecQ = P;
            
            while (Q != nil) {
                if (strcmp(P->info.nama, Q->info.nama) == 0) {
                    // Remove the duplicate (Q)
                    address temp = Q;
                    Q = Q->next;
                    PrecQ->next = Q;
                    
                    // Free the node
                    free(temp->info.nama);
                    free(temp);
                } else {
                    PrecQ = Q;
                    Q = Q->next;
                }
            }
            
            P = P->next;
        }
    }
}

// Destructor - completely rewritten
void DeAlokasi(List *L) {
    if (isEmpty(*L)) {
        return;  // Nothing to deallocate
    }
    
    address P = L->first;
    address temp;
    
    while (P != nil) {
        temp = P;
        P = P->next;
        
        // Free the mahasiswa name
        if (temp->info.nama != nil) {
            free(temp->info.nama);
            temp->info.nama = nil;
        }
        
        // Free the node
        free(temp);
    }
    
    // Reset the list
    L->first = nil;
}