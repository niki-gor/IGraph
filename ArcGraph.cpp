//
// Created by niki-gor on 12/26/22.
//

#include "ArcGraph.hpp"

ArcGraph::~ArcGraph() {
}

ArcGraph::ArcGraph(int n) : n{n} {
}

void ArcGraph::AddEdge(int from, int to) {
    e.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return n;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    std::ranges::copy(e | std::views::filter([&](auto const& edge) { return edge.first == vertex; })
                        | std::views::values, std::back_inserter(result));
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    std::ranges::copy(e | std::views::filter([&](auto const& edge) { return edge.second == vertex; })
                        | std::views::keys, std::back_inserter(result));
    return result;
}
