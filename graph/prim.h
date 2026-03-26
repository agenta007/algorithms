//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_PRIM_H
#define ALGORITHMS_PRIM_H

#include <vector>
#include <queue>
#include <limits>
#include <iostream>

// Prim's MST from source s
// adj[u] = list of {v, weight}
// Returns total MST weight and parent[] array
//undirected, connected, weighted graph
std::pair<int, std::vector<int>> prim(const std::vector<std::vector<std::pair<int,int>>>& adj, int s) {
    int n = adj.size();
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> key(n, INF), parent(n, -1);
    std::vector<bool> inMST(n, false);
    // min-heap: {key, vertex}
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>,
                        std::greater<std::pair<int,int>>> pq;

    key[s] = 0;
    pq.push({0, s});

    int total = 0;
    while (!pq.empty()) {
        auto [k, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        total += k;

        for (auto [v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    return {total, parent};
}

void demoPrim() {
    int n = 5;
    std::vector<std::vector<std::pair<int,int>>> adj(n);
    std::vector<std::tuple<int,int,int>> edges = {
        {0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}
    };
    for (auto [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto [total, parent] = prim(adj, 0);
    std::cout << "Prim MST edges: ";
    for (int v = 1; v < n; ++v)
        std::cout << parent[v] << "-" << v << " ";
    std::cout << "\nTotal weight: " << total << std::endl;
}

#endif //ALGORITHMS_PRIM_H
