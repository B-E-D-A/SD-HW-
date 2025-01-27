cmake_minimum_required(VERSION 3.13)
project(SD_project)

set(CMAKE_CXX_STANDARD 17)

add_library(GraphAlgorithms
        src/algorithms/bfs.cpp
        src/algorithms/dijkstra.cpp
        src/algorithms/bellmanFord.cpp
        src/algorithms/aStar.cpp
        src/algorithms/floydWarshall.cpp
        src/algorithms/johnson.cpp)

add_executable(performanceRunner
        tests/performanceRunner.cpp)

target_include_directories(GraphAlgorithms PUBLIC include)
target_link_libraries(performanceRunner PRIVATE GraphAlgorithms)

option(ENABLE_TESTING "Enable testing" ON)
if (ENABLE_TESTING)
    enable_testing()
    add_executable(test_runner
            tests/testBfs.cpp
            tests/testDijkstra.cpp
            tests/testBellmanFord.cpp
            tests/testAStar.cpp
            tests/testFloydWarshall.cpp
            tests/testJohnson.cpp)
    target_link_libraries(test_runner PRIVATE GraphAlgorithms)
    add_test(NAME AlgorithmsTest COMMAND test_runner)
endif()