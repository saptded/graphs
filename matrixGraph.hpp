#pragma once

#include "iGraph.hpp"

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(int count);
    explicit MatrixGraph(const IGraph &igraph);
    ~MatrixGraph() override = default;

    void AddEdge(int from, int to) override;

    [[nodiscard]] int VerticesCount() const override;

    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int vertexCount;
    std::vector<std::vector<bool>> adjacencyMatrix;

    [[nodiscard]] bool isValidIndex(int index) const;
};
