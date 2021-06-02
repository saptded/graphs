#include "listGraph.hpp"
#include <algorithm>
#include <cassert>

ListGraph::ListGraph(int count)
    : vertexCount(count) {
    adjacencyLists.resize(count);
}

ListGraph::ListGraph(const IGraph &graph)
    : ListGraph(graph.VerticesCount()) {
    for (int i = 0; i < vertexCount; ++i) {
        for (int vertices : graph.GetNextVertices(i)) {
            adjacencyLists[i].push_back(vertices);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    assert(isValidIndex(from));
    assert(isValidIndex(to));

    adjacencyLists[from].push_back(to);
}

int ListGraph::VerticesCount() const { return vertexCount; }

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(isValidIndex(vertex));

    std::vector<int> tmp;
    tmp.resize(adjacencyLists[vertex].size());
    std::copy(adjacencyLists[vertex].begin(), adjacencyLists[vertex].end(), tmp.begin());
    return tmp;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(isValidIndex(vertex));

    std::vector<int> tmp;
    for (int i = 0; i < adjacencyLists.size(); i++) {
       for (auto &j : adjacencyLists[i]) {
           if (j == vertex) {
               tmp.push_back(i);
           }
       }
    }
    return tmp;
}

bool ListGraph::isValidIndex(int index) const { return 0 <= index && index < adjacencyLists.size(); }
