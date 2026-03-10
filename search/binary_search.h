//
// Created by neo on 3/9/26.
//

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
template <typename T>
int binarySearch(T arr[], T item, int low, int high) {
    while (low <= high) {
        //int mid = low + (high - low) / 2;
        int mid = (low + high) / 2;
        if (item == arr[mid])
            return mid + 1;
        if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
#endif //BINARY_SEARCH_H
