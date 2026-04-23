//
// Created by neo on 3/29/26.
//

#ifndef ALGORITHMS_DFS_CHECK_IF_GRAPH_IS_BIPARTITE_H
#define ALGORITHMS_DFS_CHECK_IF_GRAPH_IS_BIPARTITE_H
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
struct Edge {
    int start;
    int end;
};

struct Vertex {
    int vertex;
    bool visited;
    string color;
    vector<int> adj_list;
};

bool colorSwitch = false;

bool checkIfGraphIsBipartiteDFS(int vertex, const vector<int> &adj_list, vector<Vertex> &vertices) {
    if (vertices[vertex].visited == false) {
        vertices[vertex].visited = true;
        vertices[vertex].color = "";
    }
}

void demoCheckIfGraphIsBipartite() {
    int n = 9;
    std::vector<Edge> edges = {
        {1,2},{2,3},{3, 4},{4,6},{5,7},{5,9},{8,9}
    };
    //adj list is a vector of vectors of ints, index is vertex, and values are adjacent nodes
    const vector<vector<int>> adj_list = vector<vector<int>>(9, vector<int>());
    for (auto edge : edges) {
        adj_list[edge.start].push_back({edge.end});
        adj_list[edge.end].push_back(edge.start);
    }
    vector<Vertex> vertices;
    cout << checkIfGraphIsBipartiteDFS(0, adj_list, vertices);
}

#endif //ALGORITHMS_DFS_CHECK_IF_GRAPH_IS_BIPARTITE_H