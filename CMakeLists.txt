cmake_minimum_required(VERSION 3.29)
project(algorithms)
set(CMAKE_CXX_STANDARD 20)

# List all source files
set(SOURCES
        main.cpp
        rod_cutting.cpp
        graph/knight_steps.cpp
)

set(HEADERS
        sorting/selection_sort.h
        helpers.h
        sorting/binary_insertion_sort.h
        search/binary_search.h
        sorting/quick_sort.h
        sorting/quick_sort_ll.h
        search/binary_search_recursively.h
        sorting/bucket_sort.h
        greedy/minimum_number_of_coins.h
        dp/zadacha1_dp.h
        greedy/fractional_knapsack.h
        greedy/min_cost.h
        graph/read_adjacency_list.h
        graph/read_adjacency_matrix.h
        graph/adjacency_list.h
        graph/simple_adjacency_list_implementation.h
        graph/bfs.h
        graph/shortest_path_unweighted.h
        graph/dfs.h
        graph/dijkstra.h
        graph/kruskal.h
        graph/prim.h
        greedy/activity_selection.h
        greedy/huffman.h
        greedy/job_sequencing.h
        greedy/interval_partitioning.h
        dp/knapsack_01.h
        dp/lcs.h
        dp/lis.h
        dp/edit_distance.h
        dp/coin_change_dp.h
        dp/rod_cutting.h
        dp/matrix_chain.h
        dp/subset_sum.h
        dp/longest_palindromic_subsequence.h
        dp/max_subarray.h
        dp/word_break.h
        graph/topological_sort.h
        graph/undirected_cycle_detector.h
        graph/knight_steps.h
        graph/printPathVertices.h
        sorting/merge_two_sorted_arrays.h
        graph/find_shortest_path_between_cities.h
        graph/find_shortes_path_between_nodes.h
        graph/distance_of_nearest_1_in_binary_grid.h
        graph/steps_knight.h
)

# Remove the problematic file from the list
# If you don't have dfs_2.h, remove it from the list
# Or create the file if it's needed

add_executable(algorithms ${SOURCES} ${HEADERS})