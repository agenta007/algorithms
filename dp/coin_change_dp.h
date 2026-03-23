//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_COIN_CHANGE_DP_H
#define ALGORITHMS_COIN_CHANGE_DP_H

#include <vector>
#include <algorithm>
#include <iostream>

const int COIN_INF = 1e9;

// Minimum number of coins to make amount (DP, exact solution)
// Returns -1 if impossible
int coinChangeMin(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, COIN_INF);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
        for (int c : coins)
            if (c <= i && dp[i - c] + 1 < dp[i])
                dp[i] = dp[i - c] + 1;
    return dp[amount] == COIN_INF ? -1 : dp[amount];
}

// Number of ways to make amount (coin change combinations)
long long coinChangeWays(const std::vector<int>& coins, int amount) {
    std::vector<long long> dp(amount + 1, 0);
    dp[0] = 1;
    for (int c : coins)
        for (int i = c; i <= amount; ++i)
            dp[i] += dp[i - c];
    return dp[amount];
}

void demoCoinChangeDP() {
    std::vector<int> coins = {1, 5, 6, 9};
    int amount = 11;
    std::cout << "Min coins for " << amount << ": " << coinChangeMin(coins, amount) << "\n";
    std::cout << "Ways to make " << amount << ": "  << coinChangeWays(coins, amount) << "\n";
}

#endif //ALGORITHMS_COIN_CHANGE_DP_H
