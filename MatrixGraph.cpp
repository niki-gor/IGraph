#include "MatrixGraph.hpp"

MatrixGraph::~MatrixGraph() {
}

MatrixGraph::MatrixGraph(int n) : n{n}, e(n, std::vector<bool>(n, false)) {
}

void MatrixGraph::AddEdge(int from, int to) {
    e[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return n;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    std::ranges::copy_if(std::views::iota(0, n), std::back_inserter(result), [&](int i) {
        return e[vertex][i];
    });
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    std::ranges::copy_if(std::views::iota(0, n), std::back_inserter(result), [&](int i) {
        return e[i][vertex];
    });
    return result;
}
