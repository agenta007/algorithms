//
// Created by neo on 3/23/26.
//

#ifndef ALGORITHMS_TOPOLOGICAL_SORT_H
#define ALGORITHMS_TOPOLOGICAL_SORT_H

#include <vector>
#include <stack>
#include <queue>
#include <iostream>

// --- DFS-based topological sort ---
// Works on a DAG (directed acyclic graph)
// Push to stack after all descendants are visited; reverse gives topo order

static void topoHelper(const std::vector<std::vector<int>>& adj, int u,
                       std::vector<bool>& visited, std::stack<int>& stk) {
    //mark current node as visited
    visited[u] = true;
    //for every adjacent node
    for (int v : adj[u])
        //if node not visited, call topohelper
        if (!visited[v])
            topoHelper(adj, v, visited, stk);
    //after iterating all adjacent nodes, push node to stack
    stk.push(u);
}

std::vector<int> topologicalSortDFS(const std::vector<std::vector<int>>& adj) {
    int n = adj.size();
    std::vector<bool> visited(n, false);
    std::stack<int> stk;

    //for every node in the graph
    for (int u = 0; u < n; ++u)
        //if node is unvisited
        if (!visited[u])
            //topoHelper adjacencyList, visitedVector, stack
            topoHelper(adj, u, visited, stk);

    std::vector<int> order;
    while (!stk.empty()) { order.push_back(stk.top()); stk.pop(); }
    return order;
}

// --- Kahn's algorithm (BFS / in-degree based) ---
// Also detects cycles: if result size < n, graph has a cycle
std::vector<int> topologicalSortKahn(const std::vector<std::vector<int>>& adj) {
    int n = adj.size();
    std::vector<int> indegree(n, 0);
    for (int u = 0; u < n; ++u)
        for (int v : adj[u])
            ++indegree[v];

    std::queue<int> q;
    for (int u = 0; u < n; ++u)
        if (indegree[u] == 0) q.push(u);

    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0) q.push(v);
    }

    if ((int)order.size() != n)
        std::cout << "[topologicalSortKahn] cycle detected — not a DAG\n";

    return order;
}

void demoTopologicalSort() {
    // DAG: 1->2, 1->3, 3->2, 4->3, 4->2  (vertices 1..4, so n=5)
    int n = 5;
    std::vector<std::vector<int>> adj(n);
    for (auto [u, v] : std::vector<std::pair<int,int>>{{1,3},{1,2},{3,2},{4,3},{4,2}})
        adj[u].push_back(v);

    std::vector<int> dfs_order = topologicalSortDFS(adj);
    std::cout << "Topo sort (DFS):  ";
    for (int v : dfs_order) std::cout << v << " ";
    std::cout << "\n";

    std::vector<int> kahn_order = topologicalSortKahn(adj);
    std::cout << "Topo sort (Kahn): ";
    for (int v : kahn_order) std::cout << v << " ";
    std::cout << "\n";
}

#endif //ALGORITHMS_TOPOLOGICAL_SORT_H
