#include <stdio.h>
#include <stdlib.h> 
#include<time.h>
#include "List.h"

// 使用哈希表记录已生成的指数
#define MAX_EXPONENT 1000000
int exponentHash[MAX_EXPONENT + 1] = { 0 };

// 生成随机多项式
void generateRandomPolynomial(LinkList* list, int numTerms, int maxCoefficient, int maxExponent) {
    int generatedTerms = 0;
    while (generatedTerms < numTerms) {
        int coefficient = rand() % (2 * maxCoefficient + 1) - maxCoefficient; // 随机生成系数
        int exponent = rand() % (maxExponent + 1); // 随机生成指数

        // 检查是否已经生成过该指数
        if (exponentHash[exponent] == 0) {
            insertNode(list, coefficient, exponent);
            exponentHash[exponent] = 1; // 标记该指数已生成
            generatedTerms++;
        }
    }
}

int main() {


    clock_t start, end;
    double cpu_time_used;

    // 记录开始时间
    start = clock();

    // 创建两个多项式链表
    LinkList polyA, polyB, resultAdd, resultSub, resultMul;

    // 初始化多项式链表
    initList(&polyA);
    initList(&polyB);
    initList(&resultAdd);
    initList(&resultSub);
    initList(&resultMul);

    // 设置随机数种子
    srand(time(NULL));

    // 随机生成多项式A
    int numTermsA = 10; // 多项式A的项数
    int maxCoefficientA = 100; // 多项式A的系数范围
    int maxExponentA = 2000; // 多项式A的指数范围
    memset(exponentHash, 0, sizeof(exponentHash)); // 清除哈希表
    generateRandomPolynomial(&polyA, numTermsA, maxCoefficientA, maxExponentA);

    // 随机生成多项式B
    int numTermsB = 10; // 多项式B的项数
    int maxCoefficientB = 100; // 多项式B的系数范围
    int maxExponentB = 2000; // 多项式B的指数范围
    memset(exponentHash, 0, sizeof(exponentHash)); // 清除哈希表
    generateRandomPolynomial(&polyB, numTermsB, maxCoefficientB, maxExponentB);

    // 打印原始多项式
    printf("多项式 A: ");
    printList(&polyA);
    printf("多项式 B: ");
    printList(&polyB);

    // 计算多项式的和
    addPolynomial(&resultAdd, &polyA, &polyB);

    // 打印结果多项式（和）
    printf("多项式 A + B: ");
    printList(&resultAdd);

    // 计算多项式的差
    subtractPolynomial(&resultSub, &polyA, &polyB);

    // 打印结果多项式（差）
    printf("多项式 A - B: ");
    printList(&resultSub);

    // 计算多项式的积
    multiplyPolynomial(&resultMul, &polyA, &polyB);

    // 打印结果多项式（积）
    printf("多项式 A * B: ");
    printList(&resultMul);

    // 清理资源
    freeList(&polyA);
    freeList(&polyB);
    freeList(&resultAdd);
    freeList(&resultSub);
    freeList(&resultMul);

    // 记录结束时间
    end = clock();

    // 计算并输出程序运行时间
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("程序运行时间: %f 秒\n", cpu_time_used);
    return 0;
}