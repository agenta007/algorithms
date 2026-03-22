//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_KRUSKAL_H
#define ALGORITHMS_KRUSKAL_H

#include <vector>
#include <algorithm>
#include <iostream>

struct Edge {
    int u, v, w;
    bool operator<(const Edge& o) const { return w < o.w; }
};

struct DSU {
    std::vector<int> parent, rank_;
    DSU(int n) : parent(n), rank_(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank_[a] < rank_[b]) std::swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b]) ++rank_[a];
        return true;
    }
};

// Kruskal's MST
// edges: list of {u, v, weight}
// Returns MST edges and total weight
std::vector<Edge> kruskal(int n, std::vector<Edge> edges) {
    std::sort(edges.begin(), edges.end());
    DSU dsu(n);
    std::vector<Edge> mst;
    for (Edge& e : edges) {
        if (dsu.unite(e.u, e.v))
            mst.push_back(e);
    }
    return mst;
}

void demoKruskal() {
    int n = 5;
    std::vector<Edge> edges = {
        {0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}
    };
    std::vector<Edge> mst = kruskal(n, edges);
    int total = 0;
    std::cout << "Kruskal MST edges: ";
    for (Edge& e : mst) {
        std::cout << e.u << "-" << e.v << "(" << e.w << ") ";
        total += e.w;
    }
    std::cout << "\nTotal weight: " << total << std::endl;
}

#endif //ALGORITHMS_KRUSKAL_H
