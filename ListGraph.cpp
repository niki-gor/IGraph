#include "ListGraph.hpp"

ListGraph::~ListGraph() {
}

ListGraph::ListGraph(int n) : n{n}, e(n) {
}

void ListGraph::AddEdge(int from, int to) {
    e[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return n;
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return e[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    std::ranges::copy_if(std::views::iota(0, n), std::back_inserter(result), [&](int i) {
        return std::ranges::find(e[i], vertex) != e[i].end();
    });
    return result;
}
