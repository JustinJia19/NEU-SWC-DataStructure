#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void InitStack(SqStack* S) {
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) exit(1);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack* S) { // 新增销毁栈函数
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->stacksize = 0;
}

void Push(SqStack* S, SElemType e) {
    if (S->top - S->base == S->stacksize) {
        S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base) exit(1);
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top = e;
    S->top++;
}

int StackTraverse(SqStack* S) {
    SElemType* p;
    p = S->base;
    while (p != S->top) {
        printf("Plate: %s, Move Count: %d\n", p->plate, p->moveCount);
        p++;
    }
    return 1;
}

void Pop(SqStack* S, SElemType* e) {
    if (S->top == S->base) return;
    S->top--;
    *e = *S->top;
}

SElemType GetTop(SqStack* S) {
    if (S->top != S->base)
        return *(S->top - 1);
    else {
        SElemType emptyCar = { .plate = "", .moveCount = 0 };
        return emptyCar;
    }
}

int StackLength(SqStack* S) {
    return S->top - S->base;
}

int StackEmpty(SqStack* S) {
    return (S->top == S->base);
}