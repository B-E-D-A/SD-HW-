#include "graphAlgorithms.h"
#include <deque>
#include <vector>
#include <climits>


/**
 * @brief 0-1 BFS для графов с весами рёбер 0 или 1.
 * 
 * Использует дек для обработки вершин в оптимальном порядке, сохраняя сложность O(V + E).
 */
std::vector<int> GraphAlgorithms::zeroOneBfs(int startVertex) {
    const int numVertices = graph.getNumVertices();
    std::vector<int> distances(numVertices, -1); // -1 indicates that a vertex hasn't been visited.
    std::deque<int> dq;

    distances[startVertex] = 0;
    dq.push_front(startVertex);

    while (!dq.empty()) {
        int vertex = dq.front();
        dq.pop_front();

        for (int i = 0; i < numVertices; ++i) {
            int edgeWeight = graph.getAdjMatrix()[vertex][i];
            
            if (edgeWeight == 0 || edgeWeight == 1) {
                int newDist = distances[vertex] + edgeWeight;
                
                if (newDist < distances[i] || distances[i] == -1) {
                    distances[i] = newDist;
                    
                    if (edgeWeight == 0) {
                        dq.push_front(i);
                    } else {
                        dq.push_back(i);
                    }
                }
            }
        }
    }

    return distances;
}