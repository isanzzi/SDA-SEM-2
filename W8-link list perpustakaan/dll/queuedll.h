#ifndef queue_H
#define queue_H

#include "conventiondll.h"
#include "linkeddll.h"

typedef struct {
    addressdll head;
    addressdll tail;
} Queuedll;

void SongNowdll(Queuedll *Q);

void PrintNextSongdll(Queuedll *Q);

void enqueuedll(Queuedll *Q, addressdll node);

void dequeuedll(Queuedll *Q, infotype *nilai);

void dequeueandprintdll(Queuedll *Q);

void createinitQueuedll(Queuedll *Q1);

void ExitQueuedll(Queuedll *Q1);

addressdll searchbeforeprioritydll(addressdll head);

#endif