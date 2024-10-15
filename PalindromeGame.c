#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
void getChar(char *input, char* output)
{
	int i, j = 0;
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ')
		{
			output[j] = input[i];
			j++;
		}
	}
	output[j] = '\0';
}
int main()
{
	char input[100];
	char output[100];
	SqStack S;
	int label = 0;
	
	printf("请输入字符串：\n");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';
	getChar(input, output);
	InitStack(&S);
	for (int i = 0; output[i] != '\0'; i++)
	{
		Push(&S, output[i]);
	}
	for (int i = 0; output[i] != '\0'; i++)
	{
		char find = 0;
		Pop(&S, &find);
		if (find != output[i])
		{
			label = 1;
			break;
		}
	}
	if (label == 1)
		printf("不是回文！");
	else
		printf("是回文！");

	return 0;
}
