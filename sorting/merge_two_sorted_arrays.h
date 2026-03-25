//
// Created by neo on 3/23/26.
//

#ifndef ALGORITHMS_MERGE_TWO_SORTED_ARRAYS_H
#define ALGORITHMS_MERGE_TWO_SORTED_ARRAYS_H
#include <algorithm>

int* mergeTwoSortedArrays(int* arr1, int n1, int* arr2, int n2) {
    int mergedArraySz = n1 + n2;
    int *mergedArray = new int[mergedArraySz];
    int arr1Iterator = 0;
    int arr2Iterator = 0;
    for (int i = 0; i < mergedArraySz; i++) {
        printArray(mergedArray, mergedArraySz);
        //if first array is out of bound, but second one is not yet, append from second array to mergedArray
        //if (arr1 > arr1 + n1 - 1 && arr1 < arr2 + n2) {
        if (arr1Iterator >= n1 && arr2Iterator < n2) {
            mergedArray[i] = *arr2;
            ++arr2;
            ++arr2Iterator;
            continue;
        }
        //if second array is out of bound, but first one is not yet, append from second array to mergedArray
        //if (arr2 > arr2 + n2 - 1 && arr1 < arr1 + n1) {
        if (arr2Iterator >= n2 && arr1Iterator < n1) {
            mergedArray[i] = *arr1;
            ++arr1;
            ++arr1Iterator;
            continue;
        }
        if (*arr1 == *arr2) {
            mergedArray[i++] = *arr1;
            ++arr1;
            ++arr1Iterator;
            mergedArray[i] = *arr2;
            ++arr2;
            ++arr2Iterator;
            continue;
        }
        if (*arr1 < *arr2) {
            mergedArray[i] = *arr1;
            ++arr1;
            ++arr1Iterator;
        }
        else {
            mergedArray[i] = *arr2;
            ++arr2;
            ++arr2Iterator;
        }
    }
    return mergedArray;
}

int* mergeTwoSortedArraysScratch(int* arr1, int* arr2) {
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    //int *mergedArray = new int[mergedSz];
    int mergedArrIterator = 0;
    //if two arrays are of equal size
    if (n1 == n2) {
        int *ptr1 = arr1;
        int *ptr2 = arr2;
        while (ptr1 != ptr1 + n1 && ptr2 != ptr2 + n2 ) {
            if (ptr1 == ptr2) {
                //mergedArray[mergedArrIterator++] = *ptr1;
                ptr1++;
                //mergedArray[mergedArrIterator++] = *ptr1;
                ptr2++;
            }
            if (*ptr1 < *ptr2) {
                //mergedArray[mergedArrIterator++] = *ptr2;
                ptr2++;
            }
            else {
                //mergedArray[mergedArrIterator++] = *ptr1;
                ptr1++;
            }
        }
        //return mergedArray;
    }

    //if two arrays are of different size
    int mergedSz = std::max(n1, n2);
    int *bigArray = nullptr;
    int *smallArray = nullptr;
    if (mergedSz == sizeof(arr1) / sizeof(arr1[0])) {
        bigArray = arr1;
        smallArray = arr2;
    }
    else {
        bigArray = arr2;
        smallArray = arr1;
    }
    int smallerArrSz = std::min(n1, n2);

    //iterate until bigger ends
    for (int i = 0; i < mergedSz; ++i) {
        //
        if (i > smallerArrSz) {
            //mergedArray[i] = arr1[i];
        }
    }
}
void demoMergeTwoArrays() {
    //int *arr_to_merge1_ = new int[3]{10, 15, 20};
    //int *arr_to_merge2_ = new int [4]{5, 6, 6, 15};
    int *arr_to_merge1 = new int[5]{10, 15, 20, 22, 24};
    int *arr_to_merge2 = new int [7]{5, 6, 6, 15, 22, 23, 24};
    int *mergedArray = mergeTwoSortedArrays(arr_to_merge1, 5, arr_to_merge2, 7);
    delete[] arr_to_merge1;
    delete[] arr_to_merge2;
    printArray(mergedArray, 12);
    delete[] mergedArray;
}
#endif //ALGORITHMS_MERGE_TWO_SORTED_ARRAYS_H