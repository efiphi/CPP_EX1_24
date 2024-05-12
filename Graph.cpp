/*
efiphi10@gmail.com
318591823
*/

#include "Graph.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

namespace ariel {

    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        adjacencyMatrix = matrix;
        numVert = matrix.size();

        for(const auto& row : matrix){
            if(row.size() != numVert){
                throw std::invalid_argument("The graph must be a square matrix");
            }
        }

        if(isSymmetric(matrix)){
            isDirected = true;
        }else {
            isDirected = false;
        }
        this->adjacencyMatrix = matrix;
    }

    void Graph::printGraph() const {
    int edgeCount = 0;
    for (size_t i = 0; i < adjacencyMatrix.size(); i++) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); j++) {
            if (adjacencyMatrix[i][j] != 0) {
                if (isDirected || i >= j) { // Avoid double-counting for undirected graphs
                    edgeCount++;
                }
            }
        }
    }
    std::cout << "Graph with " << numVert << " vertices and " << edgeCount << " edges.\n";
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}



    std::vector<std::vector<int>> Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }

    size_t Graph::getNumVert() const {
    return adjacencyMatrix.size();
    }

    
    bool ariel::Graph::isSymmetric(std::vector<std::vector<int>> matrix) {
        if(matrix.size() == 0){
            return true; 
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows!= cols){
            return false; // if matrix isnt square, so its not symmetric.
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < i; j++) {  // Check only the upper triangular matrix excluding diagonal
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
            }
        }
    }
    return true;
}


}
