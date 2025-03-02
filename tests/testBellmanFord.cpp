#include <iostream>
#include <vector>
#include <limits>
#include "graphAlgorithms.h"
#include "graph.h"

void testBellmanFord() {
    // Тест 1: Граф без отрицательных циклов
    std::vector<std::vector<int>> adjMatrix1 = {
            {0, 5, 0, 0, 0},
            {5, 0, 2, 0, 0},
            {0, 2, 0, 3, 0},
            {0, 0, 3, 0, 1},
            {0, 0, 0, 1, 0}
    };
    Graph g1(adjMatrix1);
    GraphAlgorithms ga1(g1);
    std::vector<int> result1 = ga1.bellmanFord(0);

    std::vector<int> expected1 = {0, 5, 7, 6, 7};
    bool test1_passed = (result1 == expected1);
    std::cout << "Test 1 - Graph without negative cycles: " << (test1_passed ? "Passed" : "Failed") << std::endl;

    // Тест 2: Граф с отрицательным циклом
    std::vector<std::vector<int>> adjMatrix2 = {
            {0, 5, 0, 0},
            {5, 0, -1, 0},
            {0, -1, 0, 2},
            {0, 0, 2, 0}
    };
    Graph g2(adjMatrix2);
    GraphAlgorithms ga2(g2);
    std::vector<int> result2 = ga2.bellmanFord(0);

    bool negativeCycleDetected = (result2[0] == std::numeric_limits<int>::max());
    std::cout << "Test 2 - Graph with negative cycle: "
              << (negativeCycleDetected ? "Passed" : "Failed") << std::endl;

    // Тест 3: Граф с одной вершиной
    std::vector<std::vector<int>> adjMatrix3 = {
            {0}
    };
    Graph g3(adjMatrix3);
    GraphAlgorithms ga3(g3);
    std::vector<int> result3 = ga3.bellmanFord(0);

    bool test3_passed = (result3[0] == 0);
    std::cout << "Test 3 - Graph with one vertex: " << (test3_passed ? "Passed" : "Failed") << std::endl;

    // Тест 4: Граф с равными ребрами
    std::vector<std::vector<int>> adjMatrix4 = {
            {0, 2, 2},
            {2, 0, 2},
            {2, 2, 0}
    };
    Graph g4(adjMatrix4);
    GraphAlgorithms ga4(g4);
    std::vector<int> result4 = ga4.bellmanFord(0);

    std::vector<int> expected4 = {0, 2, 2};
    bool test4_passed = (result4 == expected4);
    std::cout << "Test 4 - Graph with equal weights: " << (test4_passed ? "Passed" : "Failed") << std::endl;
}

int main() {
    testBellmanFord();
    return 0;
}
