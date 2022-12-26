#ifndef IGRAPH_MATRIXGRAPH_HPP
#define IGRAPH_MATRIXGRAPH_HPP


#include <vector>
#include <ranges>
#include <algorithm>
#include "IGraph.hpp"

class MatrixGraph : public IGraph {
    int n;
    std::vector<std::vector<bool>> e;
public:
    ~MatrixGraph() override;

    MatrixGraph(int n);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;
};


#endif //IGRAPH_MATRIXGRAPH_HPP
