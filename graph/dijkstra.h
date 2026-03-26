//tech with tim lecture from lesson99.mp4 algoexpert.io
//O(v^2 + e) time | O (v) space - where V is number of vertices and E is the number of edges
//1. Mark all nodes as unvisited
//2. Assign to all nodes a tentative distance value (in the beginning 0, INF ... INF)
//3. For the current node calculate the distance to all unvisited neighbours
//3.1 Update shortest distance, if new distance is shorter that the old distance
//4. Mark current node as visited
//5. Choose new current node from unvisited nodes with minimal distance
#ifndef ALGORITHMS_DIJKSTRA_H
#define ALGORITHMS_DIJKSTRA_H

#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <map>
#include <tuple>
#include <iomanip>

using Edge = std::pair<int, int>;
using StringVertexAdjacency = std::pair<string, string>;
struct EdgeBetweenStringVertices {
    std::string src;
    std::string dst;
    int weight;
};

const int INFINITY_DISTANCE = std::numeric_limits<int>::max();

struct VertexInfo {
    int min_distance;
    std::string previous_vertex;
};
std::vector<std::string> reconstruct_path(
    const std::map<std::string, VertexInfo>& vertex_table,
    const std::string& start_vertex,
    const std::string& end_vertex)
{
    std::vector<std::string> path;

    std::string current = end_vertex;
    while (!current.empty()) {
        path.push_back(current);
        if (current == start_vertex)
            break;
        current = vertex_table.at(current).previous_vertex;
    }

    if (path.back() != start_vertex)
        return {}; // end_vertex is unreachable from start_vertex

    std::reverse(path.begin(), path.end());
    return path;
}


void print_dijkstra_table(const std::map<std::string, VertexInfo>& vertex_table) {
    constexpr int COL_WIDTH = 16;

    std::cout << std::left
              << std::setw(COL_WIDTH) << "Vertex"
              << std::setw(COL_WIDTH) << "Min Distance"
              << std::setw(COL_WIDTH) << "Previous Vertex"
              << "\n"
              << std::string(COL_WIDTH * 3, '-') << "\n";

    for (const auto& [vertex, info] : vertex_table) {
        std::string distance_str = (info.min_distance == INFINITY_DISTANCE) ? "INF" : std::to_string(info.min_distance);
        std::string previous_str = info.previous_vertex.empty() ? "-" : info.previous_vertex;

        std::cout << std::setw(COL_WIDTH) << vertex
                  << std::setw(COL_WIDTH) << distance_str
                  << std::setw(COL_WIDTH) << previous_str
                  << "\n";
    }
}
std::map<std::string, VertexInfo> dijkstra(
    const std::map<std::string, std::vector<std::pair<std::string, int>>>& adjacency_list,
    const std::string& start_vertex)
{
    using HeapEntry = std::pair<int, std::string>;

    std::map<std::string, VertexInfo> vertex_table;
    for (const auto& [vertex, _] : adjacency_list)
        vertex_table[vertex] = {INFINITY_DISTANCE, ""};

    std::priority_queue<HeapEntry, std::vector<HeapEntry>, std::greater<HeapEntry>> min_heap;

    vertex_table[start_vertex].min_distance = 0;
    min_heap.push({0, start_vertex});

    while (!min_heap.empty()) {
        auto [tentative_distance, current_vertex] = min_heap.top();
        min_heap.pop();

        if (tentative_distance > vertex_table[current_vertex].min_distance)
            continue;

        for (const auto& [neighbor_vertex, edge_weight] : adjacency_list.at(current_vertex)) {
            int distance_through_current = vertex_table[current_vertex].min_distance + edge_weight;
            if (distance_through_current < vertex_table[neighbor_vertex].min_distance) {
                vertex_table[neighbor_vertex] = {distance_through_current, current_vertex};
                min_heap.push({distance_through_current, neighbor_vertex});
            }
        }
    }

    return vertex_table;
}

std::vector<int> dijkstra(const std::vector<std::vector<Edge>>& adjacency_list, int start_vertex) {
    int num_vertices = adjacency_list.size();
    std::vector<int> shortest_distances(num_vertices, INFINITY_DISTANCE);

    using HeapEntry = std::pair<int, int>;
    std::priority_queue<HeapEntry, std::vector<HeapEntry>, std::greater<HeapEntry>> min_heap;

    shortest_distances[start_vertex] = 0;
    min_heap.push({0, start_vertex});

    while (!min_heap.empty()) {
        auto [tentative_distance, current_vertex] = min_heap.top();
        min_heap.pop();

        if (tentative_distance > shortest_distances[current_vertex])
            continue;

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

void runDijkstra() {
    bool isDirected = false;

    // Edge list format: {from_vertex, to_vertex, weight}
    std::vector<std::tuple<int, int, int>> edge_list = {
        {0, 1, 2}, {0, 3, 8}, {1, 4, 6}, {3, 4, 7}, {4, 5, 1}, {4, 2, 9}, {5, 3, 3}
    };
    // Edge list format: {from_vertex_letter, to_vertex_letter, weight}
    std::vector<EdgeBetweenStringVertices> felixEdgeList = {
        {"A", "B", 2},
        {"A", "D", 8},
        {"B", "D", 5},
        {"B", "E", 6},
        {"D", "F", 2},
        {"F", "E", 1},
        {"F", "C", 3},
        {"E", "C", 9},
    };
    int num_vertices = 6; // vertices 0..5
    int felix_num_vertices = 6;
    std::map<std::string, std::vector<std::pair<std::string, int>>> adjacency_list_felix_graph;
    for (const auto& [src, dst, weight] : felixEdgeList) {
        adjacency_list_felix_graph[src].push_back({dst, weight});
        adjacency_list_felix_graph[dst].push_back({src, weight}); // if undirected
    }
    std::map<std::string, VertexInfo>  shortest_distances_table = dijkstra(adjacency_list_felix_graph, "A");
    print_dijkstra_table(shortest_distances_table);
    for (string str: reconstruct_path(shortest_distances_table, "A", "C"))
        cout << str;
    return;
    std::vector<std::vector<Edge>> adjacency_list(num_vertices);
    for (const auto& [from, to, weight] : edge_list) {
        adjacency_list[from].push_back({to, weight});
        if (!isDirected)
            adjacency_list[to].push_back({from, weight});
    }

}

#endif //ALGORITHMS_DIJKSTRA_H
