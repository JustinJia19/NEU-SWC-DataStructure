#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "Stack.h"
#include "Queue.h"

// �������¼�
void parkingCar(char* line, SqStack* S, Queue* Q, FILE* output) {
    char plate[20], action[10];
    sscanf(line, "%s %s", plate, action);

    if (strcmp(action, "arrives") == 0) {
        if (StackLength(S) >= STACK_INIT_SIZE) {
            fprintf(output, "Sorry %s, the lot is full\n", plate);
            SElemType car = { .plate = "", .moveCount = 0 };
            strcpy(car.plate, plate);
            Enqueue(Q, car);
        }
        else {
            SElemType car = { .plate = "", .moveCount = 0 };
            strcpy(car.plate, plate);
            Push(S, car);
        }
    }
    else if (strcmp(action, "departs") == 0) {
        SqStack auxStack;
        InitStack(&auxStack);
        SElemType leavingCar;
        int found = 0;

        // �������г���ֱ���ҵ�Ҫ�뿪�ĳ���
        while (!StackEmpty(S)) {
            SElemType tempCar;
            Pop(S, &tempCar);
            if (strcmp(tempCar.plate, plate) == 0) {
                leavingCar = tempCar;
                found = 1;
                break;
            }
            tempCar.moveCount++;
            Push(&auxStack, tempCar);
        }

        // ����ҵ���Ҫ�뿪�ĳ����������Ƴ�
        if (found) {
            fprintf(output, "%s was moved %d times while it was here\n", plate, leavingCar.moveCount);
            // ��������������ѹ��ջ��
            while (!StackEmpty(&auxStack)) {
                SElemType tempCar;
                Pop(&auxStack, &tempCar);
                Push(S, tempCar);
            }

            // �������Ƿ�Ϊ��
            if (!IsEmpty(Q)) {
                SElemType car;
                Dequeue(Q, &car);
                Push(S, car);
                fprintf(output, "%s has been parked from the queue\n", car.plate);
            }
        }
        

        // ���ٸ���ջ
        DestroyStack(&auxStack);
    }
}

// ���ջ�����ÿ�������ƶ�����
void clearAndOutputStack(SqStack* S, FILE* output) {
    while (!StackEmpty(S)) {
        SElemType car;
        Pop(S, &car);
        fprintf(output, "%s was moved %d times while it was here\n", car.plate, car.moveCount);
    }
}

int main() {
    SqStack S;
    InitStack(&S);

    Queue Q;
    InitQueue(&Q);

    FILE* input = fopen("data.txt", "r");
    FILE* output = fopen("output.txt", "w");
    if (input == NULL || output == NULL) {
        printf("�ļ���ʧ�ܣ�\n");
        DestroyStack(&S);
        DestroyQueue(&Q);
        return -1;
    }

    char line[256];
    while (fgets(line, 256, input)) {
        parkingCar(line, &S, &Q, output);
    }

    // ���ջ�����ÿ�������ƶ�����
    clearAndOutputStack(&S, output);

    // ��ն���
    DestroyQueue(&Q);

    fclose(input);
    fclose(output);
    DestroyStack(&S);

    return 0;
}