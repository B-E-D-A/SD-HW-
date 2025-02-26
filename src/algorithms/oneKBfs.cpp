#include "graphAlgorithms.h"
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>

/**
 * @brief Реализация алгоритма поиска в ширину (1-k BFS) для обхода графа с натуральными 
 * весами ребер от 1 до k от стартовой вершины.
 */
std::vector<int> GraphAlgorithms::oneKBfs(int startVertex, int k) {
    int n = graph.getNumVertices();
    std::vector<int> distances(n, -1); // -1 indicates that a vertex hasn't been visited.
    std::queue<int> q;
    std::unordered_set<int> visited;

    q.push(startVertex);
    distances[startVertex] = 0;
    visited.insert(startVertex);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (distances[current] >= k) {
            continue; // We've reached the desired distance k
        }

        for (const auto& neighbor : graph.getNeighbors(current)) {
            int neighborVertex = neighbor.first;
            int edgeWeight = neighbor.second;

            if (visited.find(neighborVertex) == visited.end()) {
                q.push(neighborVertex);
                visited.insert(neighborVertex);
                distances[neighborVertex] = distances[current] + 1;
            }
        }
    }

    // Collect nodes that are within distance k
    std::vector<int> nodesWithinDistanceK;
    for (int i = 0; i < n; ++i) {
        if (distances[i] != -1 && distances[i] <= k) {
            nodesWithinDistanceK.push_back(i);
        }
    }

    return nodesWithinDistanceK;
}
