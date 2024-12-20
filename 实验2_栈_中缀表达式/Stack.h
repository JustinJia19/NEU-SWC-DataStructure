#ifndef STACK_H
#define STACK_H

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef double SElemType;
typedef struct {
    SElemType* base;
    SElemType* top;
    int stacksize;
} SqStack;

typedef struct {
    char* base;
    char* top;
    int stacksize;
} OpStack;

void InitStack(SqStack* S);
void Push(SqStack* S, SElemType e);
int StackTraverse(SqStack* S);
void Pop(SqStack* S, SElemType* e);
SElemType GetTop(SqStack* S);
int StackLength(SqStack* S);
int StackEmpty(SqStack* S);

void InitOpStack(OpStack* S);
void PushOp(OpStack* S, char e);
int StackTraverseOp(OpStack* S);
void PopOp(OpStack* S, char* e);
char GetTopOp(OpStack* S);
int StackLengthOp(OpStack* S);
int StackEmptyOp(OpStack* S);

#endif