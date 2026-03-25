//
// Created by neo on 3/22/26.
//
#ifndef ALGORITHMS_DIJKSTRA_H
#define ALGORITHMS_DIJKSTRA_H

#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <tuple>

// Type aliases for readability
using Edge = std::pair<int, int>; // {neighbor, weight}
using NodeState = std::pair<int, int>; // {distance, vertex}

const int INFINITY_DISTANCE = std::numeric_limits<int>::max();

std::vector<int> dijkstra(const std::vector<std::vector<Edge>>& adjacency_list, int start_vertex) {
    int num_vertices = adjacency_list.size();

    // Vector to store shortest distances from source
    std::vector<int> distances(num_vertices, INFINITY_DISTANCE);

    // Min-heap priority queue storing {distance, vertex}
    std::priority_queue<NodeState, std::vector<NodeState>, std::greater<NodeState>> min_heap;
    // Initialize source vertex distance
    distances[start_vertex] = 0;
    min_heap.push({0, start_vertex});
    while (!min_heap.empty()) {
        // Extract the vertex with the minimum distance
        auto [current_distance, current_vertex] = min_heap.top();
        min_heap.pop();

        // Skip stale entries
        if (current_distance > distances[current_vertex]) {
            continue;
        }

        // Iterate over neighbors
        for (const auto& [neighbor_vertex, edge_weight] : adjacency_list[current_vertex]) {
            int new_distance = distances[current_vertex] + edge_weight;

            // Relaxation step
            if (new_distance < distances[neighbor_vertex]) {
                int old_distance = distances[neighbor_vertex];
                distances[neighbor_vertex] = new_distance;
                min_heap.push({new_distance, neighbor_vertex});
                std::cout << " -> Updated distance: " << old_distance << " -> " << new_distance << std::endl;
            } else {
                std::cout << " -> No update (Current distance " << distances[neighbor_vertex] << " is better)" << std::endl;
            }
        }
    }

    return distances;
}

std::vector<int> dijkstra_verbose(const std::vector<std::vector<Edge>>& adjacency_list, int start_vertex) {
    int num_vertices = adjacency_list.size();

    // Vector to store shortest distances from source
    std::vector<int> distances(num_vertices, INFINITY_DISTANCE);

    // Min-heap priority queue storing {distance, vertex}
    std::priority_queue<NodeState, std::vector<NodeState>, std::greater<NodeState>> min_heap;

    std::cout << "=== Dijkstra Algorithm Started ===" << std::endl;
    std::cout << "Start Vertex: " << start_vertex << std::endl;

    // Initialize source vertex distance
    distances[start_vertex] = 0;
    min_heap.push({0, start_vertex});
    std::cout << "Initialized distance of vertex " << start_vertex << " to 0" << std::endl;

    while (!min_heap.empty()) {
        // Extract the vertex with the minimum distance
        auto [current_distance, current_vertex] = min_heap.top();
        min_heap.pop();

        std::cout << "\n--- Processing Vertex " << current_vertex << " (Distance: " << current_distance << ") ---" << std::endl;

        // Skip stale entries
        if (current_distance > distances[current_vertex]) {
            std::cout << "Skipping stale entry for vertex " << current_vertex
                      << " (Current best distance: " << distances[current_vertex] << ")" << std::endl;
            continue;
        }

        // Iterate over neighbors
        for (const auto& [neighbor_vertex, edge_weight] : adjacency_list[current_vertex]) {
            std::cout << "Checking neighbor " << neighbor_vertex << " (Edge weight: " << edge_weight << ")";

            int new_distance = distances[current_vertex] + edge_weight;

            // Relaxation step
            if (new_distance < distances[neighbor_vertex]) {
                int old_distance = distances[neighbor_vertex];
                distances[neighbor_vertex] = new_distance;
                min_heap.push({new_distance, neighbor_vertex});

                std::cout << " -> Updated distance: " << old_distance << " -> " << new_distance << std::endl;
            } else {
                std::cout << " -> No update (Current distance " << distances[neighbor_vertex] << " is better)" << std::endl;
            }
        }
    }

    std::cout << "\n=== Algorithm Finished ===" << std::endl;
    return distances;
}

void runDijkstra() {
    std::vector<std::tuple<int, int, int>> djikstra_directed_graph = {
        {0, 1, 7}, {1, 4, 3}, {1, 2, 6}, {1, 3, 20}, {2, 3, 14}, {3, 4, 2}
    };
    bool isDirected = false;
    std::vector<std::tuple<int, int, int>> graph_felix_tech_tips = {
        {0, 1, 2}, {0, 3, 8}, {1, 4, 6}, {3, 4, 7}, {4, 5, 1}, {4, 2, 9}, {5, 3, 3}
    };
    int num_vertices = 5;
    std::vector<std::vector<Edge>> adjacency_list(num_vertices);

    // Edge list: {u, v, weight}
    std::cout << "Building Graph..." << std::endl;
    if (isDirected) {
        for (const auto& [u, v, weight] : graph_felix_tech_tips) {
            adjacency_list[u].push_back({v, weight});
            //adjacency_list[v].push_back({u, weight});
            std::cout << "Added edge: " << u << " -> " << v << " (Weight: " << weight << ")" << std::endl;
        }
    }
    else {
        for (const auto& [u, v, weight] : graph_felix_tech_tips) {
            adjacency_list[u].push_back({v, weight});
            adjacency_list[v].push_back({u, weight});
            std::cout << "Added edge: " << u << " -> " << v << " (Weight: " << weight << ")" << std::endl;
        }
    }
    std::cout << "Built graph." << std::endl;

    std::vector<int> shortest_distances = dijkstra(adjacency_list, 0);

    std::cout << "\nFinal Results:" << std::endl;
    for (int i = 0; i < num_vertices; ++i) {
        std::cout << "Shortest distance from 0 to " << i << ": " << shortest_distances[i] << std::endl;
    }
}

#endif //ALGORITHMS_DIJKSTRA_H