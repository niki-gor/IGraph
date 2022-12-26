#include "ListGraph.hpp"
#include "MatrixGraph.hpp"
#include "SetGraph.hpp"
#include "ArcGraph.hpp"
#include <memory>
#include <cassert>

int main() {
    const int n = 100;

    std::vector<std::shared_ptr<IGraph>> graphs;
    graphs.emplace_back(new ListGraph(n));
    graphs.emplace_back(new MatrixGraph(n));
    graphs.emplace_back(new SetGraph(n));
    graphs.emplace_back(new ArcGraph(n));

    for (auto graph : graphs) {
        assert(graph->VerticesCount() == n);
    }

    std::vector<std::pair<int, int>> e;
    for (auto i : std::views::iota(0, 100)) {
        int from = rand() % n;
        int to = rand() % n;
        if (from != to && std::find(e.begin(), e.end(), std::pair{from, to}) == e.end()) {
            e.emplace_back(from, to);
        }
    }

    for (auto [from, to] : e) {
        for (auto graph : graphs) {
            graph->AddEdge(from, to);
        }
    }

    for (auto [from, to] : e) {
        for (auto graph : graphs) {
            auto next = graph->GetNextVertices(from);
            assert(std::find(next.begin(), next.end(), to) != next.end());
            auto prev = graph->GetPrevVertices(to);
            assert(std::find(prev.begin(), prev.end(), from) != prev.end());
        }
    }

    return 0;
}