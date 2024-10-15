#pragma once
#ifndef STACK_H
#define STACK_H

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

void InitStack(SqStack* S);
void Push(SqStack* S, SElemType e);
int StackTraverse(SqStack* S);
void Pop(SqStack* S, SElemType *e);
SElemType GetTop(SqStack* S);
int StackLength(SqStack* S);
int StackEmpty(SqStack* S);

#endif