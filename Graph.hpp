/*
efiphi10@gmail.com
318591823
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

using namespace std;

namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
        bool isDirected;
        size_t numVert;

    public:
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        std::vector<std::vector<int>> getAdjacencyMatrix() const;
        bool getIsDirected() {return isDirected;}
        size_t getNumVert() const;
        bool isSymmetric(std::vector<std::vector<int>> matrix);
    };
}

#endif // GRAPH_HPP
