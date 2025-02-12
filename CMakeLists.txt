cmake_minimum_required(VERSION 3.13)
project(GraphAlgorithmsLibrary)

set(CMAKE_CXX_STANDARD 17)

add_library(GraphAlgorithmsLibrary STATIC
        src/algorithms/bfs.cpp
        src/algorithms/dijkstra.cpp
        src/algorithms/bellmanFord.cpp
        src/algorithms/aStar.cpp
        src/algorithms/floydWarshall.cpp
        src/algorithms/johnson.cpp
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
endif()

add_executable(performanceRunner tests/performanceRunner.cpp)
target_link_libraries(performanceRunner PRIVATE GraphAlgorithmsLibrary)
