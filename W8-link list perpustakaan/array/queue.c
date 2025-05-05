#include "queue.h"

void enqueue(Queue *Q, address node) {
    if (isEmpty(Q->head)) {
        Q->head = node;
        Q->tail = node;
        node->next = NULL;
        return;
    } else {
        modifiedIns_Akhir(&(Q->head), node);
        address temp = Q->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Q->tail = temp;
    }
}

address searchbeforepriority (address head){
    if (head==NULL || head->next ==NULL){
        printf ("List kosong");
        return NULL;
    }
    address temp = head;
    while (temp != NULL){
        if (temp->next->level==1){
            return temp;
        }
        temp=temp->next;
    }
    temp=head;
    while (temp != NULL){
        if (temp->next->level==2){
            return temp;
        }
        temp=temp->next;
    }
    temp=head;
    while (temp != NULL){
        if (temp->next->level==3){
            return temp;
        }
        temp=temp->next;
    }

    return NULL;
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