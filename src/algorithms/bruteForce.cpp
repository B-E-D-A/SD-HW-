#include "graphAlgorithms.h"
#include <algorithm>
#include <vector>
#include <limits>


std::vector<int> GraphAlgorithms::bruteForce(int startVertex) {
    const int numVertices = graph.getNumVertices();
    const auto& adjMatrix = graph.getAdjMatrix();
    std::vector<int> distances(numVertices, std::numeric_limits<int>::max());
    distances[startVertex] = 0;

    std::vector<int> vertices;
    for (int i = 0; i < numVertices; ++i) {
        if (i != startVertex) {
            vertices.push_back(i);
        }
    }

    // Перебор всевозможных перестановок для всех вершин графа
    do {
        int currentVertex = startVertex;
        int currentDistance = 0;

        for (int vertex : vertices) {
            if (adjMatrix[currentVertex][vertex] > 0) {
                currentDistance += adjMatrix[currentVertex][vertex];
                distances[vertex] = std::min(distances[vertex], currentDistance);
                currentVertex = vertex;
            } else {
                break;
            }
        }
    } while (std::next_permutation(vertices.begin(), vertices.end()));

    return distances;
}