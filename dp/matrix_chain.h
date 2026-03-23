//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_MATRIX_CHAIN_H
#define ALGORITHMS_MATRIX_CHAIN_H

#include <vector>
#include <climits>
#include <iostream>

// Matrix chain multiplication
// dims[i] x dims[i+1] is the dimension of matrix i
// Returns minimum number of scalar multiplications
// dp[i][j] = min cost to multiply matrices i..j
int matrixChain(const std::vector<int>& dims) {
    int n = dims.size() - 1; // number of matrices
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    // len = chain length
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
                dp[i][j] = std::min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n-1];
}

// Also returns the optimal parenthesisation
static void printParens(const std::vector<std::vector<int>>& split, int i, int j) {
    if (i == j) { std::cout << "M" << i+1; return; }
    std::cout << "(";
    printParens(split, i, split[i][j]);
    printParens(split, split[i][j]+1, j);
    std::cout << ")";
}

void demoMatrixChain() {
    // Matrices: 30x35, 35x15, 15x5, 5x10, 10x20, 20x25
    std::vector<int> dims = {30, 35, 15, 5, 10, 20, 25};
    int n = dims.size() - 1;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> split(n, std::vector<int>(n, 0));

    for (int len = 2; len <= n; ++len)
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
                if (cost < dp[i][j]) { dp[i][j] = cost; split[i][j] = k; }
            }
        }

    std::cout << "Matrix chain min ops: " << dp[0][n-1] << "\nOrder: ";
    printParens(split, 0, n-1);
    std::cout << std::endl;
}

#endif //ALGORITHMS_MATRIX_CHAIN_H
