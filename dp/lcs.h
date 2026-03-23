//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_LCS_H
#define ALGORITHMS_LCS_H

#include <vector>
#include <string>
#include <iostream>

// Longest Common Subsequence
// Returns length and the actual LCS string
std::pair<int, std::string> lcs(const std::string& a, const std::string& b) {
    int m = a.size(), n = b.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }

    // reconstruct
    std::string result;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) { result += a[i-1]; --i; --j; }
        else if (dp[i-1][j] > dp[i][j-1]) --i;
        else --j;
    }
    std::reverse(result.begin(), result.end());
    return {dp[m][n], result};
}

void demoLCS() {
    std::string a = "ABCBDAB", b = "BDCAB";
    auto [len, seq] = lcs(a, b);
    std::cout << "LCS of \"" << a << "\" and \"" << b << "\": \""
              << seq << "\" (length " << len << ")\n";
}

#endif //ALGORITHMS_LCS_H
