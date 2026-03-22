//
// Created by neo on 3/16/26.
//

#ifndef FRACTIONAL_KNAPSACK_H
#define FRACTIONAL_KNAPSACK_H
#include <algorithm>
#include <vector>

#include "../helpers.h"
#include "../sorting/binary_insertion_sort.h"
using namespace std;
double fractionalKnapsack_(int n, double weights[], double values[], double capacity) {
    vector<double> ratios;
    for (int i = 0; i < n; i++) {
        ratios.push_back(values[i] / weights[i]);
    }
    sort(ratios.begin(), ratios.end(), std::greater<double>());
    for (int i = 0; i < n; i++) {

    }

}

//a and b are 2 items
bool compare(vector<int>& a, vector<int>& b) {
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];
    return a1 > b1;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    //values = {60, 100, 120};
    //weights = {10, 20, 30};
    // Create 2D vector to store value and weight
    // items[i][0] = value, items[i][1] = weight
    //create a vector of two vectors
    vector<vector<int>> items(n, vector<int>(2));

    //0->value, 1->weight
    for (int i = 0; i < n; i++) {
        items[i][0] = val[i];
        items[i][1] = wt[i];
    }
    printVector(items[0]);
    // Sort items based on value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    double res = 0.0;
    int currentCapacity = capacity;

    // Process items in sorted order
    for (int i = 0; i < n; i++) {

        // If we can take the entire item
        if (items[i][1] <= currentCapacity) {
            res += items[i][0];
            currentCapacity -= items[i][1];
        }

        // Otherwise take a fraction of the item
        else {
            res += (1.0 * items[i][0] / items[i][1]) * currentCapacity;

            // Knapsack is full
            break;
        }
    }

    return res;
}
#endif //FRACTIONAL_KNAPSACK_H
