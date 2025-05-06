#include "queue.h"
#include "linked.h"

void enqueue(Queue *Q, address node, addrBuku book) {
    if (Q == NULL || node == NULL || book == NULL) {
        printf("Error: Invalid queue, node, or book\n");
        return;
    }
    if (node->info == NULL) {
        printf("Error: Node info is NULL\n");
        return;
    }
    node->next = NULL;
    printf("Enqueue: Adding %s (priority %d) for book %s\n", node->info, node->priority, book->info);
    if (isEmpty(Q->head)) {
        Q->head = node;
        Q->tail = node;
        node->next = book;
        printf("Enqueued %s as head, tail=%s, points to book %s\n", node->info, Q->tail->info, book->info);
    } else {
        address current = Q->head;
        address prev = NULL;
        while (current != NULL && current != book && current->priority <= node->priority) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            node->next = Q->head;
            Q->head = node;
            printf("Enqueued %s as new head, points to %s\n", node->info, node->next->info);
        } else if (current == book || current == NULL) {
            prev->next = node;
            node->next = book;
            Q->tail = node;
            printf("Enqueued %s at tail, points to book %s\n", node->info, book->info);
        } else {
            prev->next = node;
            node->next = current;
            printf("Enqueued %s between %s and %s\n", node->info, prev->info, current->info);
        }
    }
}

void dequeue(Queue *Q, infotype *nilai) {
    if (Q == NULL || isEmpty(Q->head)) {
        printf("Dequeue failed: Empty queue\n");
        *nilai = NULL;
        return;
    }
    address temp = Q->head;
    *nilai = temp->info;
    Q->head = temp->next;
    if (Q->head == NULL || Q->head == Q->tail->next) {
        Q->tail = NULL;
        printf("Dequeued %s, queue now empty\n", *nilai);
    } else {
        printf("Dequeued %s, new head %s\n", *nilai, Q->head->info);
    }
    temp->next = NULL;
    free(temp);
}

void createinitQueue(Queue *Q) {
    if (Q == NULL) {
        printf("Error: NULL queue\n");
        return;
    }
    Q->head = NULL;
    Q->tail = NULL;
    printf("Initialized queue: head=%p, tail=%p\n", (void*)Q->head, (void*)Q->tail);
}

void ExitQueue(Queue *Q) {
    if (Q == NULL) return;
    address temp;
    while (Q->head != NULL && Q->head != Q->tail->next) {
        temp = Q->head;
        Q->head = temp->next;
        if (temp->info != NULL) free(temp->info);
        free(temp);
    }
    Q->tail = NULL;
    printf("Queue cleared\n");
}