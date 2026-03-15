//
// Created by neo on 3/9/26.
//

#ifndef BINARY_SEARCH_RECURSIVELY_H
#define BINARY_SEARCH_RECURSIVELY_H
#include <iterator>
using namespace std;
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

inline void demoBinarySearch() {
    int sorted_arr[] {1, 3, 5, 27, 29, 30 ,31, 32, 100};
    int index_of_searched_number = binarySearchRecursively(sorted_arr, 100, 0, std::size(sorted_arr) - 1, std::size(sorted_arr));
    cout << index_of_searched_number << endl;
}
#endif //BINARY_SEARCH_RECURSIVELY_H
