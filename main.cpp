#include <iostream>

#include "helpers.h"
#include "sorting/selection_sort.h"
#include "search/binary_search.h"
#include "sorting/quick_sort.h"
#include "sorting/quick_sort_ll.h"
#include "helpers.h"
#include "search/binary_search.h"
#include "search/binary_search_recursively.h"
#include "sorting/bucket_sort.h"
#include "greedy/minimum_number_of_coins.h"
#include "greedy/fractional_knapsack.h"
#include "greedy/min_cost.h"
#include "greedy/activity_selection.h"
#include "greedy/huffman.h"
#include "greedy/job_sequencing.h"
#include "greedy/interval_partitioning.h"
#include "dp/zadacha1_dp.h"
#include "dp/knapsack_01.h"
#include "dp/lcs.h"
#include "dp/lis.h"
#include "dp/edit_distance.h"
#include "dp/coin_change_dp.h"
#include "dp/rod_cutting.h"
#include "dp/matrix_chain.h"
#include "dp/subset_sum.h"
#include "dp/longest_palindromic_subsequence.h"
#include "dp/max_subarray.h"
#include "dp/word_break.h"
#include "graph/read_adjacency_list.h"
#include "graph/simple_adjacency_list_implementation.h"
#include "graph/adjacency_list.h"
#include "graph/simple_adjacency_list_implementation.h"
#include "graph/read_adjacency_matrix.h"
#include "graph/bfs.h"
#include "graph/shortest_path_unweighted.h"
#include "graph/dfs.h"
#include "graph/dijkstra.h"
#include "graph/prim.h"
#include "graph/undirected_cycle_detector.h"
#include "graph/bfs_2.h"
using namespace std;
#define stack_array_size 100

void demoSearchAlgorithms() {
    //demoBinarySearch();
    //int arr[] = {1, 2, 3}; // Example input array (replace with your actual array)
    //int rod_length = sizeof(arr) / sizeof(arr[0]);
    //rod_cutting(arr, rod_length);
    //bucketSortDemo();
    //
    //printVector(coinChange(39, coins));
    //int capacity = 50;
    //cout << fractionalKnapsack(val, wt, capacity) << endl;
    //std::vector<std::vector<int>> adj_matrix(m, std::vector<int>(m, 0));
    //readAdjacencyMatrix(adj_matrix, n, m);
    //printAdjacencyMatrix(adj_matrix, n, m);
    //vector<int> a = { 4, 3, 2 };
    //cout << minCost(a) << endl;
    //int n = 4, m = 4;
    //std::vector<std::vector<int>> adj_list(m, std::vector<int>(m, 0));
    //readAdjacencyList(adj_list, n, m);
    //std::vector<std::vector<int>> adj_list(4, std::vector<int>());
    //createAdjList(adj_list, 4);
    //printAdjList(adj_list);


    //cout << bfs_traverse_a_graph(adj_list_graph_with_cycle, 0) << '\n';
    //vector<int> order = bfs(adj_list_graph_with_cycle, 0);
    //printVector(order);
    //int n = 6;
    //auto adj_list = randomTree(n);
    //printAdjacencyList(adj_list_graph_with_cycle);
    //cout << (hasCycle(adj_list_graph_with_cycle) ? "yes" : "no") << endl;
    //demoShortestPathUnweighted();
    //shortestPathUnweighted(adj_list, 0, );
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    //int arr[stack_array_size];
    //generateRandomInts(arr, stack_array_size, 0, 100);
    //selectionSort(arr, stack_array_size);
    //QuickSort(arr, 0, stack_array_size - 1);
    //cout << "Sorted: ";
    //printArray(arr, stack_array_size);
    //cout << binarySearch(arr, 4, 0, stack_array_size - 1) << endl;
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    vector<int> coins = {1, 2, 5, 10};
    vector<int> coin_values = {60, 100, 120};
    vector<int> coin_weights = {30, 20, 30};

    std::vector<std::vector<int>> adj_list_graph_with_cycle = {
        {1},          // 0 -> 1
        {0, 2, 3},    // 1 -> 0, 2, 3
        {1, 3},       // 2 -> 1, 3
        {1, 2}        // 3 -> 1, 2
    };
    std::vector<std::vector<int>> adj_graph_without_cycle = {
        {1},       // 0 -> 1
        {0, 2},    // 1 -> 0, 2
        {1, 3},    // 2 -> 1, 3
        {2}        // 3 -> 2
    };
    std::vector<std::tuple<int, int, int>> djikstra_directed_graph = {
        {0, 1, 7}, {1, 4, 3}, {1, 2, 6}, {1, 3, 20}, {2, 3, 14}, {3, 4, 2}
    };
    demoBFS();
    runDijkstra(djikstra_directed_graph, true);
    return 0;
}