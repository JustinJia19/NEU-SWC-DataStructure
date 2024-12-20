#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void InitStack(SqStack* S)
{
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) exit(1);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

void Push(SqStack* S, SElemType e)
{
    if (S->top - S->base >= S->stacksize)
    {
        S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base) exit(1);
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top = e;
    S->top++;
}

int StackTraverse(SqStack* S)
{
    SElemType* p;
    p = S->base;
    while (p != S->top)
    {
        printf("%f\n", *p);
        p++;
    }
    return 1;
}

void Pop(SqStack* S, SElemType* e)
{
    if (S->top == S->base)
        return;
    *e = *(S->top - 1);
    S->top--;
}

SElemType GetTop(SqStack* S)
{
    if (S->top != S->base)
        return *(S->top - 1);
    else
        return 0; // 或者返回一个特定的错误码
}

int StackLength(SqStack* S)
{
    return S->top - S->base;
}

int StackEmpty(SqStack* S)
{
    return (S->top == S->base);
}

void InitOpStack(OpStack* S)
{
    S->base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
    if (!S->base) exit(1);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

void PushOp(OpStack* S, char e)
{
    if (S->top - S->base >= S->stacksize)
    {
        S->base = (char*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(char));
        if (!S->base) exit(1);
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top = e;
    S->top++;
}

int StackTraverseOp(OpStack* S)
{
    char* p;
    p = S->base;
    while (p != S->top)
    {
        printf("%c\n", *p);
        p++;
    }
    return 1;
}

void PopOp(OpStack* S, char* e)
{
    if (S->top == S->base)
        return;
    *e = *(S->top - 1);
    S->top--;
}

char GetTopOp(OpStack* S)
{
    if (S->top != S->base)
        return *(S->top - 1);
    else
        return '\0'; 
}

int StackLengthOp(OpStack* S)
{
    return S->top - S->base;
}

int StackEmptyOp(OpStack* S)
{
    return (S->top == S->base);
}