//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_ACTIVITY_SELECTION_H
#define ALGORITHMS_ACTIVITY_SELECTION_H

#include <vector>
#include <algorithm>
#include <iostream>

struct Activity {
    int start, end, idx;
};

// Select maximum number of non-overlapping activities
// sorted by finish time (greedy choice)
std::vector<Activity> activitySelection(std::vector<Activity> acts) {
    std::sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
        return a.end < b.end;
    });

    std::vector<Activity> selected;
    int lastEnd = -1;

    for (const Activity& a : acts) {
        if (a.start >= lastEnd) {
            selected.push_back(a);
            lastEnd = a.end;
        }
    }
    return selected;
}

void demoActivitySelection() {
    // {start, end, index}
    std::vector<Activity> acts = {
        {1,4,0},{3,5,1},{0,6,2},{5,7,3},{3,9,4},{5,9,5},{6,10,6},{8,11,7},{8,12,8},{2,14,9},{12,16,10}
    };
    auto sel = activitySelection(acts);
    std::cout << "Activity selection (" << sel.size() << " activities): ";
    for (auto& a : sel)
        std::cout << "[" << a.start << "," << a.end << "] ";
    std::cout << std::endl;
}

#endif //ALGORITHMS_ACTIVITY_SELECTION_H
