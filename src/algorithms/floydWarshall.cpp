#include "graphAlgorithms.h"
#include <climits>
#include <iostream>

/**
 * @brief Реализация алгоритма Флойда-Уоршелла для нахождения всех пар кратчайших путей.
 */
std::vector<std::vector<int>> GraphAlgorithms::floydWarshall() {
    std::cout << "Floyd-Warshall algorithm called" << std::endl;

    const std::vector<std::vector<int>> &adjMatrix = graph.getAdjMatrix();
    int vertexCount = graph.getNumVertices();
    int inf = INT_MAX;

    std::vector<std::vector<int>> dist(vertexCount,
                                        std::vector<int>(vertexCount, inf));

    for (int i = 0; i < vertexCount; ++i) {
        for (int j = 0; j < vertexCount; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (adjMatrix[i][j] != 0) {
                dist[i][j] = adjMatrix[i][j];
            }
        }
    }

    for (int k = 0; k < vertexCount; ++k) {
        for (int i = 0; i < vertexCount; ++i) {
            for (int j = 0; j < vertexCount; ++j) {
                if (dist[i][k] != inf && dist[k][j] != inf) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    return dist;
}
