//
// Created by niki-gor on 12/26/22.
//

#ifndef IGRAPH_LISTGRAPH_HPP
#define IGRAPH_LISTGRAPH_HPP

#include <vector>
#include <ranges>
#include <algorithm>
#include "IGraph.hpp"


class ListGraph : public IGraph {
    int n;
    std::vector<std::vector<int>> e;
public:
    ~ListGraph() override;

    ListGraph(int n);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;
};


#endif //IGRAPH_LISTGRAPH_HPP
