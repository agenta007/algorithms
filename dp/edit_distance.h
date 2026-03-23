//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_EDIT_DISTANCE_H
#define ALGORITHMS_EDIT_DISTANCE_H

#include <vector>
#include <string>
#include <iostream>

// Edit distance (Levenshtein): min insert/delete/replace to turn a into b
// dp[i][j] = edit distance between a[0..i-1] and b[0..j-1]
int editDistance(const std::string& a, const std::string& b) {
    int m = a.size(), n = b.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + std::min({dp[i-1][j],    // delete
                                          dp[i][j-1],    // insert
                                          dp[i-1][j-1]}); // replace
        }
    return dp[m][n];
}

void demoEditDistance() {
    std::string a = "sunday", b = "saturday";
    std::cout << "Edit distance \"" << a << "\" -> \"" << b << "\": "
              << editDistance(a, b) << "\n";
    std::cout << "Edit distance \"kitten\" -> \"sitting\": "
              << editDistance("kitten", "sitting") << "\n";
}

#endif //ALGORITHMS_EDIT_DISTANCE_H
