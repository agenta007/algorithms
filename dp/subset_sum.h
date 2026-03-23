//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_SUBSET_SUM_H
#define ALGORITHMS_SUBSET_SUM_H

#include <vector>
#include <functional>
#include <iostream>

// Subset sum: does any subset of arr sum to target?
// dp[j] = true if sum j is achievable
bool subsetSum(const std::vector<int>& arr, int target) {
    std::vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int x : arr)
        for (int j = target; j >= x; --j)
            if (dp[j - x]) dp[j] = true;
    return dp[target];
}

// Returns all subsets that sum to target
std::vector<std::vector<int>> subsetSumAll(const std::vector<int>& arr, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    int n = arr.size();

    std::function<void(int, int)> solve = [&](int idx, int rem) {
        if (rem == 0) { result.push_back(current); return; }
        if (idx == n || rem < 0) return;
        // include arr[idx]
        current.push_back(arr[idx]);
        solve(idx + 1, rem - arr[idx]);
        current.pop_back();
        // skip arr[idx]
        solve(idx + 1, rem);
    };

    solve(0, target);
    return result;
}

void demoSubsetSum() {
    std::vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    std::cout << "Subset sum (" << target << "): "
              << (subsetSum(arr, target) ? "YES" : "NO") << "\n";

    auto all = subsetSumAll(arr, target);
    std::cout << "All subsets summing to " << target << ":\n";
    for (auto& s : all) {
        std::cout << "  { ";
        for (int x : s) std::cout << x << " ";
        std::cout << "}\n";
    }
}

#endif //ALGORITHMS_SUBSET_SUM_H
