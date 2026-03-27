//
// Created by neo on 3/27/26.
//

#ifndef ALGORITHMS_TRAPPING_RAIN_WATER_H
#define ALGORITHMS_TRAPPING_RAIN_WATER_H
#include <iostream>
#include <vector>
using namespace std;
int trapping_rain_water(int n, vector<int> buildingsHeights) {

}

void demoTrappingRainWater() {
    int testsCount;
    cin >> testsCount;
    for (int i = 0; i < testsCount; i++) {
        int N;
        cin >> N;
        trapping_rain_water(N);
        vector<int> buildingsHeights;
        for (int i = 0; i < N; i++) {
            cin >> buildingsHeights[i];
        }
        trapping_rain_water(N, buildingsHeights);
    }
}
#endif //ALGORITHMS_TRAPPING_RAIN_WATER_H