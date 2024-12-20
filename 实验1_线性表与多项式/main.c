#include <stdio.h>
#include <stdlib.h> 
#include<time.h>
#include "List.h"

// ʹ�ù�ϣ���¼�����ɵ�ָ��
#define MAX_EXPONENT 1000000
int exponentHash[MAX_EXPONENT + 1] = { 0 };

// �����������ʽ
void generateRandomPolynomial(LinkList* list, int numTerms, int maxCoefficient, int maxExponent) {
    int generatedTerms = 0;
    while (generatedTerms < numTerms) {
        int coefficient = rand() % (2 * maxCoefficient + 1) - maxCoefficient; // �������ϵ��
        int exponent = rand() % (maxExponent + 1); // �������ָ��

        // ����Ƿ��Ѿ����ɹ���ָ��
        if (exponentHash[exponent] == 0) {
            insertNode(list, coefficient, exponent);
            exponentHash[exponent] = 1; // ��Ǹ�ָ��������
            generatedTerms++;
        }
    }
}

int main() {


    clock_t start, end;
    double cpu_time_used;

    // ��¼��ʼʱ��
    start = clock();

    // ������������ʽ����
    LinkList polyA, polyB, resultAdd, resultSub, resultMul;

    // ��ʼ������ʽ����
    initList(&polyA);
    initList(&polyB);
    initList(&resultAdd);
    initList(&resultSub);
    initList(&resultMul);

    // �������������
    srand(time(NULL));

    // ������ɶ���ʽA
    int numTermsA = 10; // ����ʽA������
    int maxCoefficientA = 100; // ����ʽA��ϵ����Χ
    int maxExponentA = 2000; // ����ʽA��ָ����Χ
    memset(exponentHash, 0, sizeof(exponentHash)); // �����ϣ��
    generateRandomPolynomial(&polyA, numTermsA, maxCoefficientA, maxExponentA);

    // ������ɶ���ʽB
    int numTermsB = 10; // ����ʽB������
    int maxCoefficientB = 100; // ����ʽB��ϵ����Χ
    int maxExponentB = 2000; // ����ʽB��ָ����Χ
    memset(exponentHash, 0, sizeof(exponentHash)); // �����ϣ��
    generateRandomPolynomial(&polyB, numTermsB, maxCoefficientB, maxExponentB);

    // ��ӡԭʼ����ʽ
    printf("����ʽ A: ");
    printList(&polyA);
    printf("����ʽ B: ");
    printList(&polyB);

    // �������ʽ�ĺ�
    addPolynomial(&resultAdd, &polyA, &polyB);

    // ��ӡ�������ʽ���ͣ�
    printf("����ʽ A + B: ");
    printList(&resultAdd);

    // �������ʽ�Ĳ�
    subtractPolynomial(&resultSub, &polyA, &polyB);

    // ��ӡ�������ʽ���
    printf("����ʽ A - B: ");
    printList(&resultSub);

    // �������ʽ�Ļ�
    multiplyPolynomial(&resultMul, &polyA, &polyB);

    // ��ӡ�������ʽ������
    printf("����ʽ A * B: ");
    printList(&resultMul);

    // ������Դ
    freeList(&polyA);
    freeList(&polyB);
    freeList(&resultAdd);
    freeList(&resultSub);
    freeList(&resultMul);

    // ��¼����ʱ��
    end = clock();

    // ���㲢�����������ʱ��
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("��������ʱ��: %f ��\n", cpu_time_used);
    return 0;
}