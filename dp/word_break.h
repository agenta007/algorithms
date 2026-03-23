//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_WORD_BREAK_H
#define ALGORITHMS_WORD_BREAK_H

#include <vector>
#include <string>
#include <unordered_set>
#include <functional>
#include <iostream>

// Word break: can s be segmented into words from the dictionary?
// dp[i] = true if s[0..i-1] can be segmented
bool wordBreak(const std::string& s, const std::vector<std::string>& dict) {
    std::unordered_set<std::string> wordSet(dict.begin(), dict.end());
    int n = s.size();
    std::vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
    return dp[n];
}

// Returns all valid segmentations
std::vector<std::string> wordBreakAll(const std::string& s, const std::vector<std::string>& dict) {
    std::unordered_set<std::string> wordSet(dict.begin(), dict.end());
    int n = s.size();
    // memo[i] = list of sentences for s[i..n-1]
    std::vector<std::vector<std::string>> memo(n + 1);
    std::vector<bool> computed(n + 1, false);

    std::function<std::vector<std::string>(int)> solve = [&](int start) -> std::vector<std::string> {
        if (computed[start]) return memo[start];
        computed[start] = true;
        if (start == n) { memo[start] = {""}; return memo[start]; }
        for (int end = start + 1; end <= n; ++end) {
            std::string word = s.substr(start, end - start);
            if (wordSet.count(word)) {
                for (const std::string& rest : solve(end)) {
                    memo[start].push_back(word + (rest.empty() ? "" : " " + rest));
                }
            }
        }
        return memo[start];
    };

    return solve(0);
}

void demoWordBreak() {
    std::string s = "catsanddog";
    std::vector<std::string> dict = {"cat","cats","and","sand","dog"};
    std::cout << "Word break \"" << s << "\": "
              << (wordBreak(s, dict) ? "YES" : "NO") << "\n";
    std::cout << "All segmentations:\n";
    for (auto& seg : wordBreakAll(s, dict))
        std::cout << "  " << seg << "\n";
}

#endif //ALGORITHMS_WORD_BREAK_H
