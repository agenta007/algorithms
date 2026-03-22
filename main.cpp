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
#include "dp/zadacha1_dp.h"
#include "graph/read_adjacency_list.h"
#include "greedy/fractional_knapsack.h"
#include "greedy/min_cost.h"
#include "graph/read_adjacency_matrix.h"
using namespace std;
#define stack_array_size 100

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    //demoBinarySearch();
    //int arr[] = {1, 2, 3}; // Example input array (replace with your actual array)
    //int rod_length = sizeof(arr) / sizeof(arr[0]);
    //rod_cutting(arr, rod_length);
    //bucketSortDemo();
    //vector<int> coins = {1, 2, 5, 10};
    //printVector(coinChange(39, coins));
    //vector<int> val = {60, 100, 120};
    //vector<int> wt = {30, 20, 30};
    //int capacity = 50;
    //cout << fractionalKnapsack(val, wt, capacity) << endl;
    
    //std::vector<std::vector<int>> adj_matrix(m, std::vector<int>(m, 0));
    //readAdjacencyMatrix(adj_matrix, n, m);
    //printAdjacencyMatrix(adj_matrix, n, m);
    //vector<int> a = { 4, 3, 2 };
    //cout << minCost(a) << endl;
    int n = 4, m = 4;
    std::vector<std::vector<int>> adj_list(m, std::vector<int>(m, 0));
    readAdjacencyList(adj_list, n, m);
    
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    //int arr[stack_array_size];
    //generateRandomInts(arr, stack_array_size, 0, 100);
    //selectionSort(arr, stack_array_size);
    //QuickSort(arr, 0, stack_array_size - 1);
    //cout << "Sorted: ";
    //printArray(arr, stack_array_size);
    //cout << binarySearch(arr, 4, 0, stack_array_size - 1) << endl;
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}