#include <bits/stdc++.h>
using namespace std;

int find_length(int* arr, int n)
{
    int up[n];
    int down[n];

    for (int i = 0; i < n; i++) {
        up[i] = 1;
        down[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                up[i] = max(up[i], down[j] + 1);
            }
            else if (arr[i] < arr[j]) {
                down[i] = max(down[i], up[j] + 1);
            }
        }
    }

    int m = 0;

    for (int i = 0; i < n; i++) {
        m = max(m, max(up[i], down[i]));
    }

    return m;
}

int main()
{
    //code
    int t;

    cout << "Testcase : ";
    cin >> t;

    while (t--) {
        int n;

        cout << "Enter the element number : ";
        cin >> n;

        int arr[n];

        cout << "Fill the array : ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Length of the subsequence : " << find_length(arr, n) << endl;
    }

    return 0;
}
