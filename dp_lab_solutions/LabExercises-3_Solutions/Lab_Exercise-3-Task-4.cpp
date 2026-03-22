#include <bits/stdc++.h>
using namespace std;

int max(int a, int b, int c)
{

    if (a > b && a > c)
        return a;
    if (b > c)
        return b;
    return c;
}

int LCS3(string s1, string s2, string s3, int m, int n, int o)
{

    int dp[m + 1][n + 1][o + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j][0] = 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= o; j++) {
            dp[0][i][j] = 0;
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= o; j++) {
            dp[i][0][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= o; k++) {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                }
                else {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]);
                }
            }
        }
    }
    return dp[m][n][o];
}

int main()
{
    int t, m, n, o;

    cout << "enter length of three strings respectively\n";
    cin >> m >> n >> o;

    cout << "enter the three strings respectively\n";
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << "length of LCS of the three is : " << LCS3(s1, s2, s3, m, n, o) << endl;

    return 0;
}
