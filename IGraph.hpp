#ifndef IGRAPH_IGRAPH_HPP
#define IGRAPH_IGRAPH_HPP

struct IGraph {
    virtual ~IGraph() {
    }

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;

    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};


#endif //IGRAPH_IGRAPH_HPP
