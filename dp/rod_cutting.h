//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_ROD_CUTTING_H
#define ALGORITHMS_ROD_CUTTING_H

#include <vector>
#include <iostream>

// Rod cutting: given prices[i] = price of rod of length i+1,
// find max revenue from cutting rod of length n
// dp[j] = max revenue for rod of length j
int rodCutting(const std::vector<int>& prices, int n) {
    std::vector<int> dp(n + 1, 0);
    for (int j = 1; j <= n; ++j)
        for (int cut = 1; cut <= j; ++cut)
            dp[j] = std::max(dp[j], prices[cut - 1] + dp[j - cut]);
    return dp[n];
}

// Also returns the cuts made
std::pair<int, std::vector<int>> rodCuttingWithCuts(const std::vector<int>& prices, int n) {
    std::vector<int> dp(n + 1, 0), cutAt(n + 1, 0);
    for (int j = 1; j <= n; ++j)
        for (int cut = 1; cut <= j; ++cut)
            if (prices[cut - 1] + dp[j - cut] > dp[j]) {
                dp[j] = prices[cut - 1] + dp[j - cut];
                cutAt[j] = cut;
            }

    std::vector<int> cuts;
    while (n > 0) { cuts.push_back(cutAt[n]); n -= cutAt[n]; }
    return {dp[n + (int)(cuts.empty() ? 0 : 0)], cuts}; // dp already final
}

void demoRodCutting() {
    std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    // Recompute properly
    std::vector<int> dp(n + 1, 0), cutAt(n + 1, 0);
    for (int j = 1; j <= n; ++j)
        for (int cut = 1; cut <= j; ++cut)
            if (prices[cut - 1] + dp[j - cut] > dp[j]) {
                dp[j] = prices[cut - 1] + dp[j - cut];
                cutAt[j] = cut;
            }

    std::vector<int> cuts;
    int rem = n;
    while (rem > 0) { cuts.push_back(cutAt[rem]); rem -= cutAt[rem]; }

    std::cout << "Rod cutting (n=" << n << ") max revenue: " << dp[n] << "\nCuts: ";
    for (int c : cuts) std::cout << c << " ";
    std::cout << std::endl;
}

#endif //ALGORITHMS_ROD_CUTTING_H
