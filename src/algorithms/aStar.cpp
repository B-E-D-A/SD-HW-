#include "graphAlgorithms.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

struct Node {
    int vertex;
    int cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

/**
 * @brief Реализация алгоритма A* для нахождения кратчайших путей от стартовой вершины до всех остальных.
 */
std::vector<int> GraphAlgorithms::aStar(int startVertex) {
    const int numVertices = graph.getNumVertices();
    std::vector<int> distances(numVertices, std::numeric_limits<int>::max());
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

    distances[startVertex] = 0;
    pq.push({startVertex, 0});

    while (!pq.empty()) {
        int vertex = pq.top().vertex;
        int cost = pq.top().cost;
        pq.pop();

        if (cost > distances[vertex]) continue;

        for (int i = 0; i < numVertices; ++i) {
            if (graph.getAdjMatrix()[vertex][i] != 0) {
                int newCost = distances[vertex] + graph.getAdjMatrix()[vertex][i];
                if (newCost < distances[i]) {
                    distances[i] = newCost;
                    pq.push({i, newCost});
                }
            }
        }
    }

    return distances;
}

