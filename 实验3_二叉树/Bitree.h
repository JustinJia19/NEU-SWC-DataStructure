#ifndef BITREE_H_
#define BITREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BiTreeNode {
    char* name;                // �ڵ�����
    int count;                 // �ڵ�����
    struct BiTreeNode* firstChild; // ָ���һ���ӽڵ�
    struct BiTreeNode* nextSibling; // ָ����һ���ֵܽڵ�
    struct BiTreeNode* parent;      // ָ��˫�׽ڵ�
} BiTreeNode;

// ����һ���µĶ������ڵ�
BiTreeNode* createNode(const char* name, int count, BiTreeNode* parent);

// ����һ���½ڵ�
void insertFirstChild(BiTreeNode* parent, const char* name, int count);

// �ͷ��������������ڴ�
void freeTree(BiTreeNode* root);

// ���ҽڵ�
BiTreeNode* findNodeByName(BiTreeNode* root, const char* name);

// ��ȡָ���ڵ�������ӽڵ㣬������ӽڵ���Ϣ
void getAllChildrenByName(BiTreeNode* root, const char* nodeName);

// ����һ���ڵ��Ƿ�Ϊ�ڶ����ڵ�����ȣ�������Ȩֵ֮��
int getDescendantCount(BiTreeNode* root, const char* descendantName, const char* ancestorName);


#endif // BITREE_H_