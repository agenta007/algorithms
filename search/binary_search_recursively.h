//
// Created by neo on 3/9/26.
//

#ifndef BINARY_SEARCH_RECURSIVELY_H
#define BINARY_SEARCH_RECURSIVELY_H
#include <iterator>

template <typename T>
int binarySearchRecursively(T arr[], T value, int start, int end, int sz) {
    //if (start > end)
    //    return -1;
    int middle_index = (end - start) / 2 + start;
    //if (middle_index >= sizeof(arr) / sizeof(arr[0]) || middle_index < 0 )
    //    return -1;
    if (arr[middle_index] == value)
        return middle_index;
    if (arr[middle_index] < value)
        return binarySearchRecursively(arr, value, middle_index + 1, end, sz);
    if (arr[middle_index] > value)
        return binarySearchRecursively(arr, value, start, middle_index - 1, sz);
}
#endif //BINARY_SEARCH_RECURSIVELY_H
