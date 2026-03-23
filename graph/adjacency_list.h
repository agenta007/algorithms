//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_ADJACENCY_LIST_H
#define ALGORITHMS_ADJACENCY_LIST_H

#include <vector>
#include <stdexcept>
#include <iostream>

struct AdjList {
    int V;
    bool directed;
    std::vector<int>* adj; // array of vectors

    AdjList(int vertices, bool directed = false)
        : V(vertices), directed(directed), adj(new std::vector<int>[vertices]) {}

    ~AdjList() { delete[] adj; }

    // Disable copy, allow move
    AdjList(const AdjList&) = delete;
    AdjList& operator=(const AdjList&) = delete;

    AdjList(AdjList&& o) noexcept : V(o.V), directed(o.directed), adj(o.adj) {
        o.adj = nullptr;
    }

    void addEdge(int u, int v) {
        if (u < 0 || u >= V || v < 0 || v >= V)
            throw std::out_of_range("vertex out of range");
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u);
    }

    void removeEdge(int u, int v) {
        auto& lu = adj[u];
        lu.erase(std::remove(lu.begin(), lu.end(), v), lu.end());
        if (!directed) {
            auto& lv = adj[v];
            lv.erase(std::remove(lv.begin(), lv.end(), u), lv.end());
        }
    }

    bool hasEdge(int u, int v) const {
        for (int w : adj[u]) if (w == v) return true;
        return false;
    }

    const std::vector<int>& neighbors(int u) const { return adj[u]; }

    void print() const {
        for (int u = 0; u < V; ++u) {
            std::cout << u << ": ";
            for (int v : adj[u]) std::cout << v << " ";
            std::cout << "\n";
        }
    }

    // Read from stdin: m edges, each line "u v"
    void read(int m) {
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            addEdge(u, v);
        }
    }
};

void demoAdjList() {
    AdjList g(6, false);
    for (auto [u, v] : std::vector<std::pair<int,int>>{{0,1},{0,2},{1,3},{1,4},{2,4},{3,5},{4,5}})
        g.addEdge(u, v);

    std::cout << "Adjacency list (undirected):\n";
    g.print();

    std::cout << "Neighbors of 1: ";
    for (int v : g.neighbors(1)) std::cout << v << " ";
    std::cout << "\n";

    std::cout << "Edge 1-3: " << (g.hasEdge(1,3) ? "yes" : "no") << "\n";
    g.removeEdge(1, 3);
    std::cout << "After remove 1-3, edge 1-3: " << (g.hasEdge(1,3) ? "yes" : "no") << "\n";
}

#endif //ALGORITHMS_ADJACENCY_LIST_H
