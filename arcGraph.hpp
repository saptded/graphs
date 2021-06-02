#pragma once

#include "iGraph.hpp"

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int n);
    explicit ArcGraph(const IGraph &other);
    ~ArcGraph() override = default;

    void AddEdge(int from, int to) override;

    [[nodiscard]] int VerticesCount() const override;

    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int vertexCount;
    std::vector<std::pair<int, int>> arcsArray;

    [[nodiscard]] bool isValidIndex(int index) const;
};
