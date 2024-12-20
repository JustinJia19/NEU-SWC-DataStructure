#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

// ����ڵ㣬���� exponent ��Ա
typedef struct Node {
    int coefficient; // ϵ��
    int exponent;    // ָ��
    struct Node* next;
} Node;

// ��������
typedef struct LinkList {
    Node* head;
} LinkList;

// ��ʼ������
void initList(LinkList* list);

// ���������Ƿ�Ϊ��
bool EmptyList(LinkList* list);

// ����ڵ㣬��ָ����������
void insertNode(LinkList* list, int coefficient, int exponent);

// ɾ���ڵ�
int deleteNode(LinkList* list, int coefficient, int exponent);

// ���ҽڵ�
Node* searchNode(LinkList* list, int exponent);

// ��ӡ����
void printList(LinkList* list);

// �ͷ�����
void freeList(LinkList* list);

// ����ʽ�ӷ�
void addPolynomial(LinkList* result, LinkList* polyA, LinkList* polyB);

// ����ʽ����
void subtractPolynomial(LinkList* result, LinkList* polyA, LinkList* polyB);

// ����ʽ�˷�
void multiplyPolynomial(LinkList* result, LinkList* polyA, LinkList* polyB);

#endif // !LIST_H