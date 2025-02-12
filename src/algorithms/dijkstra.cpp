#include "graphAlgorithms.h"
#include <vector>
#include <queue>
#include <limits>

std::vector<int> GraphAlgorithms::dijkstra(int startVertex) {
    const int numVertices = graph.getNumVertices();
    std::vector<int> distances(numVertices, std::numeric_limits<int>::max());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    distances[startVertex] = 0;
    pq.push({0, startVertex});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        if (dist > distances[vertex]) continue;

        for (int i = 0; i < numVertices; ++i) {
            int weight = graph.getAdjMatrix()[vertex][i];
            if (weight > 0) {  // Учитываем только существующие рёбра
                int newDist = distances[vertex] + weight;
                if (newDist < distances[i]) {
                    distances[i] = newDist;
                    pq.push({newDist, i});
                }
            }
        }
    }

    return distances;
}
