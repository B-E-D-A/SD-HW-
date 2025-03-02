#include "graphAlgorithms.h"
#include <queue>
#include <vector>
#include <iostream>

/**
 * @brief Реализация алгоритма поиска в ширину (BFS) для обхода графа от стартовой вершины.
 */
std::vector<int> GraphAlgorithms::bfs(int startVertex) {
    const int numVertices = graph.getNumVertices();
    std::vector<int> distances(numVertices, -1);
    std::queue<int> q;

    distances[startVertex] = 0;
    q.push(startVertex);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int i = 0; i < numVertices; ++i) {
            if (graph.getAdjMatrix()[vertex][i] != 0 && distances[i] == -1) {
                distances[i] = distances[vertex] + 1;
                q.push(i);
            }
        }
    }

    return distances;
}
