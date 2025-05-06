#ifndef queue_H
#define queue_H
#include "convention.h"

typedef struct {
    address head;
    address tail;
} Queue;

void createinitQueue(Queue *Q);
void enqueue(Queue *Q, address node, addrBuku book);
void dequeue(Queue *Q, infotype *nilai);
void ExitQueue(Queue *Q);

#endif