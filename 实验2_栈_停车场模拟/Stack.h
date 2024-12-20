#ifndef STACK_H
#define STACK_H

#define STACK_INIT_SIZE 5
#define STACKINCREMENT 10

typedef struct {
    char plate[20];
    int moveCount; // ÒÆ¶¯´ÎÊý
} SElemType;


typedef struct {
    SElemType* base;
    SElemType* top;
    int stacksize;
} SqStack;

void InitStack(SqStack* S);
void DestroyStack(SqStack* S); 
void Push(SqStack* S, SElemType e);
int StackTraverse(SqStack* S);
void Pop(SqStack* S, SElemType* e);
SElemType GetTop(SqStack* S);
int StackLength(SqStack* S);
int StackEmpty(SqStack* S);

#endif