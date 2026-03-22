//
// Created by neo on 3/15/26.
//
#include <vector>
#include <algorithm>

#ifndef MINIMUM_NUMBER_OF_COINS_H
#define MINIMUM_NUMBER_OF_COINS_H
std::vector<int> coinChange(int n, std::vector<int>& coins) {
    std::sort(coins.begin(), coins.end(), std::greater<int>()); // Sort in descending order
    std::vector<int> coins_in_hand;

    for (int coin : coins) {
        while (n - coin >= 0) {
            coins_in_hand.push_back(coin);
            n -= coin;
        }
    }

    return coins_in_hand;
}
#endif //MINIMUM_NUMBER_OF_COINS_H
