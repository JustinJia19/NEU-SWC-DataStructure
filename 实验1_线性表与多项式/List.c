#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void initList(LinkList* list) {
    list->head = NULL;
}

bool EmptyList(LinkList* list) {
    return list->head == NULL;
}

void insertNode(LinkList* list, int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;

    if (EmptyList(list)) {
        list->head = newNode;
    }
    else {
        Node* current = list->head;
        Node* prev = NULL;
        while (current != NULL && current->exponent > exponent) {
            prev = current;
            current = current->next;
        }
        //检查是否有指数相同的结点
        if (current != NULL && current->exponent == exponent) {
            current->coefficient += coefficient;//合并系数
            free(newNode); // 如果已有相同指数的项，则释放新节点
        }
        else {
            if (prev == NULL) {
                newNode->next = list->head;
                list->head = newNode;
            }
            else {
                newNode->next = current;
                prev->next = newNode;
            }
        }
    }
}

int deleteNode(LinkList* list, int coefficient, int exponent) {
    Node* pFind = list->head;
    Node* preFind = NULL;

    while (pFind != NULL && (pFind->exponent != exponent || pFind->coefficient != coefficient)) {
        preFind = pFind;
        pFind = pFind->next;
    }
    if (pFind == NULL) {
        return 0; // 没有找到节点
    }

    if (preFind == NULL) {
        list->head = pFind->next;
    }
    else {
        preFind->next = pFind->next;
    }

    free(pFind);
    return 1;
}

Node* searchNode(LinkList* list, int exponent) {
    Node* pFind = list->head;

    while (pFind != NULL && pFind->exponent != exponent) {
        pFind = pFind->next;
    }
    return pFind;
}

void printList(LinkList* list) {
    Node* pFind = list->head;
    bool isFirstTerm = true;

    while (pFind != NULL) {
        if (pFind->coefficient != 0) { // 只输出系数不为0的项
            if (isFirstTerm) {
                if (pFind->coefficient < 0) {
                    printf("-");
                }
                printf("%dx^%d", abs(pFind->coefficient), pFind->exponent);
                isFirstTerm = false;
            }
            else {
                if (pFind->coefficient >= 0) {
                    printf(" + ");
                }
                else {
                    printf(" - ");
                }
                printf("%dx^%d", abs(pFind->coefficient), pFind->exponent);
            }
        }
        pFind = pFind->next;
    }
    printf("\n");
}

void freeList(LinkList* list) {
    Node* pFind = list->head;
    Node* next;
    while (pFind != NULL) {
        next = pFind->next;
        free(pFind);
        pFind = next;
    }
    list->head = NULL;
}

void addPolynomial(LinkList* result, LinkList* polyA, LinkList* polyB) {
    initList(result);
    Node* currentA = polyA->head;
    Node* currentB = polyB->head;

    while (currentA != NULL && currentB != NULL) {
        if (currentA->exponent > currentB->exponent) {
            insertNode(result, currentA->coefficient, currentA->exponent);
            currentA = currentA->next;
        }
        else if (currentA->exponent < currentB->exponent) {
            insertNode(result, currentB->coefficient, currentB->exponent);
            currentB = currentB->next;
        }
        else {
            int sumCoeff = currentA->coefficient + currentB->coefficient;
            //存储两个多项式中相同指数项的系数和
            if (sumCoeff != 0) { // 只插入系数不为0的项
                insertNode(result, sumCoeff, currentA->exponent);
            }
            currentA = currentA->next;
            currentB = currentB->next;
        }
    }

    while (currentA != NULL) {
        insertNode(result, currentA->coefficient, currentA->exponent);
        currentA = currentA->next;
    }

    while (currentB != NULL) {
        insertNode(result, currentB->coefficient, currentB->exponent);
        currentB = currentB->next;
    }
}

void subtractPolynomial(LinkList* result, LinkList* polyA, LinkList* polyB) {
    initList(result);
    Node* currentA = polyA->head;
    Node* currentB = polyB->head;

    while (currentA != NULL && currentB != NULL) {
        if (currentA->exponent > currentB->exponent) {
            insertNode(result, currentA->coefficient, currentA->exponent);
            currentA = currentA->next;
        }
        else if (currentA->exponent < currentB->exponent) {
            insertNode(result, -currentB->coefficient, currentB->exponent);
            currentB = currentB->next;
        }
        else {
            int diffCoeff = currentA->coefficient - currentB->coefficient;
            if (diffCoeff != 0) { // 只插入系数不为0的项
                insertNode(result, diffCoeff, currentA->exponent);
            }
            currentA = currentA->next;
            currentB = currentB->next;
        }
    }

    while (currentA != NULL) {
        insertNode(result, currentA->coefficient, currentA->exponent);
        currentA = currentA->next;
    }

    while (currentB != NULL) {
        insertNode(result, -currentB->coefficient, currentB->exponent);
        currentB = currentB->next;
    }
}

void multiplyPolynomial(LinkList* result, LinkList* polyA, LinkList* polyB) {
    initList(result);
    Node* currentA = polyA->head;

    while (currentA != NULL) {
        Node* currentB = polyB->head;
        while (currentB != NULL) {
            int newCoefficient = currentA->coefficient * currentB->coefficient;
            int newExponent = currentA->exponent + currentB->exponent;
            if (newCoefficient != 0) {
                insertNode(result, newCoefficient, newExponent);
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;
    }
}