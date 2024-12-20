#include "city.h"

int main() {
    Graph graph;
    initGraph(&graph);

    loadServicesFromFile(&graph, "services.txt");

    printGraph(&graph);

    return 0;
}