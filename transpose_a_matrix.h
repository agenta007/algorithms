//
// Created by neo on 3/28/26.
//

#ifndef ALGORITHMS_TRANSPOSE_A_MATRIX_H
#define ALGORITHMS_TRANSPOSE_A_MATRIX_H
#include <iostream>
#include <random>
using namespace std;
int** transposeAmatrix(int n, int m, int **orig_matrix) {
    int** matrix = new int*[m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = orig_matrix[j][i];
        }
    }
    return matrix;

}

void printMatrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void demoTransposeAmatrix() {
    srand(time(0));
    int n, m;
    n = 3;
    m = 4;
    int **orig_matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        orig_matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            orig_matrix[i][j] = rand() % 100;
        }
    }
    printMatrix(orig_matrix, n, m);
    cout << endl;
    int **tranposed_matrix = transposeAmatrix(n, m, orig_matrix);
    printMatrix(tranposed_matrix, m, n);
    for (int i = 0; i < n; i++) {
        delete [] orig_matrix[i];
    }
    delete [] orig_matrix;
}
#endif //ALGORITHMS_TRANSPOSE_A_MATRIX_H