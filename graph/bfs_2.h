//
// Created by neo on 3/23/26.
//

#ifndef ALGORITHMS_BFS_2_H
#define ALGORITHMS_BFS_2_H
#include <format>
#include <queue>
#include <vector>
#include <string>
using namespace std;
string bfs_traverse_a_graph(vector<vector<int>>& adj_list, int src_node) {
    vector<bool> visited(adj_list.size(), false);
    queue<int> q;
    q.push(src_node);
    string graph_str = "";
    while (!q.empty()) {
        if (!visited[q.front()]) {
            int u = q.front();
            q.pop();
            for (int v : adj_list[u]) {
                q.push(v);
            }
            visited[u] = true;
            graph_str += std::to_string(u);
            graph_str += ", ";
        }
        else {
            q.pop();
        }
    }
    return graph_str;
}
#endif //ALGORITHMS_BFS_2_H