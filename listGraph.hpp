#pragma once

#include <list>
#include <vector>

#include "iGraph.hpp"

class ListGraph : public IGraph {
public:
    explicit ListGraph(int count);
    explicit ListGraph(const IGraph &graph);
    ~ListGraph() override = default;

    void AddEdge(int from, int to) override;

    [[nodiscard]] int VerticesCount() const override;

    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int vertexCount;
    std::vector<std::list<int>> adjacencyLists;

    [[nodiscard]] bool isValidIndex(int index) const;
};