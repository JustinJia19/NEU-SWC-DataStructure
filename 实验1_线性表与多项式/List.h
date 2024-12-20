#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

// 定义节点，增加 exponent 成员
typedef struct Node {
    int coefficient; // 系数
    int exponent;    // 指数
    struct Node* next;
} Node;

// 定义链表
typedef struct LinkList {
    Node* head;
} LinkList;

// 初始化链表
void initList(LinkList* list);

// 检验链表是否为空
bool EmptyList(LinkList* list);

// 插入节点，按指数降序排列
void insertNode(LinkList* list, int coefficient, int exponent);

// 删除节点
int deleteNode(LinkList* list, int coefficient, int exponent);

// 查找节点
Node* searchNode(LinkList* list, int exponent);

// 打印链表
void printList(LinkList* list);

// 释放链表
void freeList(LinkList* list);

// 多项式加法
void addPolynomial(LinkList* result, LinkList* polyA, LinkList* polyB);

// 多项式减法
void subtractPolynomial(LinkList* result, LinkList* polyA, LinkList* polyB);

// 多项式乘法
void multiplyPolynomial(LinkList* result, LinkList* polyA, LinkList* polyB);

#endif // !LIST_H