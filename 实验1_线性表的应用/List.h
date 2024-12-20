#include <stdbool.h>
#ifndef LIST_H
#define LIST_H

//定义节点
typedef struct intNode {
    int data;
    struct intNode* next;
} intNode;
typedef struct floatNode {
    float data;
    struct floatNode* next;
} floatNode;
typedef struct charNode {
    char data;
    struct charNode* next;
} charNode;

//定义链表
typedef struct intLinkList {
    intNode* head;
} intLinkList;
typedef struct floatLinkList {
    floatNode* head;
} floatLinkList;
typedef struct charLinkList {
    charNode* head;
} charLinkList;

// 初始化链表
void initIntList(intLinkList* list);
void initFloatList(floatLinkList* list);
void initCharList(charLinkList* list);

//检验链表是否为空
bool EmptyIntList(intLinkList* list);
bool EmptyFloatList(floatLinkList* list);
bool EmptyCharList(charLinkList* list);

// 插入节点
void insertIntNode(intLinkList* list, int val);
void insertFloatNode(floatLinkList* list, float val);
void insertCharNode(charLinkList* list, char val);

// 删除节点
bool deleteIntNode(intLinkList* list, int val);
bool deleteFloatNode(floatLinkList* list, float val);
bool deleteCharNode(charLinkList* list, char val);

// 查找节点
intNode* searchIntNode(intLinkList* list, int val);
floatNode* searchFloatNode(floatLinkList* list, float val);
charNode* searchCharNode(charLinkList* list, char val);

// 打印链表
void printIntList(intLinkList* list);
void printFloatList(floatLinkList* list);
void printCharList(charLinkList* list);

// 释放链表
void freeIntList(intLinkList* list);
void freeFloatList(floatLinkList* list);
void freeCharList(charLinkList* list);

// 并集
void unionIntSet(intLinkList* result, intLinkList* setA, intLinkList* setB);
void unionFloatSet(floatLinkList* result, floatLinkList* setA, floatLinkList* setB);
void unionCharSet(charLinkList* result, charLinkList* setA, charLinkList* setB);
//交集
void intersectionIntSet(intLinkList* result, intLinkList* setA, intLinkList* setB);
void intersectionFloatSet(floatLinkList* result, floatLinkList* setA, floatLinkList* setB);
void intersectionCharSet(charLinkList* result, charLinkList* setA, charLinkList* setB);
//差集
void differenceIntSet(intLinkList* result, intLinkList* setA, intLinkList* setB);
void differenceFloatSet(floatLinkList* result, floatLinkList* setA, floatLinkList* setB);
void differenceCharSet(charLinkList* result, charLinkList* setA, charLinkList* setB);
//补集
void complementIntSet(intLinkList* result, intLinkList* universal, intLinkList* subset);
void complementFloatSet(floatLinkList* result, floatLinkList* universal, floatLinkList* subset);
void complementCharSet(charLinkList* result, charLinkList* universal, charLinkList* subset);

#endif // !LIST_H