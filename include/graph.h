#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

/**
 * @class Graph
 * Этот класс реализует граф с заданным числом вершин и возможностью указания, является ли граф направленным.
 * Он позволяет добавлять рёбра, проверять соседей вершин и работать с матрицей смежности.
 */

class Graph {
private:
    bool isDirected;
    int vertexCount;
    int edgesCount;
    std::vector<std::vector<int>> adjMatrix;

public:
    /**
     * Конструктор для создания графа с заданным количеством вершин и флагом направленности.
     */
    Graph(int vertices, bool isDirected = false)
        : vertexCount(vertices), isDirected(isDirected), edgesCount(0) {
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    /**
     * Конструктор для создания графа с использованием матрицы смежности.
     */
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

    /**
     * Получение информации о том, является ли граф направленным.
     * @return true, если граф направленный; false, если граф ненаправленный.
     */
    bool isDirectedGraph() const {
        return isDirected;
    }

    /**
     * Получение количества вершин в графе.
     * @return Количество вершин в графе.
     */
    int getNumVertices() const {
        return vertexCount;
    }

    /**
     * Получение количества рёбер в графе.
     * @return Количество рёбер в графе.
     */
    int getNumEdges() const {
        return edgesCount;
    }

    /**
     * Получение матрицы смежности графа.
     * @return Ссылка на матрицу смежности.
     */
    const std::vector<std::vector<int>>& getAdjMatrix() const {
        return adjMatrix;
    }

    /**
     * Получение соседей заданной вершины.
     * @param vertex Индекс вершины.
     * @return Вектор пар, где каждая пара содержит индекс соседней вершины и вес рёбра.
     */
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
