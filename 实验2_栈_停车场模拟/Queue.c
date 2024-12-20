#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void InitQueue(Queue* Q) {
    Q->front = Q->rear = NULL;
}

bool IsEmpty(Queue* Q) {
    return Q->front == NULL;
}

void Enqueue(Queue* Q, SElemType e) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        exit(1);  // ·ÖÅäÄÚ´æÊ§°Ü
    }
    newNode->data = e;
    newNode->next = NULL;
    if (IsEmpty(Q)) {
        Q->front = Q->rear = newNode;
    }
    else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

void Dequeue(Queue* Q, SElemType* e) {
    if (IsEmpty(Q)) {
        return;
    }
    QueueNode* temp = Q->front;
    *e = temp->data;
    Q->front = Q->front->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    free(temp);
}

void DestroyQueue(Queue* Q) {
    while (!IsEmpty(Q)) {
        SElemType e;
        Dequeue(Q, &e);
    }
}