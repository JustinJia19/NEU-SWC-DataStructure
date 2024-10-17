#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void conversation()
{
	SqStack S;
	int n;
	InitStack(&S);
	scanf_s("%d", &n);
	while (n)
	{
		Push(&S, n%8);
		n = n / 8;
	}
	while (!StackEmpty(&S))
	{
		int e = 0;
		Pop(&S, &e);
		printf("%d", e);
	}
}
int main(void)
{

	conversation();
	return 0;
}
