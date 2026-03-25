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

// Edge: a connection from the current vertex to a neighbor.
//   first  = neighbor_vertex  (where this edge leads)
//   second = edge_weight      (cost to travel this edge)
using Edge = std::pair<int, int>;

// HeapEntry: what gets pushed into the min-heap.
//   first  = tentative_distance  (total cost to reach this vertex so far)
//   second = vertex              (which vertex this entry is for)
// The heap is sorted by tentative_distance (smallest first),
// so we always process the closest unfinished vertex next.
using HeapEntry = std::pair<int, int>;

// Sentinel value meaning "no path found yet"
const int INFINITY_DISTANCE = std::numeric_limits<int>::max();

// dijkstra: finds the shortest distance from start_vertex to every other vertex.
//
// adjacency_list[u] = list of {neighbor, weight} edges leaving vertex u
// Returns shortest_distances[], where shortest_distances[v] is the
// minimum total cost to reach v from start_vertex.
std::vector<int> dijkstra(const std::vector<std::vector<Edge>>& adjacency_list, int start_vertex) {
    int num_vertices = adjacency_list.size();

    // shortest_distances[v] = best known cost to reach v from start_vertex.
    // Initialised to INFINITY (unreachable) for all vertices except the source.
    std::vector<int> shortest_distances(num_vertices, INFINITY_DISTANCE);

    // min_heap always gives us the HeapEntry with the smallest tentative_distance.
    // We use std::greater so the smallest distance floats to the top (min-heap).
    std::priority_queue<HeapEntry, std::vector<HeapEntry>, std::greater<HeapEntry>> min_heap;

    // Step 1: the cost to reach the source from itself is 0.
    shortest_distances[start_vertex] = 0;
    min_heap.push({0, start_vertex});

    while (!min_heap.empty()) {
        // Step 2: pick the unvisited vertex with the smallest known distance.
        auto [tentative_distance, current_vertex] = min_heap.top();
        min_heap.pop();

        // Step 3: skip stale heap entries.
        // When we find a better path to a vertex, we push a new HeapEntry but
        // leave the old one in the heap. If that old entry is popped later,
        // tentative_distance will be greater than the already-recorded best —
        // so we skip it to avoid redundant work.
        if (tentative_distance > shortest_distances[current_vertex])
            continue;

        // Step 4: relax all edges leaving current_vertex.
        // "Relaxing" means: can we reach neighbor_vertex cheaper by going
        // through current_vertex than any path we've found so far?
        for (const auto& [neighbor_vertex, edge_weight] : adjacency_list[current_vertex]) {
            int distance_through_current = shortest_distances[current_vertex] + edge_weight;

            if (distance_through_current < shortest_distances[neighbor_vertex]) {
                // Found a cheaper path — update the best known distance
                // and push a fresh HeapEntry so this vertex is reconsidered.
                shortest_distances[neighbor_vertex] = distance_through_current;
                min_heap.push({distance_through_current, neighbor_vertex});
            }
        }
    }

    return shortest_distances;
}

// dijkstra_verbose: same algorithm, prints every decision for learning purposes.
std::vector<int> dijkstra_verbose(const std::vector<std::vector<Edge>>& adjacency_list, int start_vertex) {
    //get number of vertices
    int num_vertices = adjacency_list.size();
    //set all distances to INFINITY
    std::vector<int> shortest_distances(num_vertices, INFINITY_DISTANCE);
    //create a min priority queue
    std::priority_queue<HeapEntry, std::vector<HeapEntry>, std::greater<HeapEntry>> min_heap;

    std::cout << "=== Dijkstra Started (source = " << start_vertex << ") ===" << std::endl;

    shortest_distances[start_vertex] = 0;
    min_heap.push({0, start_vertex});

    while (!min_heap.empty()) {
        auto [tentative_distance, current_vertex] = min_heap.top();
        min_heap.pop();

        std::cout << "\nPopped vertex " << current_vertex
                  << " with tentative_distance=" << tentative_distance << std::endl;

        // Stale entry: a shorter path to current_vertex was already finalised
        if (tentative_distance > shortest_distances[current_vertex]) {
            std::cout << "  -> Stale entry, skipping "
                      << "(best known = " << shortest_distances[current_vertex] << ")" << std::endl;
            continue;
        }

        //for every adjacent vertex
        //"Relaxing" an edge means: checking if going through this edge gives a shorter path, and updating if it does.
        for (const auto& [neighbor_vertex, edge_weight] : adjacency_list[current_vertex]) {
            int distance_through_current = shortest_distances[current_vertex] + edge_weight;

            std::cout << "  Relaxing edge " << current_vertex << " -> " << neighbor_vertex
                      << "  (edge_weight=" << edge_weight
                      << ", distance_through_current=" << distance_through_current
                      << ", best_so_far=" << shortest_distances[neighbor_vertex] << ")";

            if (distance_through_current < shortest_distances[neighbor_vertex]) {
                shortest_distances[neighbor_vertex] = distance_through_current;
                min_heap.push({distance_through_current, neighbor_vertex});
                std::cout << "  -> UPDATED" << std::endl;
            } else {
                std::cout << "  -> no improvement" << std::endl;
            }
        }
    }

    std::cout << "\n=== Dijkstra Finished ===" << std::endl;
    return shortest_distances;
}

void runDijkstra() {
    bool isDirected = false;

    // Edge list format: {from_vertex, to_vertex, weight}
    std::vector<std::tuple<int, int, int>> edge_list = {
        {0, 1, 2}, {0, 3, 8}, {1, 4, 6}, {3, 4, 7}, {4, 5, 1}, {4, 2, 9}, {5, 3, 3}
    };
    int num_vertices = 6; // vertices 0..5

    std::vector<std::vector<Edge>> adjacency_list(num_vertices);
    for (const auto& [from, to, weight] : edge_list) {
        adjacency_list[from].push_back({to, weight});
        if (!isDirected)
            adjacency_list[to].push_back({from, weight});
    }

    std::vector<int> shortest_distances = dijkstra_verbose(adjacency_list, 0);

    std::cout << "\nShortest distances from vertex 0:" << std::endl;
    for (int v = 0; v < num_vertices; ++v) {
        if (shortest_distances[v] == INFINITY_DISTANCE)
            std::cout << "  0 -> " << v << ": unreachable" << std::endl;
        else
            std::cout << "  0 -> " << v << ": " << shortest_distances[v] << std::endl;
    }
}

#endif //ALGORITHMS_DIJKSTRA_H
