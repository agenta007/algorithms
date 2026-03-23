//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_INTERVAL_PARTITIONING_H
#define ALGORITHMS_INTERVAL_PARTITIONING_H

#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

struct Interval {
    int start, end, idx;
};

// Interval partitioning: assign each interval to a "room" (resource)
// minimizing the number of rooms used (= max overlap at any point)
// Returns assignment[i] = room index for interval i
std::vector<int> intervalPartitioning(std::vector<Interval> intervals) {
    int n = intervals.size();
    std::vector<int> assignment(n);

    // sort by start time
    std::vector<int> order(n);
    for (int i = 0; i < n; ++i) order[i] = i;
    std::sort(order.begin(), order.end(), [&](int a, int b) {
        return intervals[a].start < intervals[b].start;
    });

    // min-heap: {end_time, room_id}
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>,
                        std::greater<std::pair<int,int>>> pq;
    int rooms = 0;

    for (int i : order) {
        if (!pq.empty() && pq.top().first <= intervals[i].start) {
            auto [endTime, room] = pq.top();
            pq.pop();
            assignment[i] = room;
            pq.push({intervals[i].end, room});
        } else {
            assignment[i] = rooms++;
            pq.push({intervals[i].end, assignment[i]});
        }
    }
    return assignment;
}

void demoIntervalPartitioning() {
    std::vector<Interval> intervals = {
        {0,30,0},{5,10,1},{15,20,2},{7,15,3},{20,35,4}
    };
    auto asgn = intervalPartitioning(intervals);
    int maxRoom = *std::max_element(asgn.begin(), asgn.end()) + 1;
    std::cout << "Interval partitioning (" << maxRoom << " rooms needed):\n";
    for (int i = 0; i < (int)intervals.size(); ++i)
        std::cout << "  [" << intervals[i].start << "," << intervals[i].end
                  << "] -> room " << asgn[i] << "\n";
}

#endif //ALGORITHMS_INTERVAL_PARTITIONING_H
