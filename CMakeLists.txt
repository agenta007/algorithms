cmake_minimum_required(VERSION 3.29)
project(algorithms)
set(CMAKE_CXX_STANDARD 20)

# Headers are found automatically via #include — only .cpp files needed here
add_executable(algorithms
        main.cpp
        rod_cutting.cpp
        graph/knight_steps.cpp
        exam/supertriangle.h
        greedy/trapping_rain_water.h
        sorting/intervals_sort.h
        euclid_gcd.h
        transpose_a_matrix.h
        greedy/task_bind.h
        algoexpert/two_number_sum.h
        greedy/obsht_broi_nenamalqvashti_chisla.h
        graph/dfs_check_if_graph_is_bipartite.h
)