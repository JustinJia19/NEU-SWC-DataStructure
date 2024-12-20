#ifndef QUEUE_H
#define QUEUE_H
# include "Stack.h"

#include <stdbool.h>

typedef struct QueueNode {
    SElemType data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void InitQueue(Queue* Q);
bool IsEmpty(Queue* Q);
void Enqueue(Queue* Q, SElemType e);
void Dequeue(Queue* Q, SElemType* e);
void DestroyQueue(Queue* Q);

#endif