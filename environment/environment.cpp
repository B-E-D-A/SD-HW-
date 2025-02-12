#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "graph.h"
#include "graphAlgorithms.h"

template<typename Func>
long long benchmark(Func &&func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = end - start;
    return duration.count();
}

Graph createCompleteGraph(int numVertices) {
    std::vector<std::vector<int>> adjMatrix(numVertices, std::vector<int>(numVertices, 1));
    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i][i] = 0;
    }
    return Graph(adjMatrix);
}

Graph createRandomGraph(int numVertices, int numEdges) {
    std::vector<std::vector<int>> adjMatrix(numVertices, std::vector<int>(numVertices, 0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    std::uniform_int_distribution<> disVertices(0, numVertices - 1);

    for (int i = 0; i < numEdges; ++i) {
        int u = disVertices(gen);
        int v = disVertices(gen);
        int weight = dis(gen);
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    return Graph(adjMatrix);
}

void benchmarkAlgorithms(int numVertices) {
    Graph completeGraph = createCompleteGraph(numVertices);
    Graph randomGraph1 = createRandomGraph(numVertices, numVertices * 2);
    Graph randomGraph2 = createRandomGraph(numVertices, numVertices * 2);
    Graph randomGraph3 = createRandomGraph(numVertices, numVertices * 2);

    GraphAlgorithms gaComplete(completeGraph);
    GraphAlgorithms gaRandom1(randomGraph1);
    GraphAlgorithms gaRandom2(randomGraph2);
    GraphAlgorithms gaRandom3(randomGraph3);

    std::cout << "Benchmarking complete graph with " << numVertices << " vertices:\n";
    long long bfsTime = benchmark([&]() { gaComplete.bfs(0); });
    std::cout << "BFS time: " << bfsTime << " ms\n";

    long long dijkstraTime = benchmark([&]() { gaComplete.dijkstra(0); });
    std::cout << "Dijkstra time: " << dijkstraTime << " ms\n";

    long long bellmanFordTime = benchmark([&]() { gaComplete.bellmanFord(0); });
    std::cout << "Bellman-Ford time: " << bellmanFordTime << " ms\n";

    // Для случайного графа 1
    std::cout << "\nBenchmarking random graph 1 with " << numVertices << " vertices:\n";
    bfsTime = benchmark([&]() { gaRandom1.bfs(0); });
    std::cout << "BFS time: " << bfsTime << " ms\n";

    dijkstraTime = benchmark([&]() { gaRandom1.dijkstra(0); });
    std::cout << "Dijkstra time: " << dijkstraTime << " ms\n";

    bellmanFordTime = benchmark([&]() { gaRandom1.bellmanFord(0); });
    std::cout << "Bellman-Ford time: " << bellmanFordTime << " ms\n";

    // Для случайного графа 2
    std::cout << "\nBenchmarking random graph 2 with " << numVertices << " vertices:\n";
    bfsTime = benchmark([&]() { gaRandom2.bfs(0); });
    std::cout << "BFS time: " << bfsTime << " ms\n";

    dijkstraTime = benchmark([&]() { gaRandom2.dijkstra(0); });
    std::cout << "Dijkstra time: " << dijkstraTime << " ms\n";

    bellmanFordTime = benchmark([&]() { gaRandom2.bellmanFord(0); });
    std::cout << "Bellman-Ford time: " << bellmanFordTime << " ms\n";

    // Для случайного графа 3
    std::cout << "\nBenchmarking random graph 3 with " << numVertices << " vertices:\n";
    bfsTime = benchmark([&]() { gaRandom3.bfs(0); });
    std::cout << "BFS time: " << bfsTime << " ms\n";

    dijkstraTime = benchmark([&]() { gaRandom3.dijkstra(0); });
    std::cout << "Dijkstra time: " << dijkstraTime << " ms\n";

    bellmanFordTime = benchmark([&]() { gaRandom3.bellmanFord(0); });
    std::cout << "Bellman-Ford time: " << bellmanFordTime << " ms\n";

}

int main() {
    int numVertices = 100;
    benchmarkAlgorithms(numVertices);
    return 0;
}
