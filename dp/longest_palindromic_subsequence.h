//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_LONGEST_PALINDROMIC_SUBSEQUENCE_H
#define ALGORITHMS_LONGEST_PALINDROMIC_SUBSEQUENCE_H

#include <vector>
#include <string>
#include <iostream>

// Longest Palindromic Subsequence
// dp[i][j] = length of LPS in s[i..j]
int longestPalindromicSubsequence(const std::string& s) {
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) dp[i][i] = 1;

    for (int len = 2; len <= n; ++len)
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = (len == 2) ? 2 : dp[i+1][j-1] + 2;
            else
                dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
        }
    return dp[0][n-1];
}

// Longest Palindromic Substring (different: contiguous)
// Returns the substring
std::string longestPalindromicSubstring(const std::string& s) {
    int n = s.size(), start = 0, maxLen = 1;
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

    for (int i = 0; i < n; ++i) dp[i][i] = true;
    for (int i = 0; i < n - 1; ++i)
        if (s[i] == s[i+1]) { dp[i][i+1] = true; start = i; maxLen = 2; }

    for (int len = 3; len <= n; ++len)
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                if (len > maxLen) { start = i; maxLen = len; }
            }
        }
    return s.substr(start, maxLen);
}

void demoLPS() {
    std::string s = "bbbab";
    std::cout << "Longest palindromic subsequence of \"" << s << "\": "
              << longestPalindromicSubsequence(s) << "\n";

    std::string t = "babad";
    std::cout << "Longest palindromic substring of \"" << t << "\": \""
              << longestPalindromicSubstring(t) << "\"\n";
}

#endif //ALGORITHMS_LONGEST_PALINDROMIC_SUBSEQUENCE_H
