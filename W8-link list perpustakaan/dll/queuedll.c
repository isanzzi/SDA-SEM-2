#include "queuedll.h"

void enqueuedll(Queuedll *Q, addressdll node) {
    if (isEmptydll(Q->head)) {
        Q->head = node;
        Q->tail = node;
        node->next = NULL;
        return;
    } else {
        modifiedIns_Akhirdll(&(Q->head), node);
        addressdll temp = Q->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Q->tail = temp;
    }
}

addressdll searchbeforeprioritydll(addressdll head){
    if (head==NULL || head->next ==NULL){
        printf ("List kosong");
        return NULL;
    }
    addressdll temp = head;
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

void SongNowdll(Queuedll *Q){
    if (!isEmptydll(Q->head)){
        printf ("%s", Q->head->info);    
    } else {
        printf ("queue is empty");
    }
    printf ("\n");
}

void PrintNextSongdll(Queuedll *Q){
    printf ("Next song will be : ");
    if (!isEmptydll(Q->head) && Q->head->next != nil) {
        printf ("%s", Q->head->next->info);
    } else {
        printf ("no next song in queue");
    }
    printf ("\n");
}

void dequeuedll(Queuedll *Q, infotype *nilai){
    if (!isEmptydll(Q->head)) {
        Del_Awaldll(&Q->head, nilai);
        if (Q->head == nil) {
            Q->tail = nil;
        }

    }
}

void dequeueandprintdll(Queuedll *Q) {
    infotype nilai;
    if (!isEmptydll(Q->head)) {
        dequeuedll(Q, &nilai);
        printf("Lagu yang telah selesai adalah %s\n", nilai);
    } else {
        printf("Queue kosong\n");
    }
}

void createinitQueuedll(Queuedll *Q1){
    Q1->head = nil;
    Q1->tail = nil;
}

void ExitQueuedll(Queuedll *Q1){
    DeAlokasidll(&(Q1->head));
    Q1->tail = nil;
}