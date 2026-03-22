//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_DIJKSTRA_H
#define ALGORITHMS_DIJKSTRA_H

#include <vector>
#include <queue>
#include <limits>
#include <iostream>

const int INF = std::numeric_limits<int>::max();

// Dijkstra's shortest path from source s
// adj[u] = list of {v, weight} pairs
// Returns dist[] where dist[i] = shortest distance from s to i
std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int,int>>>& adj, int s) {
    int n = adj.size();
    std::vector<int> dist(n, INF);
    // min-heap: {dist, vertex}
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>,
                        std::greater<std::pair<int,int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // stale entry

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void demoDijkstra() {
    int n = 5;
    std::vector<std::vector<std::pair<int,int>>> adj(n);
    // edges: u, v, weight
    std::vector<std::tuple<int,int,int>> edges = {
        {0,1,4},{0,2,1},{2,1,2},{1,3,1},{2,3,5},{3,4,3}
    };
    for (auto [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    std::vector<int> dist = dijkstra(adj, 0);
    std::cout << "Dijkstra from 0: ";
    for (int i = 0; i < n; ++i)
        std::cout << "d[" << i << "]=" << dist[i] << " ";
    std::cout << std::endl;
}

#endif //ALGORITHMS_DIJKSTRA_H
