
#include "graphAlgorithms.h"
#include "graph.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <limits>

void testFloydWarshall() {
    const int INF = std::numeric_limits<int>::max();

    // Тест 1: Обычный взвешенный граф
    {
        std::vector<std::vector<int>> matrix = {
                {0, 10, 3, INF, INF},
                {10, 0, 1, 2, INF},
                {3, 1, 0, 8, 2},
                {INF, 2, 8, 0, 7},
                {INF, INF, 2, 7, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<std::vector<int>> result = ga.floydWarshall();
        std::vector<std::vector<int>> expected = {
                {0, 4, 3, 6, 5},
                {4, 0, 1, 2, 3},
                {3, 1, 0, 3, 2},
                {6, 2, 3, 0, 5},
                {5, 3, 2, 5, 0}
        };
        assert(result == expected && "Test 1 Failed: Floyd-Warshall result mismatch");
    }

    // Тест 2: Граф с несвязанной вершиной
    {
        std::vector<std::vector<int>> matrix = {
                {0, 4, INF, INF, INF},
                {4, 0, 6, 5, INF},
                {INF, 6, 0, 2, INF},
                {INF, 5, 2, 0, INF},
                {INF, INF, INF, INF, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<std::vector<int>> result = ga.floydWarshall();
        std::vector<std::vector<int>> expected = {
                {0, 4, 10, 9, INF},
                {4, 0, 6, 5, INF},
                {10, 6, 0, 2, INF},
                {9, 5, 2, 0, INF},
                {INF, INF, INF, INF, 0}
        };
        assert(result == expected && "Test 2 Failed: Floyd-Warshall result mismatch");
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
        std::vector<std::vector<int>> result = ga.floydWarshall();
        std::vector<std::vector<int>> expected = {
                {0, 1, 2, 3},
                {1, 0, 3, 2},
                {2, 3, 0, 1},
                {3, 2, 1, 0}
        };
        assert(result == expected && "Test 3 Failed: Floyd-Warshall result mismatch");
    }

    std::cout << "All Floyd-Warshall tests passed successfully!" << std::endl;
}

int main() {
    testFloydWarshall();
    return 0;
}
