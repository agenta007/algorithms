//
// Created by neo on 3/22/26.
//

#ifndef ALGORITHMS_JOB_SEQUENCING_H
#define ALGORITHMS_JOB_SEQUENCING_H

#include <vector>
#include <algorithm>
#include <iostream>

struct Job {
    int id, deadline, profit;
};

// Greedy job sequencing: maximize profit scheduling at most one job per slot
// Each job takes 1 unit of time and must finish by its deadline
std::vector<int> jobSequencing(std::vector<Job> jobs) {
    std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;
    for (auto& j : jobs) maxDeadline = std::max(maxDeadline, j.deadline);

    std::vector<int> slot(maxDeadline + 1, -1); // slot[t] = job id scheduled at time t
    std::vector<int> result;

    for (auto& j : jobs) {
        // Find latest free slot at or before deadline
        for (int t = j.deadline; t >= 1; --t) {
            if (slot[t] == -1) {
                slot[t] = j.id;
                result.push_back(j.id);
                break;
            }
        }
    }
    return result;
}

void demoJobSequencing() {
    std::vector<Job> jobs = {
        {1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,3,15}
    };
    auto scheduled = jobSequencing(jobs);
    int total = 0;
    std::cout << "Job sequencing scheduled jobs: ";
    for (int id : scheduled) {
        std::cout << id << " ";
        for (auto& j : jobs) if (j.id == id) total += j.profit;
    }
    std::cout << "\nTotal profit: " << total << std::endl;
}

#endif //ALGORITHMS_JOB_SEQUENCING_H
