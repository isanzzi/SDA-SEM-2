#ifndef queue_H
#define queue_H

#include "convention.h"
#include "linked.h"

typedef struct {
    address head;
    address tail;
} Queue;

void SongNow(Queue *Q);

void PrintNextSong (Queue *Q);

void enqueue (Queue *Q, infotype nilai);

void dequeue (Queue *Q, infotype *nilai);

void dequeueandprint (Queue *Q);

void createinitQueue(Queue *Q1);

void ExitQueue (Queue *Q1);

#endif