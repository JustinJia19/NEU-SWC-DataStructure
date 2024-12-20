#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "Stack.h"
#include "Queue.h"

// 处理到达事件
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

        // 弹出所有车辆直到找到要离开的车辆
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

        // 如果找到了要离开的车辆，则将其移除
        if (found) {
            fprintf(output, "%s was moved %d times while it was here\n", plate, leavingCar.moveCount);
            // 将其他车辆重新压入栈中
            while (!StackEmpty(&auxStack)) {
                SElemType tempCar;
                Pop(&auxStack, &tempCar);
                Push(S, tempCar);
            }

            // 检查队列是否为空
            if (!IsEmpty(Q)) {
                SElemType car;
                Dequeue(Q, &car);
                Push(S, car);
                fprintf(output, "%s has been parked from the queue\n", car.plate);
            }
        }
        

        // 销毁辅助栈
        DestroyStack(&auxStack);
    }
}

// 清空栈并输出每辆车的移动次数
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
        printf("文件打开失败！\n");
        DestroyStack(&S);
        DestroyQueue(&Q);
        return -1;
    }

    char line[256];
    while (fgets(line, 256, input)) {
        parkingCar(line, &S, &Q, output);
    }

    // 清空栈并输出每辆车的移动次数
    clearAndOutputStack(&S, output);

    // 清空队列
    DestroyQueue(&Q);

    fclose(input);
    fclose(output);
    DestroyStack(&S);

    return 0;
}