//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_LIS_H
#define ALGORITHMS_LIS_H

#include <vector>
#include <algorithm>
#include <iostream>

// Longest Increasing Subsequence — O(n log n) patience sorting
// Returns length and the actual subsequence
std::pair<int, std::vector<int>> lis(const std::vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return {0, {}};

    std::vector<int> tails;   // tails[i] = smallest tail of IS with length i+1
    std::vector<int> parent(n, -1);
    std::vector<int> pos(n);  // pos[i] = index in tails where arr[i] was placed

    for (int i = 0; i < n; ++i) {
        int lo = (int)(std::lower_bound(tails.begin(), tails.end(), arr[i]) - tails.begin());
        if (lo == (int)tails.size()) tails.push_back(arr[i]);
        else tails[lo] = arr[i];
        pos[i] = lo;
        // find predecessor: last index j < i with pos[j] == lo-1
        if (lo > 0) {
            for (int j = i - 1; j >= 0; --j) {
                if (pos[j] == lo - 1 && arr[j] < arr[i]) { parent[i] = j; break; }
            }
        }
    }

    int len = tails.size();
    // trace back
    std::vector<int> seq;
    int cur = -1;
    for (int i = n - 1; i >= 0; --i)
        if (pos[i] == len - 1) { cur = i; break; }
    while (cur != -1) { seq.push_back(arr[cur]); cur = parent[cur]; }
    std::reverse(seq.begin(), seq.end());
    return {len, seq};
}

void demoLIS() {
    std::vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    auto [len, seq] = lis(arr);
    std::cout << "LIS length: " << len << "\nSequence: ";
    for (int x : seq) std::cout << x << " ";
    std::cout << std::endl;
}

#endif //ALGORITHMS_LIS_H
