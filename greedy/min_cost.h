//
// Created by neo on 3/16/26.
//

#ifndef MIN_COST_H
#define MIN_COST_H
#include <vector>

int minCost(std::vector<int>& a)
{
    // Minimum cost is (size - 1) multiplied with minimum element.
    int n = a.size();
    return (n - 1) * (*min_element(a.begin(), a.end()));
    //posledniq index po minimalniq element
}
#endif //MIN_COST_H
