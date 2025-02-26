#include "graphAlgorithms.h"
#include "graph.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <limits>

void testDijkstra() {
    const int INF = std::numeric_limits<int>::max();

    // Тест 1: Обычный взвешенный граф
    {
        std::vector<std::vector<int>> matrix = {
                {0, 10, 3, 0, 0},
                {10, 0, 1, 2, 0},
                {3, 1, 0, 8, 2},
                {0, 2, 8, 0, 7},
                {0, 0, 2, 7, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.bruteForce(0);
        std::vector<int> expected = {0, 4, 3, 6, 5};
        assert(result == expected && "Test 1 Failed: Dijkstra result mismatch");
    }

    // Тест 2: Граф с несвязанной вершиной
    {
        std::vector<std::vector<int>> matrix = {
                {0, 4, 0, 0, 0},
                {4, 0, 6, 5, 0},
                {0, 6, 0, 2, 0},
                {0, 5, 2, 0, 0},
                {0, 0, 0, 0, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.bruteForce(0);
        std::vector<int> expected = {0, 4, 10, 9, INF};
        assert(result == expected && "Test 2 Failed: Dijkstra result mismatch");
    }

    // Тест 3: Полностью связанный граф
    {
        std::vector<std::vector<int>> matrix = {
                {0, 1, 2, 3},
                {1, 0, 4, 2},
                {2, 4, 0, 1},
                {3, 2, 1, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.bruteForce(0);
        std::vector<int> expected = {0, 1, 2, 3};
        assert(result == expected && "Test 3 Failed: Dijkstra result mismatch");
    }

    std::cout << "All Dijkstra tests passed successfully!" << std::endl;
}

int main() {
    testDijkstra();
    return 0;
}

