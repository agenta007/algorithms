//
// Created by neo on 3/23/26.
//
#ifndef ALGORITHMS_KNIGHT_STEPS_H
#define ALGORITHMS_KNIGHT_STEPS_H

#include <vector>
#include <queue>

using namespace std;

class knight_steps {
public:
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        // All 8 possible knight moves
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        // Convert to 0-indexed
        int sx = KnightPos[0] - 1, sy = KnightPos[1] - 1;
        int tx = TargetPos[0] - 1, ty = TargetPos[1] - 1;

        if (sx == tx && sy == ty) return 0;

        vector<vector<bool>> visited(N, vector<bool>(N, false));
        queue<pair<int, int>> q;

        q.push({sx, sy});
        visited[sx][sy] = true;
        int steps = 0;

        while (!q.empty()) {
            steps++;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (int j = 0; j < 8; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if (nx == tx && ny == ty) return steps;

                    if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;  // unreachable
    }
};

#endif