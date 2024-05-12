/*
efiphi10@gmail.com
318591823
*/

#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace std;

TEST_CASE("isConnected - Connected and Non-connected Graphs") {
    ariel::Graph g;
    std::vector<std::vector<int>> connected = {
        {0, 1},
        {1, 0}
    };
    g.loadGraph(connected);
    CHECK(ariel::Algorithms::isConnected(g) == 1);

    std::vector<std::vector<int>> not_connected = {
        {0, 0},
        {0, 0}
    };
    g.loadGraph(not_connected);
    CHECK(ariel::Algorithms::isConnected(g) == 0);
}


TEST_CASE("Testing shortest paths and their string representations") {
    ariel::Graph g;
    std::vector<std::vector<int>> matrix = {
        {0, 1, 100},
        {1, 0, 1},
        {100, 1, 0}
    };
    g.loadGraph(matrix);

    auto path = ariel::Algorithms::shortestPath(g, 0, 2);
    CHECK(path != nullptr);
    std::string pathStr = ariel::Algorithms::shortestPathToString(path);
    CHECK(pathStr == "0->1->2");
    delete path;  // Remember to delete dynamically allocated memory

    path = ariel::Algorithms::shortestPath(g, 0, 1);
    CHECK(path != nullptr);
    pathStr = ariel::Algorithms::shortestPathToString(path);
    CHECK(pathStr == "0->1");
    delete path;

    
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    // Directed graph without cycles.
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "No cycle found");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    // Directed graph with cycles.
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "0->1->2->0");

    vector<vector<int>> graph3 = {{0, 1, 0, 1, 1}, 
                                  {1, 0, 1, 0, 0}, 
                                  {0, 1, 0, 1, 0}, 
                                  {1, 0, 1, 0, 0}, 
                                  {1, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "0->1->2->3->0");
    

    vector<vector<int>> graph4 = {{0}};
    g.loadGraph(graph4);
    // Graph with one vertex no edges.
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "No cycle found");
  
    vector<vector<int>> graph5 = {{1}};
    g.loadGraph(graph5);
    // Graph with one vertex cyclic edge.
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "0->0");
}
TEST_CASE("Testing graph bipartiteness and its string representation") {
    ariel::Graph g;
    std::vector<std::vector<int>> bipartite = {
        {0, 1},
        {1, 0}
    };
    g.loadGraph(bipartite);
    auto sets = ariel::Algorithms::isBipartite(g);
    CHECK(sets.size() == 2);
    std::string bipartiteStr = ariel::Algorithms::bipartiteGraphToString(sets);
    CHECK(bipartiteStr == "{ 0 } { 1 }");

    std::vector<std::vector<int>> not_bipartite = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g.loadGraph(not_bipartite);
    sets = ariel::Algorithms::isBipartite(g);
    CHECK(sets.empty() == true);
}

TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;

    SUBCASE("Single Vertex with No Edges") {
        std::vector<std::vector<int>> graph = {{0}};
        g.loadGraph(graph);
        std::ostringstream redirectedOutput;
        std::streambuf* oldStdout = std::cout.rdbuf(redirectedOutput.rdbuf());
        ariel::Algorithms::negativeCycle(g);
        std::cout.rdbuf(oldStdout);
        CHECK(ariel::Algorithms::trim(redirectedOutput.str()) == "No negative cycle detected!\n");
    }

    SUBCASE("Single Vertex with a Negative Self-Loop") {
        std::vector<std::vector<int>> graph1 = {{-1}};
        g.loadGraph(graph1);
        std::ostringstream redirectedOutput;
        std::streambuf* oldStdout = std::cout.rdbuf(redirectedOutput.rdbuf());
        ariel::Algorithms::negativeCycle(g);
        std::cout.rdbuf(oldStdout);
        CHECK(ariel::Algorithms::trim(redirectedOutput.str()) == "Negative cycle detected!\n");
    }

    SUBCASE("Complex Graph with Negative and Positive Cycles") {
        g.loadGraph({{0, 1, -1, -1}, {1, 0, 0, 2}, {-1, 0, 0, -4}, {-1, 2, -4, 0}});
        std::ostringstream redirectedOutput;
        std::streambuf* oldStdout = std::cout.rdbuf(redirectedOutput.rdbuf());
        ariel::Algorithms::negativeCycle(g);
        std::cout.rdbuf(oldStdout);
        CHECK(ariel::Algorithms::trim(redirectedOutput.str()) == "Negative cycle detected!\n");
    }

    SUBCASE("Undirected Graph with Negative Edges But No Cycle") {
        g.loadGraph({{0, -1, 0}, {-1, 0, -1}, {0, -1, 0}});
        std::ostringstream redirectedOutput;
        std::streambuf* oldStdout = std::cout.rdbuf(redirectedOutput.rdbuf());
        ariel::Algorithms::negativeCycle(g);
        std::cout.rdbuf(oldStdout);
        CHECK(redirectedOutput.str() == "No negative cycle detected!\n");
    }

    SUBCASE("Graph with No Negative Cycles") {
        g.loadGraph({{0, 4, 5}, {4, 0, 6}, {5, 6, 0}});
        std::ostringstream redirectedOutput;
        std::streambuf* oldStdout = std::cout.rdbuf(redirectedOutput.rdbuf());
        ariel::Algorithms::negativeCycle(g);
        std::cout.rdbuf(oldStdout);
        CHECK(ariel::Algorithms::trim(redirectedOutput.str()) == "No negative cycle detected!\n");
    }
}



TEST_CASE("Invalid Graph - Non-square Matrix") {
    ariel::Graph g;
    std::vector<std::vector<int>> non_square_matrix = {
        {0, 1},
        {1, 0, 1}
    };
    CHECK_THROWS(g.loadGraph(non_square_matrix));
}
