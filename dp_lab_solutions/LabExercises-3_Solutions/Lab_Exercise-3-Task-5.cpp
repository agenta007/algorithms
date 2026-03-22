#include <bits/stdc++.h>
using namespace std;

int findmax(vector<int> arr, int in, int n, int* lastindex)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max && i != in) {
            max = arr[i];
            *lastindex = i;
        }
    }
    return max;
}

int recurZigZag(vector<vector<int> > arr, int row, int col, int n, int** dp)
{
    //memoization part
    if (dp[row][col] != -1) //if already solved, no need to compute again
        return dp[row][col];

    if (row == n - 1) {
        dp[row][col] = arr[row][col];
        return arr[row][col];
    }
    int max = INT_MIN;
    for (int k = 0; k < n; k++) {
        if (k != col) {
            int t = recurZigZag(arr, row + 1, k, n, dp);
            if (max < t)
                max = t;
        }
    }
    dp[row][col] = std::max(dp[row][col], arr[row][col] + max); //store solution
    return dp[row][col];
}

int main()
{
    int t, n, item;

    cout << "Enter test case:\n";
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Input size of square matrix\n";
        cin >> n;

        vector<vector<int> > arr;

        cout << "Input the square matrix\n";
        for (int i = 0; i < n; i++) {
            vector<int> inn;
            for (int j = 0; j < n; j++) {
                cin >> item;
                inn.push_back(item);
            }
            arr.push_back(inn);
        }

        int** dp = (int**)(malloc(sizeof(int*) * n));

        for (int i = 0; i < n; i++) {
            dp[i] = (int*)(malloc(sizeof(int) * n));
            for (int j = 0; j < n; j++)
                dp[i][j] = -1;
        }

        int mymax = INT_MIN;

        for (int i = 0; i < n; i++) {
            int p = recurZigZag(arr, 0, i, n, dp);
            if (p > mymax)
                mymax = p;
        }

        cout << "Maximum zigzag sum: " << mymax << endl;
    }

    return 0;
}
