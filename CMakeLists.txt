cmake_minimum_required(VERSION 3.13)
project(SD_project)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCES
    src/algorithms/bfs.cpp
    src/algorithms/dijkstra.cpp
    src/algorithms/bellmanFord.cpp
    src/algorithms/aStar.cpp
    src/algorithms/floydWarshall.cpp
    src/algorithms/johnson.cpp
)

add_executable(SD_project ${SOURCES})

# enable_testing()
