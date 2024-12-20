#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BiTree.h"

int main() {
    // ���ļ�
    FILE* file = fopen("definition.txt", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    // �������ڵ����
    BiTreeNode* root = NULL;

    // ��ȡ�ļ��ĵ�һ�У���ȡ��һ��������Ϊ���ڵ�
    char line[256];
    if (fgets(line, sizeof(line), file)) {
        // ȥ����β�Ļ��з�
        line[strcspn(line, "\n")] = '\0';

        // ������һ������
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

        // �������ڵ�
        root = createNode(rootName, count, NULL); // ��ʼ�����ڵ�� count Ϊ����ֵ��˫�׽ڵ�Ϊ NULL

        // ������һ���ӽڵ㲢����
        insertFirstChild(root, childName, count);
    }
    else {
        printf("File is empty\n");
        fclose(file);
        return 1;
    }

    // ��ȡ�ļ�����
    while (fgets(line, sizeof(line), file)) {
        // ȥ����β�Ļ��з�
        line[strcspn(line, "\n")] = '\0';

        // ����������
        char* token = strtok(line, " ");
        if (token == NULL) continue;

        char* word1 = token;
        token = strtok(NULL, " ");
        if (token == NULL) continue;

        int count = atoi(token);
        token = strtok(NULL, " ");
        if (token == NULL) continue;

        char* word2 = token;

        // ���һ򴴽�����1��Ӧ�Ľڵ�
        BiTreeNode* node1 = findNodeByName(root, word1);
        if (node1 == NULL) {
            node1 = createNode(word1, 0, root); // ��ʼ�� count Ϊ 0��˫�׽ڵ�Ϊ���ڵ�
            insertFirstChild(root, word1, 0); // ���뵽���ڵ�ĵ�һ���ӽڵ�
        }

        // ��������2��Ӧ�Ľڵ�
        BiTreeNode* node2 = createNode(word2, count, node1); // ����˫�׽ڵ�Ϊ node1

        // ������2���뵽����1�ĵ�һ���ӽڵ�
        insertFirstChild(node1, word2, count);
    }

    // �ر��ļ�
    fclose(file);

    // ��ȡ��ѯ�ļ�
    FILE* queries = fopen("queries.txt", "r");
    if (queries == NULL) {
        printf("Failed to open queries file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), queries)) {

        // ������ѯ����
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

    // �رղ�ѯ�ļ�
    fclose(queries);
    // �ͷ������ڴ�
    freeTree(root);

    return 0;
}