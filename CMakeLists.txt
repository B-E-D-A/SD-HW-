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
    add_executable(BFS tests/testBfs.cpp)
#    add_executable(Dijkstra tests/testDijkstra.cpp)
#    add_executable(BellmanFord tests/testBellmanFord.cpp)
#    add_executable(AStar tests/testAStar.cpp)
#    add_executable(FloydWarshall tests/testFloydWarshall.cpp)
#    add_executable(Johnson tests/testJohnson.cpp)

    target_link_libraries(BFS PRIVATE GraphAlgorithms)
#    target_link_libraries(Dijkstra PRIVATE GraphAlgorithms)
#    target_link_libraries(BellmanFord PRIVATE GraphAlgorithms)
#    target_link_libraries(AStar PRIVATE GraphAlgorithms)
#    target_link_libraries(FloydWarshall PRIVATE GraphAlgorithms)
#    target_link_libraries(Johnson PRIVATE GraphAlgorithms)

    add_test(NAME BFS COMMAND BFS)
#    add_test(NAME Dijkstra COMMAND Dijkstra)
#    add_test(NAME BellmanFord COMMAND BellmanFord)
#    add_test(NAME AStar COMMAND AStar)
#    add_test(NAME FloydWarshall COMMAND FloydWarshall)
#    add_test(NAME Johnson COMMAND Johnson)

endif()