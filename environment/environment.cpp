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
static std::unique_ptr<Graph> treeGraph;
static std::unique_ptr<Graph> cycleGraph;

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

Graph createTreeGraph(int numVertices) {
    std::vector<std::vector<int>> adjMatrix(numVertices, std::vector<int>(numVertices, 0));
    for (int i = 1; i < numVertices; ++i) {
        adjMatrix[i][i - 1] = adjMatrix[i - 1][i] = 1;
    }
    return Graph(adjMatrix);
}

Graph createCycleGraph(int numVertices) {
    std::vector<std::vector<int>> adjMatrix(numVertices, std::vector<int>(numVertices, 0));
    for (int i = 0; i < numVertices - 1; ++i) {
        adjMatrix[i][i + 1] = adjMatrix[i + 1][i] = 1;
    }
    adjMatrix[numVertices - 1][0] = adjMatrix[0][numVertices - 1] = 1;
    return Graph(adjMatrix);
}

static void SetupGraphs(int numVertices) {
    completeGraph = std::make_unique<Graph>(createCompleteGraph(numVertices));
    randomGraph1 = std::make_unique<Graph>(createRandomGraph(numVertices, numVertices * 2));
    randomGraph2 = std::make_unique<Graph>(createRandomGraph(numVertices, numVertices * 2));
    randomGraph3 = std::make_unique<Graph>(createRandomGraph(numVertices, numVertices * 2));
    treeGraph = std::make_unique<Graph>(createTreeGraph(numVertices));
    cycleGraph = std::make_unique<Graph>(createCycleGraph(numVertices));
}

#define DEFINE_BENCHMARK(alg, graph) \
static void BM_##alg##_##graph(benchmark::State& state) { \
    GraphAlgorithms ga(*graph); \
    for (auto _ : state) { \
        ga.alg(0); \
    } \
} \
BENCHMARK(BM_##alg##_##graph);

DEFINE_BENCHMARK(bfs, completeGraph)
DEFINE_BENCHMARK(dijkstra, completeGraph)
DEFINE_BENCHMARK(bellmanFord, completeGraph)
DEFINE_BENCHMARK(aStar, completeGraph)

DEFINE_BENCHMARK(bfs, randomGraph1)
DEFINE_BENCHMARK(dijkstra, randomGraph1)
DEFINE_BENCHMARK(bellmanFord, randomGraph1)
DEFINE_BENCHMARK(aStar, randomGraph1)

DEFINE_BENCHMARK(bfs, randomGraph2)
DEFINE_BENCHMARK(dijkstra, randomGraph2)
DEFINE_BENCHMARK(bellmanFord, randomGraph2)
DEFINE_BENCHMARK(aStar, randomGraph2)

DEFINE_BENCHMARK(bfs, randomGraph3)
DEFINE_BENCHMARK(dijkstra, randomGraph3)
DEFINE_BENCHMARK(bellmanFord, randomGraph3)
DEFINE_BENCHMARK(aStar, randomGraph3)

DEFINE_BENCHMARK(bfs, treeGraph)
DEFINE_BENCHMARK(dijkstra, treeGraph)
DEFINE_BENCHMARK(bellmanFord, treeGraph)
DEFINE_BENCHMARK(aStar, treeGraph)

DEFINE_BENCHMARK(bfs, cycleGraph)
DEFINE_BENCHMARK(dijkstra, cycleGraph)
DEFINE_BENCHMARK(bellmanFord, cycleGraph)
DEFINE_BENCHMARK(aStar, cycleGraph)

int main(int argc, char** argv) {
    benchmark::Initialize(&argc, argv);

    int numVertices = 500;
    SetupGraphs(numVertices);
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
    return 0;
}
