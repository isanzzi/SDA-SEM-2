#ifndef queue_H
#define queue_H
#include "conventionsll.h"

typedef struct {
    addresssll head;
    addresssll tail;
} Queuesll;

void createinitQueuesll(Queuesll *Q);
void enqueuesll(Queuesll *Q, addresssll node, addrBukusll book);
void dequeuesll(Queuesll *Q, infotypesll *nilai);
void ExitQueuesll(Queuesll *Q);

#endif