#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

void parseFile(const std::string& filename, std::vector<std::string>& grid) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Cannot open the file ! " << filename << std::endl; 
        exit(1);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        grid.push_back(line);
    }
    inputFile.close();
}

std::pair<int, int> startingPosition(const std::vector<std::string>& grid, char symbol) {
    for (int row = 0; row < (int)grid.size(); ++row) {
        int col = (int)grid[row].find(symbol);
        if (col != (int)std::string::npos) {
            return {row, col};
        }
    }
    return {-1, -1};
}

// Helper to turn right
char turnRight(char direction) {
    // direction cycle: ^ > v <
    if (direction == '^') return '>';
    if (direction == '>') return 'v';
    if (direction == 'v') return '<';
    if (direction == '<') return '^';
    return direction; // fallback
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Provide the input file in the command line" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::vector<std::string> grid;
    parseFile(filename, grid);

    char symbol = '^';  // or determine from input if needed
    auto currentPoint = startingPosition(grid, symbol);
    if (currentPoint.first == -1) {
        std::cerr << "No starting symbol found!" << std::endl;
        return 1;
    }

    int row = currentPoint.first;
    int col = currentPoint.second;

    int endRow = (int)grid.size();
    int endCol = (int)grid[0].size();

    // The guard moves until leaving the area
    // Protocol:
    // If obstacle ahead, turn right. Otherwise move forward.

    while (row >= 0 && row < endRow && col >= 0 && col < endCol) {
        char dir = grid[row][col]; 
        int newRow = row;
        int newCol = col;
        
        // Determine the cell in front of the guard based on direction
        if (dir == '^')      { newRow = row - 1; newCol = col;   }
        else if (dir == 'v') { newRow = row + 1; newCol = col;   }
        else if (dir == '>') { newRow = row;     newCol = col+1; }
        else if (dir == '<') { newRow = row;     newCol = col-1; }
        else {
            // If the cell isn't a direction arrow, break or handle error
            break;
        }

        // Check if next cell is within bounds; if not, guard leaves area
        if (newRow < 0 || newRow >= endRow || newCol < 0 || newCol >= endCol) {
            // Mark current position as visited before leaving
            grid[row][col] = 'X'; 
            break; 
        }

        // Check what is ahead
        char nextCell = grid[newRow][newCol];

        if (nextCell == '#' ) {
            // Obstacle: turn right
            grid[row][col] = turnRight(dir);
        } else {
            // Move forward
            // Mark old position as visited
            grid[row][col] = 'X';
            // Move to new position
            row = newRow;
            col = newCol;
            // Keep the same direction
            // If the new cell was '.', place the direction symbol there
            // If the puzzle requires leaving the direction symbol, do so:
            if (nextCell == '.' || nextCell == 'X')
                grid[row][col] = dir;
        }
    }

    // Print final grid state
    for (auto &item : grid) {
        std::cout << item << "\n";
    }

    int countX = 0;
    for (auto &rowStr : grid) {
        for (auto ch : rowStr) {
            if (ch == 'X') countX++;
        }
    }

    std::cout << "Total number of X: " << countX << std::endl;
    return 0;
}