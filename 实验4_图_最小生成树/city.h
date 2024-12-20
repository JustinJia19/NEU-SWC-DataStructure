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

// //初始化一个图，边权为 -1
void initGraph(Graph *graph);
//通过名称查找下标
int findCityIndex(Graph *graph, const char *cityName);
//添加城市
void addCity(Graph *graph, const char *cityName);
//添加边
void addEdge(Graph *graph, const char *fromCity, const char *toCity, int cost, int distance);
//从文件中读取信息
void loadServicesFromFile(Graph *graph, const char *filename);
//打印图
void printGraph(Graph *graph);

#endif