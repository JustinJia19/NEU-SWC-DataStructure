#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BiTree.h"

int main() {
    // 打开文件
    FILE* file = fopen("definition.txt", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    // 声明根节点变量
    BiTreeNode* root = NULL;

    // 读取文件的第一行，提取第一个单词作为根节点
    char line[256];
    if (fgets(line, sizeof(line), file)) {
        // 去除行尾的换行符
        line[strcspn(line, "\n")] = '\0';

        // 解析第一行内容
        char* token = strtok(line, " ");
        if (token == NULL) {
            printf("Invalid input format\n");
            fclose(file);
            return 1;
        }

        char* rootName = token;
        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Invalid input format\n");
            fclose(file);
            return 1;
        }

        int count = atoi(token);
        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Invalid input format\n");
            fclose(file);
            return 1;
        }

        char* childName = token;

        // 创建根节点
        root = createNode(rootName, count, NULL); // 初始化根节点的 count 为给定值，双亲节点为 NULL

        // 创建第一个子节点并插入
        insertFirstChild(root, childName, count);
    }
    else {
        printf("File is empty\n");
        fclose(file);
        return 1;
    }

    // 读取文件内容
    while (fgets(line, sizeof(line), file)) {
        // 去除行尾的换行符
        line[strcspn(line, "\n")] = '\0';

        // 解析行内容
        char* token = strtok(line, " ");
        if (token == NULL) continue;

        char* word1 = token;
        token = strtok(NULL, " ");
        if (token == NULL) continue;

        int count = atoi(token);
        token = strtok(NULL, " ");
        if (token == NULL) continue;

        char* word2 = token;

        // 查找或创建单词1对应的节点
        BiTreeNode* node1 = findNodeByName(root, word1);
        if (node1 == NULL) {
            node1 = createNode(word1, 0, root); // 初始化 count 为 0，双亲节点为根节点
            insertFirstChild(root, word1, 0); // 插入到根节点的第一个子节点
        }

        // 创建单词2对应的节点
        BiTreeNode* node2 = createNode(word2, count, node1); // 设置双亲节点为 node1

        // 将单词2插入到单词1的第一个子节点
        insertFirstChild(node1, word2, count);
    }

    // 关闭文件
    fclose(file);

    // 读取查询文件
    FILE* queries = fopen("queries.txt", "r");
    if (queries == NULL) {
        printf("Failed to open queries file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), queries)) {

        // 解析查询内容
        char action[20], place[20], subplace[20];
        if (sscanf(line, "%s %s %s", action, subplace, place) != 3) {
            sscanf(line, "%s %s", action, place);
            if (strcmp(action, "whatis") == 0)
            getAllChildrenByName(root, place);
        }

        else {
            if (strcmp(action, "howmany") == 0) {
                int num = getDescendantCount(root, subplace, place);
                printf("%s has %d %s\n", place, num, subplace);
            }
        }
    }

    // 关闭查询文件
    fclose(queries);
    // 释放树的内存
    freeTree(root);

    return 0;
}