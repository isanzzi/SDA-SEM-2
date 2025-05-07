#ifndef queue_H
#define queue_H

#include "conventionarray.h"
#include "linkedarray.h"

typedef struct {
    addressarray head;
    addressarray tail;
} Queuearray;

void SongNowArray(Queuearray *Q);
void PrintNextSongArray(Queuearray *Q);
void enqueueArray(Queuearray *Q, addressarray node);
void dequeueArray(Queuearray *Q, infotype *nilai);
void dequeueandprintArray(Queuearray *Q);
void createinitQueueArray(Queuearray *Q1);
void ExitQueueArray(Queuearray *Q1);
addressarray searchbeforepriorityArray(addressarray head);

#endif