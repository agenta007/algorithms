//
// Created by neo on 3/28/26.
//

#ifndef ALGORITHMS_TWO_NUMBER_SUM_H
#define ALGORITHMS_TWO_NUMBER_SUM_H
#include <vector>
#include <hash_map>
using namespace std;
//check if any pair of distinct integers sums up to a target value
bool twoNumberSum(vector<int> &vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (i==j)
                continue;
            if (vec[i]+vec[j] == target)
                return true;
        }
    }
    return false;
}

bool twoNumberSumHashTable(vector<int> &vec, int target) {

}

void demoTwoNumberSum() {
    vector<int> vec = {3, 5, -4, 8, 11, 1, -1, 6};
    cout << twoNumberSum(vec, 10) << endl;
}
#endif //ALGORITHMS_TWO_NUMBER_SUM_H