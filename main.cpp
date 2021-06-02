#include <cassert>
#include <algorithm>
#include <iostream>

#include "arcGraph.hpp"
#include "iGraph.hpp"
#include "listGraph.hpp"
#include "matrixGraph.hpp"
#include "setGraph.hpp"

void testNextVertices(const IGraph &first, const IGraph &second) {
    assert(first.VerticesCount() == second.VerticesCount());
    for (int i = 0; i < first.VerticesCount(); ++i) {
        auto tmp1 = first.GetNextVertices(i);
        auto tmp2 = second.GetNextVertices(i);
        for (int j = 0; j < tmp1.size(); ++j) {
            auto res = std::find(tmp1.begin(), tmp1.end(), tmp2[j]);
            if (res == std::end(tmp1)) {
                assert(false);
            }
        }
    }
}

void testPrevVertices(const IGraph &first, const IGraph &second) {
    assert(first.VerticesCount() == second.VerticesCount());
    for (int i = 0; i < first.VerticesCount(); ++i) {
        auto tmp1 = first.GetNextVertices(i);
        auto tmp2 = second.GetNextVertices(i);
        for (int j = 0; j < tmp1.size(); ++j) {
            auto res = std::find(tmp1.begin(), tmp1.end(), tmp2[j]);
            if (res == std::end(tmp1)) {
                assert(false);
            }
        }
    }
}

void printGraph(const IGraph& graph) {
    for( int i = 0; i < graph.VerticesCount(); ++i){
        for (int v : graph.GetNextVertices(i)) {
            std::cout << v << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    ListGraph listGraph(7);

    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(2, 2);
    listGraph.AddEdge(3, 3);
    listGraph.AddEdge(4, 4);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 1);
    listGraph.AddEdge(1, 2);

    std::cout << "LIST GRAPH" << std::endl;
    printGraph(listGraph);

    std::cout << "MATRIX GRAPH" << std::endl;
    MatrixGraph matrixGraph(listGraph);
    testNextVertices(listGraph, matrixGraph);
    testPrevVertices(listGraph, matrixGraph);
    printGraph(matrixGraph);

    std::cout << "SET GRAPH" << std::endl;
    SetGraph setGraph(listGraph);
    testNextVertices(listGraph, setGraph);
    testPrevVertices(listGraph, setGraph);
    printGraph(setGraph);

    std::cout << "ARC GRAPH" << std::endl;
    ArcGraph arcGraph(listGraph);
    testNextVertices(listGraph, arcGraph);
    testPrevVertices(listGraph, arcGraph);
    printGraph(arcGraph);

    return 0;
}