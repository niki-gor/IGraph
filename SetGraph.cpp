#include "SetGraph.hpp"

SetGraph::~SetGraph() {
}

SetGraph::SetGraph(int n) : n{n}, e(n) {
}

void SetGraph::AddEdge(int from, int to) {
    e[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return n;
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    std::ranges::copy(e[vertex], std::back_inserter(result));
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    std::ranges::copy_if(std::views::iota(0, n), std::back_inserter(result), [&](int i) {
        return e[i].contains(vertex);
    });
    return result;
}
