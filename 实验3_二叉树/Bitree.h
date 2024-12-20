#ifndef BITREE_H_
#define BITREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BiTreeNode {
    char* name;                // 节点名称
    int count;                 // 节点数量
    struct BiTreeNode* firstChild; // 指向第一个子节点
    struct BiTreeNode* nextSibling; // 指向下一个兄弟节点
    struct BiTreeNode* parent;      // 指向双亲节点
} BiTreeNode;

// 创建一个新的二叉树节点
BiTreeNode* createNode(const char* name, int count, BiTreeNode* parent);

// 插入一个新节点
void insertFirstChild(BiTreeNode* parent, const char* name, int count);

// 释放整个二叉树的内存
void freeTree(BiTreeNode* root);

// 查找节点
BiTreeNode* findNodeByName(BiTreeNode* root, const char* name);

// 获取指定节点的所有子节点，并输出子节点信息
void getAllChildrenByName(BiTreeNode* root, const char* nodeName);

// 检查第一个节点是否为第二个节点的祖先，并返回权值之积
int getDescendantCount(BiTreeNode* root, const char* descendantName, const char* ancestorName);


#endif // BITREE_H_