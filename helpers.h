#ifndef HELPERS_H
#define HELPERS_H

#include <random>
#include <ctime>
#include <iostream>
#include <bits/ostream.tcc>
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

#endif //HELPERS_H