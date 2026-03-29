//
// Created by neo on 3/28/26.
//

#ifndef ALGORITHMS_TASK_BIND_H
#define ALGORITHMS_TASK_BIND_H
#include <algorithm>
#include <iostream>
using namespace std;
#include <vector>
#include <stack>
//using Task = pair<int, int>;
struct Task {
    int start, end;
};
struct Schedule {
    stack<Task> jamie;
    stack<Task> cameron;
};
//using Schedule = pair<stack<Task>, stack<Task>>;

//a schedule is for two person only therefore two stacks
Schedule craftSchedule(vector<Task> &tasks){
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
    return a.start < b.start;
});
    Schedule schedule;
    /*
    1 100 jamie
    2 5
    99 150
    100 301
    150 250
     */
    for (int i = 0; i < tasks.size(); i++) {
        if (schedule.jamie.empty()) {
            schedule.jamie.push(tasks[i]);
            continue;
        }
        if (!schedule.jamie.empty() && tasks[i].start >= schedule.jamie.top().end) {
            schedule.jamie.push(tasks[i]);
            continue;
        }
        if (schedule.cameron.empty()) {
            schedule.cameron.push(tasks[i]);
        }
        if (tasks[i].start >= schedule.cameron.top().end) {
            schedule.cameron.push(tasks[i]);
            continue;
        }
    }
    return schedule;
}

void printSchedule(Schedule &schedule, int caseNumber) {
    cout << "Case #" << caseNumber << " ";
    vector<pair<Task, char>> completeSchedule;
    for (int i = 0; i < schedule.jamie.size(); i++) {
        completeSchedule.push_back({schedule.jamie.top(),'J'});
    }
    for (int i = 0; i < schedule.cameron.size(); i++) {
        completeSchedule.push_back({schedule.cameron.top(), 'C'});
    }

    for (int i = 0; i < completeSchedule.size(); i++) {
        if (completeSchedule[i].second == 'J') {
            cout << 'J';
        }
        if (completeSchedule[i].second == 'C') {
            cout << 'C';
        }
    }
}
/*
1
5
99 150
1 100
100 301
2 5
150 250

*/
void demoTaskBind() {
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        int tasksCount;
        cin >> tasksCount;
        vector<Task> tasks;
        for (int j = 0; j < tasksCount; j++) {
            int start, end;
            cin >> start >> end;
            tasks.push_back(Task(start, end));
        }
        Schedule schedule = craftSchedule(tasks);
        printSchedule(schedule, i);
    }
}

#endif //ALGORITHMS_TASK_BIND_H