#include <iostream>

#include "helpers.h"
#include "sorting/selection_sort.h"
#include "search/binary_search.h"
#include "sorting/quick_sort.h"
#include "sorting/quick_sort_ll.h"
#include "helpers.h"
#include "search/binary_search.h"
#include "search/binary_search_recursively.h"
using namespace std;
#define stack_array_size 100

void demoBinarySearch() {
    int sorted_arr[] {1, 3, 5, 27, 29, 30 ,31, 32, 100};
    int index_of_searched_number = binarySearchRecursively(sorted_arr, 100, 0, std::size(sorted_arr) - 1, std::size(sorted_arr));
    cout << index_of_searched_number << endl;
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    demoBinarySearch();
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    //int arr[stack_array_size];
    //generateRandomInts(arr, stack_array_size, 0, 100);
    //selectionSort(arr, stack_array_size);
    //QuickSort(arr, 0, stack_array_size - 1);
    //cout << "Sorted: ";
    //printArray(arr, stack_array_size);
    //cout << binarySearch(arr, 4, 0, stack_array_size - 1) << endl;
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}