
//
// Created by neo on 3/17/26.
//

#ifndef ALGORITHMS_ADJANCENCY_LIST_H
#define ALGORITHMS_ADJANCENCY_LIST_H

#include <vector>
#include <iostream>

void readAdjacencyList(std::vector<std::vector<int>>& adj_list, int n, int m) {
    // n = number of vertices, m = number of edges
    adj_list.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);  // remove for directed graph
    }
}

#endif //ALGORITHMS_ADJANCENCY_LIST_H