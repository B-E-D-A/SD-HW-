#include "graphAlgorithms.h"
#include <vector>
#include <limits>

/**
 * @brief Реализация алгоритма Беллмана-Форда для нахождения кратчайших путей с возможностью отрицательных весов.
 */

std::vector<int> GraphAlgorithms::bellmanFord(int startVertex) {
    const int numVertices = graph.getNumVertices();
    std::vector<int> distances(numVertices, std::numeric_limits<int>::max());
    distances[startVertex] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
        for (int u = 0; u < numVertices; ++u) {
            for (int v = 0; v < numVertices; ++v) {
                int weight = graph.getAdjMatrix()[u][v];
                if (weight != 0 && distances[u] != std::numeric_limits<int>::max() &&
                    distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }
    }

    return distances;
}
