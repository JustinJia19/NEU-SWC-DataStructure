#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BiTree.h"

// ����һ���µĶ������ڵ�
BiTreeNode* createNode(const char* name, int count, BiTreeNode* parent) {
    BiTreeNode* newNode = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->count = count;
    newNode->name = strdup(name); // ʹ�� strdup �����ַ���
    if (!newNode->name) {
        free(newNode);
        printf("Memory allocation for name failed\n");
        return NULL;
    }
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    newNode->parent = parent; // ����˫�׽ڵ�
    return newNode;
}

// ����һ���½ڵ�
void insertFirstChild(BiTreeNode* parent, const char* name, int count) {
    BiTreeNode* newNode = createNode(name, count, parent); // ����˫�׽ڵ�
    if (parent->firstChild == NULL) {
        parent->firstChild = newNode;
    }
    else {
        newNode->nextSibling = parent->firstChild;
        parent->firstChild = newNode;
    }
}

// �ͷ��������������ڴ�
void freeTree(BiTreeNode* root) {
    if (root != NULL) {
        freeTree(root->firstChild);
        freeTree(root->nextSibling);
        free(root->name); // �ͷ������ַ���
        free(root);
    }
}

// ���ҽڵ�
BiTreeNode* findNodeByName(BiTreeNode* root, const char* name) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(root->name, name) == 0) {
        return root;
    }
    BiTreeNode* foundNode = findNodeByName(root->firstChild, name);
    if (foundNode != NULL) {
        return foundNode;
    }
    return findNodeByName(root->nextSibling, name);
}

// ��ȡָ���ڵ������ֱ���ӽڵ㣬������ӽڵ���Ϣ
void getAllChildrenByName(BiTreeNode* root, const char* nodeName) {
    BiTreeNode* node = findNodeByName(root, nodeName);
    if (node == NULL) {
        printf("Node %s not found\n", nodeName);
        return;
    }

    if (node->firstChild == NULL) {
        printf("Node %s has no part\n", nodeName);
        return;
    }

    // ���ֱ���ӽڵ���Ϣ
    printf("Part %s subparts are:\n", nodeName);
    BiTreeNode* child = node->firstChild;
    while (child != NULL) {
        printf("%d %s\n", child->count, child->name);
        child = child->nextSibling;
    }
}


// ��ȡ���ӽڵ㵽���Ƚڵ������нڵ�� count ֵ֮��
int getDescendantCount(BiTreeNode* root, const char* descendantName, const char* ancestorName) {
    if (root == NULL || descendantName == NULL || ancestorName == NULL) {
        return 0;
    }

    BiTreeNode* descendant = findNodeByName(root, descendantName);
    if (descendant == NULL) {
        return 0; // �ӽڵ㲻����
    }

    BiTreeNode* ancestor = findNodeByName(root, ancestorName);
    if (ancestor == NULL) {
        return 0; // ���Ƚڵ㲻����
    }

    int product = 1;
    BiTreeNode* current = descendant;
    while (current != NULL && current != ancestor) {
        product *= current->count;
        current = current->parent;
    }

    if (current == ancestor) {
        return product;
    }

    return 0; // �ӽڵ㲻�����Ƚڵ�ĺ��
}