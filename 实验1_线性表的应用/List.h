#include <stdbool.h>
#ifndef LIST_H
#define LIST_H

//����ڵ�
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

//��������
typedef struct intLinkList {
    intNode* head;
} intLinkList;
typedef struct floatLinkList {
    floatNode* head;
} floatLinkList;
typedef struct charLinkList {
    charNode* head;
} charLinkList;

// ��ʼ������
void initIntList(intLinkList* list);
void initFloatList(floatLinkList* list);
void initCharList(charLinkList* list);

//���������Ƿ�Ϊ��
bool EmptyIntList(intLinkList* list);
bool EmptyFloatList(floatLinkList* list);
bool EmptyCharList(charLinkList* list);

// ����ڵ�
void insertIntNode(intLinkList* list, int val);
void insertFloatNode(floatLinkList* list, float val);
void insertCharNode(charLinkList* list, char val);

// ɾ���ڵ�
bool deleteIntNode(intLinkList* list, int val);
bool deleteFloatNode(floatLinkList* list, float val);
bool deleteCharNode(charLinkList* list, char val);

// ���ҽڵ�
intNode* searchIntNode(intLinkList* list, int val);
floatNode* searchFloatNode(floatLinkList* list, float val);
charNode* searchCharNode(charLinkList* list, char val);

// ��ӡ����
void printIntList(intLinkList* list);
void printFloatList(floatLinkList* list);
void printCharList(charLinkList* list);

// �ͷ�����
void freeIntList(intLinkList* list);
void freeFloatList(floatLinkList* list);
void freeCharList(charLinkList* list);

// ����
void unionIntSet(intLinkList* result, intLinkList* setA, intLinkList* setB);
void unionFloatSet(floatLinkList* result, floatLinkList* setA, floatLinkList* setB);
void unionCharSet(charLinkList* result, charLinkList* setA, charLinkList* setB);
//����
void intersectionIntSet(intLinkList* result, intLinkList* setA, intLinkList* setB);
void intersectionFloatSet(floatLinkList* result, floatLinkList* setA, floatLinkList* setB);
void intersectionCharSet(charLinkList* result, charLinkList* setA, charLinkList* setB);
//�
void differenceIntSet(intLinkList* result, intLinkList* setA, intLinkList* setB);
void differenceFloatSet(floatLinkList* result, floatLinkList* setA, floatLinkList* setB);
void differenceCharSet(charLinkList* result, charLinkList* setA, charLinkList* setB);
//����
void complementIntSet(intLinkList* result, intLinkList* universal, intLinkList* subset);
void complementFloatSet(floatLinkList* result, floatLinkList* universal, floatLinkList* subset);
void complementCharSet(charLinkList* result, charLinkList* universal, charLinkList* subset);

#endif // !LIST_H