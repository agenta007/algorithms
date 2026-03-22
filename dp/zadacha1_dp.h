//
// Created by neo on 3/15/26.
//

#ifndef ZADACHA1_DP_H
#define ZADACHA1_DP_H
#include <vector>

#include "../helpers.h"
using namespace std;
int minSquares(int n) {

    // minSquares(0) = 0
    if (n == 0)
        return 0;

    // n = 1*1 + 1*1 .... n times
    // so we can initialise count with n
    int cnt = n;

    // Go through all smaller numbers
    // to recursively find minimum
    for (int x = 1; x * x <= n; x++) {
        cnt = min(cnt, 1 + minSquares(n - x * x));
    }
    return cnt;
}
int min_square(int natural_number)
{
    int DP[natural_number + 1];
    //base value
    for (int i = 0; i <= natural_number; i++)
        DP[i] = i;
    //DP[0] = 0;

    //create the array of squares to be used to sum
    pmr::vector<int> squares;
    for (int i = 1;; i++) {
        if (i * i <= natural_number)
            squares.push_back(i * i);
        else
            break;
    }
    printArray(DP, natural_number+1);
    printVector(squares);
    int squares_sz = squares.size();
    for (int i = 1; i <= natural_number; i++) { //iterate for the numbers
        for (int j = 0; j < squares_sz; j++) { //iterate on the squares
            if (i >= squares[j] && DP[i - squares[j]] + 1 < DP[i]) {
                DP[i] = DP[i - squares[j]] + 1;
                printArray(DP, natural_number+1);
            }
        }
    }

    //result
    return DP[natural_number];
}
#endif //ZADACHA1_DP_H
