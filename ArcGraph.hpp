//
// Created by niki-gor on 12/26/22.
//

#ifndef IGRAPH_ARCGRAPH_HPP
#define IGRAPH_ARCGRAPH_HPP


#include <vector>
#include <ranges>
#include <algorithm>
#include "IGraph.hpp"

class ArcGraph : public IGraph {
    int n;
    std::vector<std::pair<int, int>> e;
public:
    ~ArcGraph() override;

    ArcGraph(int n);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;
};


#endif //IGRAPH_ARCGRAPH_HPP
