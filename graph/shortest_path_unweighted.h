//
// Created by neo on 3/23/26.
//

#ifndef ALGORITHMS_SHORTEST_PATH_UNWEIGHTED_H
#define ALGORITHMS_SHORTEST_PATH_UNWEIGHTED_H

#include <vector>
#include <queue>
#include <iostream>

// Shortest path in unweighted graph using BFS
// Returns dist[] where dist[i] = shortest hop-count from src to i, -1 if unreachable
// Also fills parent[] for path reconstruction
std::vector<int> shortestPathUnweighted(const std::vector<std::vector<int>>& adj, int src, std::vector<int>& parent) {
    int n = adj.size();
    std::vector<int> dist(n, -1);
    parent.assign(n, -1);

    std::queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return dist;
}

// Reconstruct path from src to dst using parent[]
std::vector<int> reconstructPath(const std::vector<int>& parent, int src, int dst) {
    if (parent[dst] == -1 && dst != src) return {}; // unreachable
    std::vector<int> path;
    for (int v = dst; v != -1; v = parent[v])
        path.push_back(v);
    std::reverse(path.begin(), path.end());
    return path;
}

void demoShortestPathUnweighted() {
    int n = 4;
    std::vector<std::vector<int>> adj(n);
    for (auto [u, v] : std::vector<std::pair<int,int>>{
            //{0,1},{0,2},{1,3},{1,4},{2,5},{3,6},{4,6},{5,7},{6,7}}
                {0, 1}, {1, 2}, {0, 2}, {1, 3}, {2, 3}
            })
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> parent;
    std::vector<int> dist = shortestPathUnweighted(adj, 0, parent);

    std::cout << "Shortest distances from 0:\n";
    for (int i = 0; i < n; ++i)
        std::cout << "  0 -> " << i << ": " << dist[i] << " hops\n";

    //std::cout << "Path 0 -> 7: ";
    //for (int v : reconstructPath(parent, 0, 7))
    //    std::cout << v << " ";
    //std::cout << "\n";
}

#endif //ALGORITHMS_SHORTEST_PATH_UNWEIGHTED_H
