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

int trap(std::vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0;
    int water = 0;

    //until rights does not meet left
    while (left < right) {
        //if right is higher that left
        if (height[left] < height[right]) {
            if (height[left] >= left_max)
                left_max = height[left];
            else
                water += left_max - height[left];
            left++;
            //if left is higher than or equal to right
        } else {
            if (height[right] >= right_max)
                right_max = height[right];
            else
                water += right_max - height[right];
            right--;
        }
    }

    return water;
}

void printBuildingsHeights(vector<int> buildingsHeights) {
    int maxHeight = 0;
    for (int i = 0; i < buildingsHeights.size(); i++) {
        if (maxHeight < buildingsHeights[i]) {
            maxHeight = buildingsHeights[i];
        }
    }
    vector<vector<char>> buildings(buildingsHeights.size(), vector<char>(maxHeight));
    for (int i = 0; i < buildingsHeights.size(); i++) {
        for (int j = buildings[i].size()-1; j > -1; j--) {
            if (j < buildingsHeights[i]) {
                buildings.at(j).at(i) = '#';
            }
            else {
                buildings.at(j).at(i) = '0';
            }
        }
    }

    for (int i = buildingsHeights.size() - 1; i > -1; i--) {
        for (int j = 0; j < buildings.at(i).size(); j++) {
            cout << buildings.at(i).at(j) << "";
        }
        cout << endl;
    }

}
void demoTrappingRainWater() {
    //vector<int> buildingsHeights = {2, 4, 6, 5, 3};
    vector<int> buildingsHeights = {6, 2, 4, 2, 4, 6};
    vector<int> buildingsHeights2 = {6, 2, 4, 7, 2, 4, 1, 2, 6, 6, 2, 4, 3, 7, 2, 4, 6, 6, 2, 4, 2, 4, 6 };
    printBuildingsHeights(buildingsHeights2);
    return;
    cout << trap(buildingsHeights) << '\n';
    return;
    //printBuildingsHeights(buildingsHeights);
    int testsCount;
    cin >> testsCount;
    for (int i = 0; i < testsCount; i++) {
        int N;
        cin >> N;
        vector<int> buildingsHeights;
        for (int i = 0; i < N; i++) {
            int currentHeight;
            cin >> currentHeight;
            buildingsHeights.push_back(currentHeight);
        }
        //trapping_rain_water(N, buildingsHeights);
        cout << trap(buildingsHeights) << '\n';
    }
}
#endif //ALGORITHMS_TRAPPING_RAIN_WATER_H