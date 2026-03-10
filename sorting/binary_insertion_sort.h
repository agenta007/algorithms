//
// Created by neo on 3/9/26.
//

#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

#include <iostream>
template <typename T>
void binaryInsertionSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T selected = arr[i];
        int j = i - 1;

        // Find the location where selected should be inserted
        int loc = binarySearch(arr, selected, 0, j);

        // Move all elements after loc to create space
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[loc] = selected;
    }
}

#endif //BINARY_INSERTION_SORT_H