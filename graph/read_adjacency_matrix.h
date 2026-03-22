//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_READ_ADJACENCY_MATRIX_H
#define ALGORITHMS_READ_ADJACENCY_MATRIX_H
void readAdjacencyMatrix(std::vector<std::vector<int>>& adj_matrix, int n, int m) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> adj_matrix[i][j];  // assign, don't push_back
        }
    }
}
#endif //ALGORITHMS_READ_ADJACENCY_MATRIX_H