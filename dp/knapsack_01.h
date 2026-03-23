//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_KNAPSACK_01_H
#define ALGORITHMS_KNAPSACK_01_H

#include <vector>
#include <iostream>

// 0/1 Knapsack: each item taken at most once
// Returns maximum value achievable within given capacity
// dp[i][w] = max value using first i items with capacity w
int knapsack01(const std::vector<int>& val, const std::vector<int>& wt, int capacity) {
    int n = val.size();
    // space-optimised: single 1D array
    std::vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; ++i) {
        // iterate backwards to avoid using item i twice
        for (int w = capacity; w >= wt[i]; --w) {
            dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[capacity];
}

// Also returns which items were selected (requires full 2D table)
std::pair<int, std::vector<int>> knapsack01WithItems(
        const std::vector<int>& val, const std::vector<int>& wt, int capacity) {
    int n = val.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i)
        for (int w = 0; w <= capacity; ++w) {
            dp[i][w] = dp[i-1][w];
            if (wt[i-1] <= w)
                dp[i][w] = std::max(dp[i][w], dp[i-1][w - wt[i-1]] + val[i-1]);
        }

    // trace back selected items
    std::vector<int> items;
    int w = capacity;
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i-1][w]) {
            items.push_back(i - 1);
            w -= wt[i-1];
        }
    }
    return {dp[n][capacity], items};
}

void demoKnapsack01() {
    std::vector<int> val = {60, 100, 120};
    std::vector<int> wt  = {10,  20,  30};
    int capacity = 50;

    auto [maxVal, items] = knapsack01WithItems(val, wt, capacity);
    std::cout << "0/1 Knapsack max value: " << maxVal << "\nItems taken (0-indexed): ";
    for (int i : items) std::cout << i << " ";
    std::cout << std::endl;
}

#endif //ALGORITHMS_KNAPSACK_01_H
