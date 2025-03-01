#include "graphAlgorithms.h"
#include "graph.h"
#include <iostream>
#include <cassert>
#include <vector>

void testZeroOneBFS() {
    // Тест 1: Ориентированный граф с путями весов 0 и 1
    {
        std::vector<std::vector<int>> matrix = {
            {0, 1, -1, -1},
            {-1, 0, 0, -1},
            {-1, -1, 0, 1},
            {-1, -1, -1, 0}
        };
        Graph g(matrix, true);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.zeroOneBfs(0);
        std::vector<int> expected = {0, 1, 1, 2};
        assert(result == expected && "Test 1 Failed: 0-1-BFS result mismatch");
    }

    // Тест 2: Граф с двумя компонентами связности
    {
        std::vector<std::vector<int>> matrix = {
            {0, 1, -1, -1, -1},
            {1, 0, -1, -1, -1},
            {-1, -1, 0, 0, -1},
            {-1, -1, 0, 0, 1},
            {-1, -1, -1, 1, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.zeroOneBfs(0);
        std::vector<int> expected = {0, 1, -1, -1, -1};
        assert(result == expected && "Test 2 Failed: 0-1-BFS result mismatch");
    }

    // Тест 3: Неориентированный граф с путем из нулевых весов
    {
        std::vector<std::vector<int>> matrix = {
            {0, 0, 1},
            {0, 0, 0},
            {1, 0, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.zeroOneBfs(0);
        std::vector<int> expected = {0, 0, 0};
        assert(result == expected && "Test 3 Failed: 0-1-BFS result mismatch");
    }

    // Тест 4: Ориентированный граф с последовательными ребрами веса 1
    {
        std::vector<std::vector<int>> matrix = {
            {0, 1, -1, -1},
            {-1, 0, 1, -1},
            {-1, -1, 0, 1},
            {-1, -1, -1, 0}
        };
        Graph g(matrix, true);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.zeroOneBfs(0);
        std::vector<int> expected = {0, 1, 2, 3};
        assert(result == expected && "Test 4 Failed: 0-1-BFS result mismatch");
    }

    // Тест 5: Две изолированные вершины
    {
        std::vector<std::vector<int>> matrix = {
            {0, -1},
            {-1, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.zeroOneBfs(0);
        std::vector<int> expected = {0, -1};
        assert(result == expected && "Test 5 Failed: 0-1-BFS result mismatch");
    }

    std::cout << "All 0-1-BFS tests passed successfully!" << std::endl;
}

int main() {
    testZeroOneBFS();
    return 0;
}