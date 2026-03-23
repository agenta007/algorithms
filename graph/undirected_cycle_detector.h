#ifndef ALGORITHMS_UNDIRECTED_CYCLE_DETECTOR_H
#define ALGORITHMS_UNDIRECTED_CYCLE_DETECTOR_H

#include <vector>
//if at any point we visit a node for the first time and we have and adjacent node that is already visited and not the parent,
//then the graph contains a cycle
//Visited node + visited neighbor + (neighbor ≠ parent) = cycle
bool dfsCycleHelper(const std::vector<std::vector<int>>& adj,
                    int u, int parent, std::vector<bool>& visited) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfsCycleHelper(adj, v, u, visited))
                return true;
        } else if (v != parent) {
            // visited neighbor that isn't our parent = cycle
            return true;
        }
    }
    return false;
}

bool hasCycle(const std::vector<std::vector<int>>& adj) {
    int n = adj.size();
    std::vector<bool> visited(n, false);

    // Loop handles disconnected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycleHelper(adj, i, -1, visited))
                return true;
        }
    }
    return false;
}

#endif
