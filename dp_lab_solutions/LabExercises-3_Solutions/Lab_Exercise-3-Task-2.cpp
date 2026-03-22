#include <bits/stdc++.h>

using namespace std;

void print(vector < int > a, int n) {
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

// global dp array, size as per constraint, here n<=100000
int arr[100001];

// recursive solution
int findmax(int n) {
  if (n <= 1)
    return n;

  int p = findmax(n / 2) + findmax(n / 3) + findmax(n / 4);

  return n > p ? n : p;
}

int main() {
  int t, n, item;

  // precompute the dp array
  arr[0] = 0;
  arr[1] = 1;

  for (int i = 2; i <= 100000; i++) {
    int p = arr[i / 4] + arr[i / 3] + arr[i / 2];
    arr[i] = i > p ? i : p;
  }

  cout << "Number of testcase:\n";
  scanf("%d", & t);

  for (int i = 0; i < t; i++) {

    cout << "Enter n\n";
    scanf("%d", & n);

    cout << "Maximum sum is: " << arr[n] << endl;
    // cout<<findmax(n)<<endl;
    // if you want to check recursive one and have
    // a long day to check for large n
  }

  return 0;
}
