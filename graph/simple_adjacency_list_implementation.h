//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_SIMPLE_ADJACENCY_LIST_IMPLEMENTATION_H
#define ALGORITHMS_SIMPLE_ADJACENCY_LIST_IMPLEMENTATION_H
#include <iostream>
#include <vector>
#include <algorithm>

void pushToAdjacencyList(std::vector<std::vector<int> > &adj_list, int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void createAdjList(std::vector<std::vector<int>> &adj_list, int vertices) {
    cout << "Now creating an adjacency list of " << vertices << " vertices (Undirected graph)" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "Enter number of adjacent nodes for vertex " << i << ": ";
        int num_adjacent;
        std::cin >> num_adjacent;

        cout << "Enter " << num_adjacent << " adjacent nodes for vertex " << i << ": ";
        for (int j = 0; j < num_adjacent; j++) {
            int v;
            std::cin >> v;
            pushToAdjacencyList(adj_list, i, v);
        }
    }
}

void printAdjList(const std::vector<std::vector<int> > &adj_list) {
    for (size_t i = 0; i < adj_list.size(); i++) {
        std::cout << i << ": ";
        for (int neighbor: adj_list[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }
}
#endif //ALGORITHMS_SIMPLE_ADJACENCY_LIST_IMPLEMENTATION_H