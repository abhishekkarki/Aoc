#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <string>
#include <set>

void parseFile(const std::string& filename, std::vector<std::string>& grid) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Cannot open the file: " << filename << std::endl;
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

char turnRight(char direction) {
    if (direction == '^') return '>';
    if (direction == '>') return 'v';
    if (direction == 'v') return '<';
    if (direction == '<') return '^';
    return direction;
}

bool detectCycle(const std::vector<std::string>& grid, int obstructionRow, int obstructionCol) {
    std::vector<std::string> testGrid = grid;
    testGrid[obstructionRow][obstructionCol] = '#';

    auto [row, col] = startingPosition(testGrid, '^');
    char direction = '^';

    std::set<std::tuple<int, int, char>> visitedStates;

    while (true) {
        auto state = std::make_tuple(row, col, direction);
        if (visitedStates.count(state)) {
            return true; // Loop detected
        }
        visitedStates.insert(state);

        int newRow = row, newCol = col;
        if (direction == '^') newRow--;
        else if (direction == 'v') newRow++;
        else if (direction == '>') newCol++;
        else if (direction == '<') newCol--;

        if (newRow < 0 || newRow >= (int)testGrid.size() || newCol < 0 || newCol >= (int)testGrid[0].size()) {
            break; // Guard leaves the grid
        }

        char nextCell = testGrid[newRow][newCol];
        if (nextCell == '#') {
            direction = turnRight(direction); // Turn right at an obstacle
        } else {
            row = newRow;
            col = newCol;
        }
    }

    return false;
}

bool isReachable(const std::vector<std::string>& grid, int startRow, int startCol, int row, int col) {
    return row >= 0 && row < (int)grid.size() &&
           col >= 0 && col < (int)grid[row].size() &&
           grid[row][col] == '.' &&
           !(row == startRow && col == startCol); // Avoid starting position
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Provide the input file in the command line" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::vector<std::string> grid;
    parseFile(filename, grid);

    auto [startRow, startCol] = startingPosition(grid, '^');
    if (startRow == -1) {
        std::cerr << "No starting position found!" << std::endl;
        return 1;
    }

    std::cout << "Parsed grid and starting position found: (" << startRow << ", " << startCol << ")" << std::endl;

    int obstructionCount = 0;
    for (int row = 0; row < (int)grid.size(); ++row) {
        for (int col = 0; col < (int)grid[row].size(); ++col) {
            if (isReachable(grid, startRow, startCol, row, col)) {
                if (detectCycle(grid, row, col)) {
                    obstructionCount++;
                }
            }
        }
    }

    std::cout << "Number of positions where an obstruction causes a loop: " << obstructionCount << std::endl;
    return 0;
}