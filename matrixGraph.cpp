#include "matrixGraph.hpp"
#include <cassert>

MatrixGraph::MatrixGraph(int count)
    : vertexCount(count) {
    adjacencyMatrix.resize(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        adjacencyMatrix[i].resize(vertexCount, false);
    }
}

MatrixGraph::MatrixGraph(const IGraph &graph)
    : MatrixGraph(graph.VerticesCount()) {
    for (int i = 0; i < vertexCount; ++i) {
        for (auto vertex : graph.GetNextVertices(i)) {
            adjacencyMatrix[i][vertex] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(isValidIndex(from));
    assert(isValidIndex(to));

    adjacencyMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const { return vertexCount; }

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(isValidIndex(vertex));

    std::vector<int> tmp;
    for (int i = 0; i < adjacencyMatrix[vertex].size(); ++i) {
        if (adjacencyMatrix[vertex][i]) {
            tmp.push_back(i);
        }
    }
    return tmp;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(isValidIndex(vertex));

    std::vector<int> tmp;
    for (int i = 0; i < adjacencyMatrix[vertex].size(); ++i) {
        if (adjacencyMatrix[i][vertex]) {
            tmp.push_back(i);
        }
    }
    return tmp;
}

bool MatrixGraph::isValidIndex(int index) const { return 0 <= index && index < vertexCount; }
