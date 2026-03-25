//
// Created by neo on 3/25/26.
//

#ifndef ALGORITHMS_DISTANCE_OF_NEAREST_1_IN_BINARY_GRID_H
#define ALGORITHMS_DISTANCE_OF_NEAREST_1_IN_BINARY_GRID_H
#include <queue>
using namespace std;
#include <vector>
#include <queue>
//Step 0:  All 1s are in the queue (distance 0)
//Step 1:  Their neighbors get distance 1 → pushed to queue
//Step 2:  THOSE cells' neighbors get distance 2 → pushed to queue
//...and so on
vector<vector<int>> find_nearest_1_distances(vector<vector<int>> &binary_grid) {
    int rows = binary_grid.size();
    int cols = binary_grid[0].size();
    vector<vector<int>> distances(rows, vector<int>(cols, -1));
    queue<pair<int, int>> queue;

    //find all 1s set distance to 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (binary_grid[i][j] == 1) {
                distances[i][j] = 0;
                queue.push({i, j});
            }
        }
    }

    //4 possible movies, 4 directions are possible
    //4 moves are (-1,0), (1,0), (0,-1) (0,1)
    //0-> up, 1-> down, 2-> left, 3-> right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    //from all 1s start bfs to find nearest 0s
    while (!queue.empty()) {
        //take x and y from pair at the front
        auto [x, y] = queue.front();
        queue.pop();
        //xy has only 4 neighbors
        for (int d = 0; d < 4; d++) {
            //get value neighbor on row
            int nx = x + dx[d];
            //get value of neighbor on column
            int ny = y + dy[d];
            //if in bounds and if distances[nx][ny] == -1 then we have a 0 in the col
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && distances[nx][ny] == -1) {
                distances[nx][ny] = distances[x][y] + 1;
                queue.push({nx, ny});
            }
        }
    }
    return distances;
}
void demoBinaryGridDistances() {
    std::vector<std::vector<int>> binary_grid_3_4 = {
        {1, 0, 0, 1},
        {0, 0, 1, 1},
        {1, 1, 0, 0}
    };
    std::vector<std::vector<int>> binary_grid_5_5 = {
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0}
    };
    auto distances = find_nearest_1_distances(binary_grid_5_5);
    printVectorOfVectors(distances);
}
#endif //ALGORITHMS_DISTANCE_OF_NEAREST_1_IN_BINARY_GRID_H