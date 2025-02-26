cmake_minimum_required(VERSION 3.13)
project(GraphAlgorithmsLibrary)

set(CMAKE_CXX_STANDARD 17)

set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
add_subdirectory(algo-benchmarking/benchmark)

add_library(GraphAlgorithmsLibrary STATIC
        src/algorithms/bfs.cpp
        src/algorithms/dijkstra.cpp
        src/algorithms/bellmanFord.cpp
        src/algorithms/aStar.cpp
        src/algorithms/floydWarshall.cpp
        src/algorithms/bruteForce.cpp
        src/algorithms/oneKBfs.cpp
        )

target_include_directories(GraphAlgorithmsLibrary PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)


install(TARGETS GraphAlgorithmsLibrary
        EXPORT GraphAlgorithmsLibraryTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        )

install(DIRECTORY include/ DESTINATION include)

install(EXPORT GraphAlgorithmsLibraryTargets
        FILE GraphAlgorithmsLibraryConfig.cmake
        DESTINATION lib/cmake/GraphAlgorithmsLibrary
        )

option(ENABLE_TESTING "Enable testing" ON)
if (ENABLE_TESTING)
    enable_testing()
    add_executable(BFS tests/testBfs.cpp)
    target_link_libraries(BFS PRIVATE GraphAlgorithmsLibrary)
    add_test(NAME BFS COMMAND BFS)

    add_executable(DIJKSTRA tests/testDijkstra.cpp)
    target_link_libraries(DIJKSTRA PRIVATE GraphAlgorithmsLibrary)
    add_test(NAME DIJKSTRA COMMAND DIJKSTRA)

    add_executable(BELLMAN-FORD tests/testBellmanFord.cpp)
    target_link_libraries(BELLMAN-FORD PRIVATE GraphAlgorithmsLibrary)
    add_test(NAME BELLMAN-FORD COMMAND BELLMAN-FORD)

    add_executable(BRUTE-FORCE tests/testBruteForce.cpp)
    target_link_libraries(BRUTE-FORCE PRIVATE GraphAlgorithmsLibrary)
    add_test(NAME BRUTE-FORCE COMMAND BRUTE-FORCE)

    add_executable(ONE_K_BFS tests/testOneKBfs.cpp)
    target_link_libraries(ONE_K_BFS PRIVATE GraphAlgorithmsLibrary)
    add_test(NAME ONE_K_BFS COMMAND ONE_K_BFS)
endif()

add_executable(environment environment/environment.cpp)
target_link_libraries(environment PRIVATE GraphAlgorithmsLibrary benchmark::benchmark)
