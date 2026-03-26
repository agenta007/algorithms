#ifndef HELPERS_H
#define HELPERS_H

#include <random>
#include <ctime>
#include <iostream>
#include <bits/ostream.tcc>
#include <map>
using namespace std;

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
template <typename T>
void printVector(const T& vec) { // 1. Подаване чрез константна референция
    for (const auto& i : vec) {   // 2. Избягване на излишни копия в цикъла
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

inline void printAdjacencyList(std::vector<std::vector<int>>& adj) {
    for (auto& i : adj) {
        cout << i[0] << " -> ";
        printVector(i);
    }
}

inline void printAdjacencyMatrix(std::vector<std::vector<int>> adj_matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << adj_matrix[i][j] << " ";
        }
    }
}
/**
 * Пълни подаден масив с 10 случайни числа в диапазона [min, max]
 */
inline void generateRandomInts(int arr[], int size, int min, int max) {
    // Използваме устройство за генериране на ентропия
    random_device rd;
    // Генератор на числа (Mersenne Twister)
    mt19937 gen(rd());
    // Дефинираме диапазона
    uniform_int_distribution<> dis(min, max);

    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
    cout << "Generated: ";
    printArray(arr, size);
}

inline std::vector<std::vector<int>> randomTree(int n) {
    std::vector<std::vector<int>> adj(n);
    srand(time(0));

    // Each node (1..n-1) picks a random parent from (0..i-1)
    for (int i = 1; i < n; i++) {
        int parent = rand() % i;
        adj[parent].push_back(i);
        adj[i].push_back(parent);  // remove for directed
    }
    return adj;
}

template <typename T>
void printVectorOfVectors(const std::vector<std::vector<T>>& grid) {
    for (const auto& row : grid) {
        for (const auto& val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
}
void printCoordinateSystem(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << "(" << i << "," << j << ") ";
        cout << "\n";
    }
}

void print_djikstra_shortest_distances(const std::map<std::string, int>& shortest_distances) {
    for (const auto& [vertex, dist] : shortest_distances)
        std::cout << vertex << ": " << (dist == std::numeric_limits<int>::max() ? "INF" : std::to_string(dist)) << "\n";
}

#endif //HELPERS_H