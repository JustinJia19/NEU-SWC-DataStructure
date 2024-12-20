#ifndef CITY_H
#define CITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 50
#define CITY_NAME_LEN 50

typedef struct {
    char name[CITY_NAME_LEN];
    int index;
} City;

typedef struct {
    int cost;
    int distance;
} Edge;

typedef struct {
    City cities[MAX_CITIES];
    Edge matrix[MAX_CITIES][MAX_CITIES];
    int cityCount;
} Graph;

// //��ʼ��һ��ͼ����ȨΪ -1
void initGraph(Graph *graph);
//ͨ�����Ʋ����±�
int findCityIndex(Graph *graph, const char *cityName);
//��ӳ���
void addCity(Graph *graph, const char *cityName);
//��ӱ�
void addEdge(Graph *graph, const char *fromCity, const char *toCity, int cost, int distance);
//���ļ��ж�ȡ��Ϣ
void loadServicesFromFile(Graph *graph, const char *filename);
//��ӡͼ
void printGraph(Graph *graph);

#endif