#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include "graph.h"
#include <vector>
#include <utility>

class GraphAlgorithms {
private:
    Graph graph;

public:
    explicit GraphAlgorithms(const Graph& g) : graph(g) {}

    std::vector<int> bfs(int startVertex);
    std::vector<int> dijkstra(int startVertex);
    std::vector<int> bellmanFord(int startVertex);
    std::vector<int> aStar(int startVertex, int goalVertex);
    std::vector<std::vector<int>> floydWarshall();
    std::vector<std::vector<int>> johnson();
};

#endif // GRAPH_ALGORITHMS_H
