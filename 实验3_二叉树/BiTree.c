#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BiTree.h"

// 创建一个新的二叉树节点
BiTreeNode* createNode(const char* name, int count, BiTreeNode* parent) {
    BiTreeNode* newNode = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->count = count;
    newNode->name = strdup(name); // 使用 strdup 复制字符串
    if (!newNode->name) {
        free(newNode);
        printf("Memory allocation for name failed\n");
        return NULL;
    }
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    newNode->parent = parent; // 设置双亲节点
    return newNode;
}

// 插入一个新节点
void insertFirstChild(BiTreeNode* parent, const char* name, int count) {
    BiTreeNode* newNode = createNode(name, count, parent); // 设置双亲节点
    if (parent->firstChild == NULL) {
        parent->firstChild = newNode;
    }
    else {
        newNode->nextSibling = parent->firstChild;
        parent->firstChild = newNode;
    }
}

// 释放整个二叉树的内存
void freeTree(BiTreeNode* root) {
    if (root != NULL) {
        freeTree(root->firstChild);
        freeTree(root->nextSibling);
        free(root->name); // 释放名称字符串
        free(root);
    }
}

// 查找节点
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

// 获取指定节点的所有直接子节点，并输出子节点信息
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

    // 输出直接子节点信息
    printf("Part %s subparts are:\n", nodeName);
    BiTreeNode* child = node->firstChild;
    while (child != NULL) {
        printf("%d %s\n", child->count, child->name);
        child = child->nextSibling;
    }
}


// 获取从子节点到祖先节点上所有节点的 count 值之积
int getDescendantCount(BiTreeNode* root, const char* descendantName, const char* ancestorName) {
    if (root == NULL || descendantName == NULL || ancestorName == NULL) {
        return 0;
    }

    BiTreeNode* descendant = findNodeByName(root, descendantName);
    if (descendant == NULL) {
        return 0; // 子节点不存在
    }

    BiTreeNode* ancestor = findNodeByName(root, ancestorName);
    if (ancestor == NULL) {
        return 0; // 祖先节点不存在
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

    return 0; // 子节点不是祖先节点的后代
}