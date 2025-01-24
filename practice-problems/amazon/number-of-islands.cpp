#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int numOfIsland = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // helper function for the bfs
        auto bfs = [&](int row, int col){
            queue<pair<int, int>> q;
            q.push({row, col});
            grid[row][col] = '0'; // mark as visited
            
            while (!q.empty()) {
                auto [currR, currC] = q.front();
                q.pop();

                // explore all four direction 
                for (auto [dr, dc] : directions) {
                    int newR = currR + dr;
                    int newC = currC + dc;

                    // check if new cell is valid and part of the island
                    if (newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] == '1') {
                        q.push({newR, newC});
                        grid[newR][newC] = '0';    // mark as visited
                    }
                }
            }

        };

        // iterating through the grid the find the islands
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    numOfIsland++;
                    bfs(i, j);
                }
            }
        }
        return numOfIsland;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Number of islands: " << solution.numIslands(grid) << endl;
    return 0;
}