//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_BFS_H
#define ALGORITHMS_BFS_H

#include <vector>
#include <queue>
#include <iostream>

// BFS from source vertex s using adjacency list
// Returns visited order
std::vector<int> bfs(const std::vector<std::vector<int>>& adj, int s) {
    int n = adj.size();
    std::vector<bool> visited(n, false);
    std::vector<int> order;
    std::queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return order;
}

void demoBFS() {
    int n = 6, m = 7;
    std::vector<std::vector<int>> adj(n);
    // Example graph edges (undirected)
    // 0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5
    std::vector<std::pair<int,int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,4},{3,5},{4,5}};
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> order = bfs(adj, 0);
    std::cout << "BFS from 0: ";
    for (int v : order) std::cout << v << " ";
    std::cout << std::endl;
}

#endif //ALGORITHMS_BFS_H
