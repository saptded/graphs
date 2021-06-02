#pragma once

#include <set>

#include "iGraph.hpp"

class SetGraph : public IGraph {
public:
    explicit SetGraph(int count);
    explicit SetGraph(const IGraph &graph);
    ~SetGraph() override = default;

    void AddEdge(int from, int to) override;

    [[nodiscard]] int VerticesCount() const override;

    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int vertexCount;
    std::vector<std::set<int>> graphSet;

    [[nodiscard]] bool isValidIndex(int index) const;
};
