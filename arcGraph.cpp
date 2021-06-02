#include "arcGraph.hpp"
#include <cassert>

ArcGraph::ArcGraph(int n)
    : vertexCount(n) {}

ArcGraph::ArcGraph(const IGraph &graph)
    : vertexCount(graph.VerticesCount()) {
    for (int i = 0; i < vertexCount; ++i) {
        for (auto &j : graph.GetNextVertices(i)) {
            arcsArray.emplace_back(i, j);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    assert(isValidIndex(from));
    assert(isValidIndex(to));

    arcsArray.emplace_back(std::pair<int, int>(from, to));
}

int ArcGraph::VerticesCount() const { return vertexCount; }

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(isValidIndex(vertex));

    std::vector<int> tmp;
    for (const auto &i : arcsArray) {
        if (i.first == vertex) {
            tmp.push_back(i.second);
        }
    }
    return tmp;
}
std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(isValidIndex(vertex));

    std::vector<int> tmp;
    for (const auto &i : arcsArray) {
        if (i.second == vertex) {
            tmp.push_back(i.first);
        }
    }
    return tmp;
}

bool ArcGraph::isValidIndex(int index) const { return 0 <= index && index < vertexCount; }
