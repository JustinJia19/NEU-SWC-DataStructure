#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "List.h"

void initIntList(intLinkList* list)
{
    list->head = NULL;
}
void initFloatList(floatLinkList* list)
{
    list->head = NULL;
}
void initCharList(charLinkList* list)
{
    list->head = NULL;
}

bool EmptyIntList(intLinkList* list)
{
    if (list->head == NULL)
        return true;
    return false;
}
bool EmptyFloatList(floatLinkList* list)
{
    if (list->head == NULL)
        return true;
    return false;
}
bool EmptyCharList(charLinkList* list)
{
    if (list->head == NULL)
        return true;
    return false;
}

void insertIntNode(intLinkList* list, int val)
{
    if (searchIntNode(list, val) == NULL) { // 检查是否已存在
        intNode* newNode = (intNode*)malloc(sizeof(intNode));
        newNode->data = val;
        newNode->next = list->head;
        list->head = newNode;
    }
}
void insertFloatNode(floatLinkList* list, float val)
{
    if (searchFloatNode(list, val) == NULL) { // 检查是否已存在
        floatNode* newNode = (floatNode*)malloc(sizeof(floatNode));
        newNode->data = val;
        newNode->next = list->head;
        list->head = newNode;
    }
}
void insertCharNode(charLinkList* list, char val)
{
    if (searchCharNode(list, val) == NULL) { // 检查是否已存在
        charNode* newNode = (charNode*)malloc(sizeof(charNode));
        newNode->data = val;
        newNode->next = list->head;
        list->head = newNode;
    }
}

bool deleteIntNode(intLinkList* list, int val)
{
    intNode* pFind = list->head;
    intNode* preFind = NULL;

    while (pFind != NULL && pFind->data != val)
    {
        preFind = pFind;
        pFind = pFind->next;
    }
    if (pFind == NULL)
        return false;//没有找到结点

    if (preFind == NULL) //头结点
    {
        list->head = pFind->next;
    }
    else {
        preFind->next = pFind->next;
    }

    free(pFind);
    return true;
}
bool deleteFloatNode(floatLinkList* list, float val)
{
    floatNode* pFind = list->head;
    floatNode* preFind = NULL;

    while (pFind != NULL && pFind->data != val)
    {
        preFind = pFind;
        pFind = pFind->next;
    }
    if (pFind == NULL)
        return false;//没有找到结点

    if (preFind == NULL) //头结点
    {
        list->head = pFind->next;
    }
    else {
        preFind->next = pFind->next;
    }

    free(pFind);
    return true;
}
bool deleteCharNode(charLinkList* list, char val)
{
    charNode* pFind = list->head;
    charNode* preFind = NULL;

    while (pFind != NULL && pFind->data != val)
    {
        preFind = pFind;
        pFind = pFind->next;
    }
    if (pFind == NULL)
        return false;//没有找到结点

    if (preFind == NULL) //头结点
    {
        list->head = pFind->next;
    }
    else {
        preFind->next = pFind->next;
    }

    free(pFind);
    return true;
}


intNode* searchIntNode(intLinkList* list, int val)
{
    intNode* pFind = list->head;

    while (pFind != NULL && pFind->data != val)
    {
        pFind = pFind->next;
    }
    return pFind;
}
floatNode* searchFloatNode(floatLinkList* list, float val)
{
    floatNode* pFind = list->head;

    while (pFind != NULL && pFind->data != val)
    {
        pFind = pFind->next;
    }
    return pFind;
}
charNode* searchCharNode(charLinkList* list, char val)
{
    charNode* pFind = list->head;

    while (pFind != NULL && pFind->data != val)
    {
        pFind = pFind->next;
    }
    return pFind;
}

void printIntList(intLinkList* list)
{
    intNode* pFind = list->head;

    while (pFind != NULL)
    {
        printf("%d ", pFind->data);
        pFind = pFind->next;
    }
}
void printFloatList(floatLinkList* list)
{
    floatNode* pFind = list->head;

    while (pFind != NULL)
    {
        printf("%f ", pFind->data);
        pFind = pFind->next;
    }
}
void printCharList(charLinkList* list)
{
    charNode* pFind = list->head;

    while (pFind != NULL)
    {
        printf("%c ", pFind->data);
        pFind = pFind->next;
    }
}

