#include "graphAlgorithms.h"
#include "graph.h"
#include <iostream>
#include <cassert>
#include <vector>

void testOneKBFS() {
    // Тест 1: Граф с одним компонентом связности
    {
        std::vector<std::vector<int>> matrix = {
                {0, 1, 0, 0},
                {1, 0, 1, 0},
                {0, 1, 0, 1},
                {0, 0, 1, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.oneKBfs(0);
        std::vector<int> expected = {0, 1, 2, 3};
        assert(result == expected && "Test 1 Failed: 1-k-BFS result mismatch");
    }

    // Тест 2: Граф с несколькими компонентами связности
    {
        std::vector<std::vector<int>> matrix = {
                {0, 1, 0, 0, 0},
                {1, 0, 1, 0, 0},
                {0, 1, 0, 0, 0},
                {0, 0, 0, 0, 1},
                {0, 0, 0, 1, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.oneKBfs(0);
        std::vector<int> expected = {0, 1, 2, -1, -1};
        assert(result == expected && "Test 2 Failed: 1-k-BFS result mismatch");
    }

    // Тест 3: Граф с циклом (0 - 1 - 2 - 0)
    {
        std::vector<std::vector<int>> matrix = {
                {0, 1, 0},
                {1, 0, 1},
                {0, 1, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.oneKBfs(0);
        std::vector<int> expected = {0, 1, 2};
        assert(result == expected && "Test 3 Failed: 1-k-BFS result mismatch");
    }

    // Тест 4: Ориентированный граф (0 -> 1 -> 2)
    {
        std::vector<std::vector<int>> matrix = {
                {0, 1, 0},
                {0, 0, 1},
                {0, 0, 0}
        };
        Graph g(matrix, true);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.oneKBfs(0);
        std::vector<int> expected = {0, 1, 2};
        assert(result == expected && "Test 4 Failed: 1-k-BFS result mismatch");
    }

    // Тест 5: Пустой граф
    {
        std::vector<std::vector<int>> matrix = {
                {0, 0},
                {0, 0}
        };
        Graph g(matrix);
        GraphAlgorithms ga(g);
        std::vector<int> result = ga.oneKBfs(0);
        std::vector<int> expected = {0, -1};
        assert(result == expected && "Test 5 Failed: 1-k-BFS result mismatch");
    }

    std::cout << "All 1-k-BFS tests passed successfully!" << std::endl;
}

int main() {
    testOneKBFS();
    return 0;
}
