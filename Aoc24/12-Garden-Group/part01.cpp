#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

void parseInput(const std::string& filename, std::vector<std::string>& grid) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file " << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        grid.push_back(line);
    }
    inputFile.close();
}

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Helper function to check if a cell is within the grid bounds
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Helper function for DFS to calculate area and perimeter of a region
void dfs(const std::vector<std::string>& grid, std::vector<std::vector<bool>>& visited,
         int x, int y, char currentChar, int& area, int& perimeter) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Directions for neighbors: up, down, left, right
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Mark the current cell as visited and increment the area
    visited[x][y] = true;
    area++;

    // Explore all neighbors
    for (auto [dx, dy] : directions) {
        int newX = x + dx;
        int newY = y + dy;

        // If the neighbor is out of bounds or a different character, count as perimeter
        if (!isValid(newX, newY, rows, cols) || grid[newX][newY] != currentChar) {
            perimeter++;
        } else if (!visited[newX][newY]) {
            // If the neighbor is part of the same region and unvisited, recurse
            dfs(grid, visited, newX, newY, currentChar, area, perimeter);
        }
    }
}

// Function to calculate the total region cost
int calculateRegionCost(const std::vector<std::string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Create a visited grid to keep track of which cells have been processed
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    // Variable to store the total region cost
    int totalCost = 0;

    // Iterate through all cells in the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // If the cell is unvisited, start a new region
            if (!visited[i][j]) {
                char currentChar = grid[i][j];
                int area = 0;
                int perimeter = 0;

                // Calculate the area and perimeter of the region using DFS
                dfs(grid, visited, i, j, currentChar, area, perimeter);

                // Add the cost of this region to the total cost
                int regionCost = area * perimeter;
                totalCost += regionCost;
            }
        }
    }

    return totalCost;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "please provide the input file " << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::vector<std::string> grid;

    parseInput(filename, grid);

    // printing the grid for debigging
    for (const auto& row : grid) {
            std::cout << row << " ";
    }
    std::cout << std::endl;

   int totalCost = calculateRegionCost(grid);

    std::cout << "Total Region Cost: " << totalCost << "\n";
    return 0;
  

    
}









