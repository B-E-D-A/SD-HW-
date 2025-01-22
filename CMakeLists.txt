cmake_minimum_required(VERSION 3.13)
project(SD_project)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCES
    src/algorithms/bfs.cpp
    src/algorithms/dijkstra.cpp
    src/algorithms/bellman_ford.cpp
    src/algorithms/a_star.cpp
    src/algorithms/floyd_warshall.cpp
    src/algorithms/johnson.cpp
    src/graph.cpp
    src/utility.cpp
)

add_executable(SD_project ${SOURCES})

# enable_testing()
