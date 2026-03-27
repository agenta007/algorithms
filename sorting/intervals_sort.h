//
// Created by neo on 3/27/26.
//

#ifndef ALGORITHMS_INTERVALS_SORT_H
#define ALGORITHMS_INTERVALS_SORT_H
//
// Created by neo on 3/5/26.
//

#include <iostream>
#include <stdint.h>
#include <vector>
#include <bits/ostream.tcc>
using namespace std;
//interval=(max-min)/n
//2 4 6 8 12, sum=30, n=5, 12-2=10, 10/5=2
//5 10 15, sum=30, n=3, 15-5=10, 10/3=5
//random order
//-100 -200 -300 0 -400 100  sum=-900,6 n= 100-400=-300, -300/6=-50
void intervals_sort(vector<int> vec) {
    int max = INT32_MAX;
    int min = INT32_MIN;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > max)
            max = vec[i];
        if (vec[i] < min)
            min = vec[i];
    }
    cout << "max=" << max << "min=" << endl;
    int interval = (max - min) / vec.size();
    cout << interval << endl;
}
#endif //ALGORITHMS_INTERVALS_SORT_H