//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_DFS_H
#define ALGORITHMS_DFS_H

#include <vector>
#include <iostream>

static void dfsHelper(const std::vector<std::vector<int>>& adj, int u, std::vector<bool>& visited, std::vector<int>& order) {
    visited[u] = true;
    order.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v])
            dfsHelper(adj, v, visited, order);
    }
}

// DFS from source vertex s using adjacency list
// Returns visited order
std::vector<int> dfs(const std::vector<std::vector<int>>& adj, int s) {
    int n = adj.size();
    std::vector<bool> visited(n, false);
    std::vector<int> order;
    dfsHelper(adj, s, visited, order);
    return order;
}

void demoDFS() {
    int n = 6;
    std::vector<std::vector<int>> adj(n);
    std::vector<std::pair<int,int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,4},{3,5},{4,5}};
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> order = dfs(adj, 0);
    std::cout << "DFS from 0: ";
    for (int v : order) std::cout << v << " ";
    std::cout << std::endl;
}

#endif //ALGORITHMS_DFS_H
