#include "city.h"

void initGraph(Graph *graph) {
    graph->cityCount = 0;
    for (int i = 0; i < MAX_CITIES; i++) {
        for (int j = 0; j < MAX_CITIES; j++) {
            graph->matrix[i][j].cost = -1;
            graph->matrix[i][j].distance = -1;
        }
    }
}

int findCityIndex(Graph *graph, const char *cityName) {
    for (int i = 0; i < graph->cityCount; ++i) {
        if (strcmp(graph->cities[i].name, cityName) == 0) {
            return i;
        }
    }
    return -1;
}

void addCity(Graph *graph, const char *cityName) {
    if (findCityIndex(graph, cityName) == -1) {
        strcpy(graph->cities[graph->cityCount].name, cityName);
        graph->cities[graph->cityCount].index = graph->cityCount;
        graph->cityCount++;
    }
}

void addEdge(Graph *graph, const char *fromCity, const char *toCity, int cost, int distance) {
    int fromIndex = findCityIndex(graph, fromCity);
    int toIndex = findCityIndex(graph, toCity);
    if (fromIndex != -1 && toIndex != -1) {
        graph->matrix[fromIndex][toIndex].cost = cost;
        graph->matrix[fromIndex][toIndex].distance = distance;
    } else {
        printf("Error: One or both cities not found.\n");
    }
}

void loadServicesFromFile(Graph *graph, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char fromCity[CITY_NAME_LEN], toCity[CITY_NAME_LEN];
    int cost, distance;

    while (fscanf(file, "%s %s %d %d", fromCity, toCity, &cost, &distance) == 4) {
        addCity(graph, fromCity);
        addCity(graph, toCity);
        addEdge(graph, fromCity, toCity, cost, distance);
    }

    fclose(file);
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->cityCount; i++) {
        printf("City: %s\n", graph->cities[i].name);
        for (int j = 0; j < graph->cityCount; j++) {
            if (graph->matrix[i][j].cost != -1) {
                printf("\tTo: %s, Cost: %d, Distance: %d\n", graph->cities[j].name, graph->matrix[i][j].cost, graph->matrix[i][j].distance);
            }
        }
    }
}