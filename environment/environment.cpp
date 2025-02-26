#include <benchmark/benchmark.h>
#include "graph.h"
#include "graphAlgorithms.h"
#include <vector>
#include <random>
#include <memory>

static std::unique_ptr<Graph> completeGraph;
static std::unique_ptr<Graph> randomGraph1;
static std::unique_ptr<Graph> randomGraph2;
static std::unique_ptr<Graph> randomGraph3;

Graph createCompleteGraph(int numVertices) {
    std::vector<std::vector<int>> adjMatrix(numVertices, std::vector<int>(numVertices, 1));
    for (int i = 0; i < numVertices; ++i)
        adjMatrix[i][i] = 0;
    return Graph(adjMatrix);
}

Graph createRandomGraph(int numVertices, int numEdges) {
    std::vector<std::vector<int>> adjMatrix(numVertices, std::vector<int>(numVertices, 0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> weightDist(1, 10);
    std::uniform_int_distribution<> vertexDist(0, numVertices - 1);
    for (int i = 0; i < numEdges; ++i) {
        int u = vertexDist(gen);
        int v = vertexDist(gen);
        int weight = weightDist(gen);
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    return Graph(adjMatrix);
}

static void SetupGraphs(int numVertices) {
    completeGraph = std::make_unique<Graph>(createCompleteGraph(numVertices));
    randomGraph1 = std::make_unique<Graph>(createRandomGraph(numVertices, numVertices * 2));
    randomGraph2 = std::make_unique<Graph>(createRandomGraph(numVertices, numVertices * 2));
    randomGraph3 = std::make_unique<Graph>(createRandomGraph(numVertices, numVertices * 2));
}

static void BM_BFS_Complete(benchmark::State& state) {
    GraphAlgorithms ga(*completeGraph);
    for (auto _ : state) {
        ga.bfs(0);
    }
}
BENCHMARK(BM_BFS_Complete);

static void BM_Dijkstra_Complete(benchmark::State& state) {
    GraphAlgorithms ga(*completeGraph);
    for (auto _ : state) {
        ga.dijkstra(0);
    }
}
BENCHMARK(BM_Dijkstra_Complete);

static void BM_BellmanFord_Complete(benchmark::State& state) {
    GraphAlgorithms ga(*completeGraph);
    for (auto _ : state) {
        ga.bellmanFord(0);
    }
}
BENCHMARK(BM_BellmanFord_Complete);

static void BM_AStar_Complete(benchmark::State& state) {
    GraphAlgorithms ga(*completeGraph);
    for (auto _ : state) {
        ga.aStar(0);
    }
}
BENCHMARK(BM_AStar_Complete);

static void BM_oneKBFS_Complete(benchmark::State& state) {
    GraphAlgorithms ga(*completeGraph);
    for (auto _ : state) {
        ga.oneKBfs(0);
    }
}
BENCHMARK(BM_oneKBFS_Complete);

static void BM_floydWarshall_Complete(benchmark::State& state) {
    GraphAlgorithms ga(*completeGraph);
    for (auto _ : state) {
        ga.floydWarshall();
    }
}
BENCHMARK(BM_floydWarshall_Complete);

static void BM_BFS_Random1(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph1);
    for (auto _ : state) {
        ga.bfs(0);
    }
}
BENCHMARK(BM_BFS_Random1);

static void BM_Dijkstra_Random1(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph1);
    for (auto _ : state) {
        ga.dijkstra(0);
    }
}
BENCHMARK(BM_Dijkstra_Random1);

static void BM_BellmanFord_Random1(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph1);
    for (auto _ : state) {
        ga.bellmanFord(0);
    }
}
BENCHMARK(BM_BellmanFord_Random1);

static void BM_AStar_Random1(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph1);
    for (auto _ : state) {
        ga.aStar(0);
    }
}
BENCHMARK(BM_AStar_Random1);

static void BM_oneKBfs_Random1(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph1);
    for (auto _ : state) {
        ga.oneKBfs(0);
    }
}
BENCHMARK(BM_oneKBfs_Random1);

static void BM_floydWarshall_Random1(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph1);
    for (auto _ : state) {
        ga.floydWarshall();
    }
}
BENCHMARK(BM_floydWarshall_Random1);

static void BM_BFS_Random2(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph2);
    for (auto _ : state) {
        ga.bfs(0);
    }
}
BENCHMARK(BM_BFS_Random2);

static void BM_Dijkstra_Random2(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph2);
    for (auto _ : state) {
        ga.dijkstra(0);
    }
}
BENCHMARK(BM_Dijkstra_Random2);

static void BM_BellmanFord_Random2(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph2);
    for (auto _ : state) {
        ga.bellmanFord(0);
    }
}
BENCHMARK(BM_BellmanFord_Random2);

static void BM_AStar_Random2(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph2);
    for (auto _ : state) {
        ga.aStar(0);
    }
}
BENCHMARK(BM_AStar_Random2);

static void BM_oneKBfs_Random2(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph2);
    for (auto _ : state) {
        ga.oneKBfs(0);
    }
}
BENCHMARK(BM_oneKBfs_Random2);

static void BM_floydWarshall_Random2(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph2);
    for (auto _ : state) {
        ga.floydWarshall();
    }
}
BENCHMARK(BM_floydWarshall_Random2);

static void BM_BFS_Random3(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph3);
    for (auto _ : state) {
        ga.bfs(0);
    }
}
BENCHMARK(BM_BFS_Random3);

static void BM_Dijkstra_Random3(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph3);
    for (auto _ : state) {
        ga.dijkstra(0);
    }
}
BENCHMARK(BM_Dijkstra_Random3);

static void BM_BellmanFord_Random3(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph3);
    for (auto _ : state) {
        ga.bellmanFord(0);
    }
}
BENCHMARK(BM_BellmanFord_Random3);

static void BM_AStar_Random3(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph3);
    for (auto _ : state) {
        ga.aStar(0);
    }
}
BENCHMARK(BM_AStar_Random3);

static void BM_oneKBfs_Random3(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph3);
    for (auto _ : state) {
        ga.oneKBfs(0);
    }
}
BENCHMARK(BM_oneKBfs_Random3);

static void BM_floydWarshall_Random3(benchmark::State& state) {
    GraphAlgorithms ga(*randomGraph3);
    for (auto _ : state) {
        ga.floydWarshall();
    }
}
BENCHMARK(BM_floydWarshall_Random3);

int main(int argc, char** argv) {
    ::benchmark::Initialize(&argc, argv);

    int numVertices = 500;
    SetupGraphs(numVertices);

    ::benchmark::RunSpecifiedBenchmarks();
    return 0;
}
