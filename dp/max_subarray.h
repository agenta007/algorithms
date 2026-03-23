//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_MAX_SUBARRAY_H
#define ALGORITHMS_MAX_SUBARRAY_H

#include <vector>
#include <climits>
#include <iostream>

// Kadane's algorithm: maximum subarray sum — O(n)
// Returns {max_sum, start_index, end_index}
std::tuple<int, int, int> maxSubarray(const std::vector<int>& arr) {
    int maxSum = INT_MIN, curSum = 0;
    int start = 0, end = 0, tempStart = 0;

    for (int i = 0; i < (int)arr.size(); ++i) {
        curSum += arr[i];
        if (curSum > maxSum) {
            maxSum = curSum;
            start = tempStart;
            end = i;
        }
        if (curSum < 0) {
            curSum = 0;
            tempStart = i + 1;
        }
    }
    return {maxSum, start, end};
}

// Maximum subarray product — O(n)
int maxSubarrayProduct(const std::vector<int>& arr) {
    int maxProd = arr[0], minProd = arr[0], result = arr[0];
    for (int i = 1; i < (int)arr.size(); ++i) {
        if (arr[i] < 0) std::swap(maxProd, minProd);
        maxProd = std::max(arr[i], maxProd * arr[i]);
        minProd = std::min(arr[i], minProd * arr[i]);
        result  = std::max(result, maxProd);
    }
    return result;
}

void demoMaxSubarray() {
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto [sum, l, r] = maxSubarray(arr);
    std::cout << "Max subarray sum: " << sum
              << " (indices " << l << " to " << r << ")\n";

    std::vector<int> arr2 = {2, 3, -2, 4};
    std::cout << "Max subarray product: " << maxSubarrayProduct(arr2) << "\n";
}

#endif //ALGORITHMS_MAX_SUBARRAY_H
