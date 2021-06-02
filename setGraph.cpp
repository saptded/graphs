#include <cassert>

#include "setGraph.hpp"

SetGraph::SetGraph(int count)
    : vertexCount(count) {
    graphSet.resize(vertexCount);
}

SetGraph::SetGraph(const IGraph &graph)
    : SetGraph(graph.VerticesCount()) {
    for (int i = 0; i < vertexCount; ++i) {
        for (auto &j : graph.GetNextVertices(i)) {
            graphSet[i].insert(j);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(isValidIndex(from));
    assert(isValidIndex(to));

    graphSet[from].insert(to);
}

int SetGraph::VerticesCount() const { return vertexCount; }

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> tmp;
    tmp.resize(graphSet[vertex].size());
    std::copy(graphSet[vertex].begin(), graphSet[vertex].end(), tmp.begin());
    return tmp;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> tmp;

    for (int i = 0; i < graphSet.size(); ++i) {
        for (auto &j : graphSet[i]) {
            if (j == vertex) {
                tmp.push_back(i);
            }
        }
    }

    return tmp;
}

bool SetGraph::isValidIndex(int index) const { return 0 <= index && index < graphSet.size(); }