#include "queuearray.h"

void enqueueArray(Queuearray *Q, addressarray node) {
    if (isEmptyarray(Q->head)) {
        Q->head = node;
        Q->tail = node;
        node->next = NULL;
        return;
    } else {
        modifiedIns_AkhirArray(&(Q->head), node);
        addressarray temp = Q->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Q->tail = temp;
    }
}

addressarray searchbeforepriorityArray(addressarray head){
    if (head==NULL || head->next ==NULL){
        printf ("List kosong");
        return NULL;
    }
    addressarray temp = head;
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

void SongNowArray (Queuearray *Q){
    if (!isEmptyarray(Q->head)){
        printf ("%s", Q->head->info);    
    } else {
        printf ("queue is empty");
    }
    printf ("\n");
}

void PrintNextSongArray (Queuearray *Q){
    printf ("Next song will be : ");
    if (!isEmptyarray(Q->head) && Q->head->next != nil) {
        printf ("%s", Q->head->next->info);
    } else {
        printf ("no next song in queue");
    }
    printf ("\n");
}

void dequeueArray (Queuearray *Q, infotype *nilai){
    if (!isEmptyarray(Q->head)) {
        Del_AwalArray(&Q->head, nilai);
        if (Q->head == nil) {
            Q->tail = nil;
        }
    }
}

void dequeueandprintArray(Queuearray *Q) {
    infotype nilai;
    if (!isEmptyarray(Q->head)) {
        dequeueArray(Q, &nilai);
        printf("Lagu yang telah selesai adalah %s\n", nilai);
    } else {
        printf("Queue kosong\n");
    }
}

void createinitQueueArray(Queuearray *Q1){
    Q1->head = nil;
    Q1->tail = nil;
}

void ExitQueueArray (Queuearray *Q1){
    DeAlokasiArray(&(Q1->head));
    Q1->tail = nil;
}