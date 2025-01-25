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

    bool isDirected() const {
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
};

#endif // GRAPH_H