void freeIntList(intLinkList* list)
{
    intNode* pFind = list->head;
    intNode* next;
    while (pFind != NULL) {
        next = pFind->next;
        free(pFind);
        pFind = next;
    }
    list->head = NULL;
}
void freeFloatList(floatLinkList* list)
{
    floatNode* pFind = list->head;
    floatNode* next;
    while (pFind != NULL) {
        next = pFind->next;
        free(pFind);
        pFind = next;
    }
    list->head = NULL;
}
void freeCharList(charLinkList* list)
{
    charNode* pFind = list->head;
    charNode* next;
    while (pFind != NULL) {
        next = pFind->next;
        free(pFind);
        pFind = next;
    }
    list->head = NULL;
}

void unionCharSet(charLinkList* result, charLinkList* setA, charLinkList* setB)
{
    initCharList(result);
    charNode* temp = setA->head;
    while (temp != NULL) {
        insertCharNode(result, temp->data);
        temp = temp->next;
    }
    temp = setB->head;
    while (temp != NULL) {
        insertCharNode(result, temp->data); //不重复则插入
        temp = temp->next;
    }
}
void unionIntSet(intLinkList* result, intLinkList* setA, intLinkList* setB)
{
    initIntList(result);
    intNode* temp = setA->head;
    while (temp != NULL) {
        insertIntNode(result, temp->data);
        temp = temp->next;
    }
    temp = setB->head;
    while (temp != NULL) {
        insertIntNode(result, temp->data); //不重复则插入
        temp = temp->next;
    }
}
void unionFloatSet(floatLinkList* result, floatLinkList* setA, floatLinkList* setB)
{
    initFloatList(result);
    floatNode* temp = setA->head;
    while (temp != NULL) {
        insertFloatNode(result, temp->data);
        temp = temp->next;
    }
    temp = setB->head;
    while (temp != NULL) {
        insertFloatNode(result, temp->data); //不重复则插入
        temp = temp->next;
    }
}

void intersectionIntSet(intLinkList* result, intLinkList* setA, intLinkList* setB)
{
    initIntList(result);
    intNode* temp = setA->head;
    while (temp != NULL) {
        if (searchIntNode(setB, temp->data) != NULL) {
            insertIntNode(result, temp->data);
        }
        temp = temp->next;
    }
}
void intersectionFloatSet(floatLinkList* result, floatLinkList* setA, floatLinkList* setB)
{
    initFloatList(result);
    floatNode* temp = setA->head;
    while (temp != NULL) {
        if (searchFloatNode(setB, temp->data) != NULL) {
            insertFloatNode(result, temp->data);
        }
        temp = temp->next;
    }
}
void intersectionCharSet(charLinkList* result, charLinkList* setA, charLinkList* setB)
{
    initCharList(result);
    charNode* temp = setA->head;
    while (temp != NULL) {
        if (searchCharNode(setB, temp->data) != NULL) {
            insertCharNode(result, temp->data);
        }
        temp = temp->next;
    }
}

void differenceIntSet(intLinkList* result, intLinkList* setA, intLinkList* setB)
{
    initIntList(result);
    intNode* temp = setA->head;
    while (temp != NULL) {
        if (searchIntNode(setB, temp->data) == NULL) {
            insertIntNode(result, temp->data);
        }
        temp = temp->next;
    }
}
void differenceFloatSet(floatLinkList* result, floatLinkList* setA, floatLinkList* setB)
{
    initFloatList(result);
    floatNode* temp = setA->head;
    while (temp != NULL) {
        if (searchFloatNode(setB, temp->data) == NULL) {
            insertFloatNode(result, temp->data);
        }
        temp = temp->next;
    }
}
void differenceCharSet(charLinkList* result, charLinkList* setA, charLinkList* setB)
{
    initCharList(result);
    charNode* temp = setA->head;
    while (temp != NULL) {
        if (searchCharNode(setB, temp->data) == NULL) {
            insertCharNode(result, temp->data);
        }
        temp = temp->next;
    }
}

void complementIntSet(intLinkList* result, intLinkList* universal, intLinkList* subset)
{
    initIntList(result);
    intNode* temp = universal->head;
    while (temp != NULL) {
        if (searchIntNode(subset, temp->data) == NULL) {
            insertIntNode(result, temp->data);
        }
        temp = temp->next;
    }
}
void complementFloatSet(floatLinkList* result, floatLinkList* universal, floatLinkList* subset)
{
    initFloatList(result);
    floatNode* temp = universal->head;
    while (temp != NULL) {
        if (searchFloatNode(subset, temp->data) == NULL) {
            insertFloatNode(result, temp->data);
        }
        temp = temp->next;
    }
}
void complementCharSet(charLinkList* result, charLinkList* universal, charLinkList* subset)
{
    initCharList(result);
    charNode* temp = universal->head;
    while (temp != NULL) {
        if (searchCharNode(subset, temp->data) == NULL) {
            insertCharNode(result, temp->data);
        }
        temp = temp->next;
    }
}
