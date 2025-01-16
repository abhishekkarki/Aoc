#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(); // Number of rows
    int n = grid[0].size(); // Number of columns
    queue<pair<int, int>> q; // Queue to hold positions of rotten oranges
    int freshCount = 0; // Count of fresh oranges

    // Directions for 4-neighbor traversal (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Step 1: Initialize the queue with all rotten oranges and count fresh oranges
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                ++freshCount;
            }
        }
    }

    // If there are no fresh oranges, return 0
    if (freshCount == 0) return 0;

    int minutes = 0;

    // Step 2: Perform BFS to rot adjacent fresh oranges
    while (!q.empty()) {
        int size = q.size();
        bool rotted = false;

        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // Check if the new cell is within bounds and has a fresh orange
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2; // Mark as rotten
                    q.push({nx, ny}); // Add to queue
                    --freshCount; // Decrease fresh orange count
                    rotted = true;
                }
            }
        }

        // If we rotted any oranges in this iteration, increment the time
        if (rotted) ++minutes;
    }

    // Step 3: Check if there are any fresh oranges left
    return freshCount == 0 ? minutes : -1;
}
