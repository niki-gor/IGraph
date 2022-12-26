//
// Created by niki-gor on 12/26/22.
//

#ifndef IGRAPH_SETGRAPH_HPP
#define IGRAPH_SETGRAPH_HPP


#include <vector>
#include <set>
#include <ranges>
#include <algorithm>
#include "IGraph.hpp"

class SetGraph : public IGraph {
    int n;
    std::vector<std::set<int>> e;
public:
    ~SetGraph() override;

    SetGraph(int n);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;
};


#endif //IGRAPH_SETGRAPH_HPP
