#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"



void InitStack(SqStack* S)
{
	S->base = (SElemType*)malloc(STACK_INIT_SIZE);
	if (!S->base) exit(1);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return;
}

void Push(SqStack* S, SElemType e)
{
	if (S->top - S->base == S->stacksize)
	{
		printf("Õ»ÒÑÂú£¡\n");
		return;//Õ»Âú
	}
	*S->top = e;
	S->top++;
	return;
}

int StackTraverse(SqStack* S)
{
	SElemType* p;
	p = S->base;
	while (p != S->top)
	{
		printf("%d\n", *p);
		p++;
	}
	return 1;
}

void Pop(SqStack* S, SElemType *e)
{
	if (S->top == S->base)
		return;
	*e = *(S->top - 1);
	S->top--;
	return;
}

SElemType GetTop(SqStack* S)
{
	if (S->top != S->base)
		return *S->top;
}

int StackLength(SqStack* S)
{
	int length;
	length = S->top - S->base;
	return length;
}

int StackEmpty(SqStack *S) {
	return (S->top == S->base);
}

