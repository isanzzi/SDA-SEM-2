#include "queue.h"

void enqueue(Queue *Q, infotype nilai) {
    // Create new string copy
    char* newStr = (char*)malloc(strlen(nilai) + 1);
    strcpy(newStr, nilai);
    
    address P = SetNode(&newStr);
    if (P == nil) {
        free(newStr);
        return;
    }
    
    if (isEmpty(Q->head)) {
        Q->head = P;
        Q->tail = P;
    } else {
        Ins_Akhir(&(Q->tail), P);
        Q->tail = P;
    }
}

void SongNow (Queue *Q){
    if (!isEmpty(Q->head)){
        printf ("%s", Q->head->info);    
    } else {
        printf ("queue is empty");
    }
    printf ("\n");
}

void PrintNextSong (Queue *Q){
    printf ("Next song will be : ");
    if (!isEmpty(Q->head) && Q->head->next != nil) {
        printf ("%s", Q->head->next->info);
    } else {
        printf ("no next song in queue");
    }
    printf ("\n");
}

void dequeue (Queue *Q, infotype *nilai){
    if (!isEmpty(Q->head)) {
        Del_Awal(&Q->head, nilai);
        if (Q->head == nil) {
            Q->tail = nil;
        }
    }
}

void dequeueandprint(Queue *Q) {
    infotype nilai;
    if (!isEmpty(Q->head)) {
        dequeue(Q, &nilai);
        printf("Lagu yang telah selesai adalah %s\n", nilai);
    } else {
        printf("Queue kosong\n");
    }
}

void createinitQueue(Queue *Q1){
    Q1->head = nil;
    Q1->tail = nil;
}

void ExitQueue (Queue *Q1){
    DeAlokasi(&(Q1->head));
    Q1->tail = nil;
}