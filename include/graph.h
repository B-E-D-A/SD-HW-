#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

class Graph {
private:
    bool isDirected;
    int vertexCount;
    int edgesCount;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertices, bool isDirected = false)
        : vertexCount(vertices), isDirected(isDirected), edgesCount(0) {
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    Graph(const std::vector<std::vector<int>>& adjMatrix, bool isDirected = false)
            : adjMatrix(adjMatrix), isDirected(isDirected), vertexCount(adjMatrix.size()), edgesCount(0) {
        for (int i = 0; i < vertexCount; ++i) {
            for (int j = 0; j < vertexCount; ++j) {
                if (adjMatrix[i][j] != 0) {
                    edgesCount++;
                    if (!isDirected && i != j) {
                        edgesCount++;
                    }
                }
            }
        }
    }

    bool isDirectedGraph() const {
        return isDirected;
    }
    int getNumVertices() const {
        return vertexCount;
    }
    int getNumEdges() const {
        return edgesCount;
    }
    const std::vector<std::vector<int>>& getAdjMatrix() const {
        return adjMatrix;
    }

    std::vector<std::pair<int, int>> getNeighbors(int vertex) const {
        std::vector<std::pair<int, int>> neighbors;
        for (int i = 0; i < vertexCount; ++i) {
            if (adjMatrix[vertex][i] != 0) {
                neighbors.emplace_back(i, adjMatrix[vertex][i]);
            }
        }
        return neighbors;
    }
};

#endif // GRAPH_H
