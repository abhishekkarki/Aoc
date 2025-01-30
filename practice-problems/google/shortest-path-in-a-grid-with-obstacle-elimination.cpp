#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();

    // case: k is greater or equal to the number of obstacles
    if (m + n <= k) return m + n - 2;

    // for all four directions
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // Visited state: (row, col, remaining obstacle eliminations)
    vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));

    // BFS queue storing (x, y, steps, remaining obstacle eliminations)
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, k});  // Start at (0,0) with 0 steps taken and k removals available
    visited[0][0][k] = true;

    while (!q.empty()) {
        auto [x, y, steps, remaining_k] = q.front();
        q.pop();

        // If we reach the bottom-right corner, return the number of steps
        if (x == m - 1 && y == n - 1) return steps;

        // Explore all 4 directions
        for (auto [dx, dy] : directions) {
            int newX = x + dx, newY = y + dy;

            // Check if within bounds
            if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                int newK = remaining_k - grid[newX][newY];  // Deduct 1 if moving onto an obstacle
                
                // Only proceed if we have enough eliminations left
                if (newK >= 0 && !visited[newX][newY][newK]) {
                    visited[newX][newY][newK] = true;
                    q.push({newX, newY, steps + 1, newK});
                }
            }
        }
    }

    return -1;  // If no path found    


}

int main() {
    vector<vector<int>> list = {
         {0, 0, 0},
        {1, 1, 0},
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 0}
    };
    int k = 1;
    
    cout << "The shortest path is : " << shortestPath(list, k) << endl;

}