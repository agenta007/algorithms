#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <algorithm> // за std::swap

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Приемаме, че текущият елемент е най-малкият
        int min_idx = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Разменяме само ако сме намерили по-малък елемент
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

#endif //SELECTION_SORT_H