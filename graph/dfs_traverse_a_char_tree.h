//
// Created by neo on 3/29/26.
//

#ifndef ALGORITHMS_DFS_TRAVERSE_A_CHAR_TREE_H
#define ALGORITHMS_DFS_TRAVERSE_A_CHAR_TREE_H
#include <vector>
using namespace std;

void dfsHelper(vector<vector<int>> &order, vector<bool> &visited,  vector<char> &order, int currentNode) {
    visited[currentNode] = true;
    //maybe set colour too here

}

vector<char> DFStraversTree(vector<vector<int>> &adj_list, int startVertex) {
    vector<char> order;
    vector<bool> visited;
    for (auto adjacentVertex : adj_list[startVertex]) {
        if (!visited[adjacentVertex]) {
            dfsHelper(adj_list, visited, order, startVertex);
        }
    }
}

void demoDFStraverseTree(){
    vector<pair<char, char>> edges = {
        {'A', 'B'},
        {'A', 'C'},
        {'B', 'D'},
        {'B', 'E'},
        {'E', 'H'},
        {'C', 'F'},
        {'C', 'G'},
    };
    vector<vector<int>> adj_list;
    for (int i = 0; i < edges.size(); i++) {
        adj_list[edges[i].first].push_back(edges[i].second);
        adj_list[edges[i].second].push_back(edges[i].first);
    }
    DFStraversTree(adj_list, 'A');
}
#endif //ALGORITHMS_DFS_TRAVERSE_A_CHAR_TREE_H