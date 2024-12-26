#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Function to check if the X-MAS pattern exists at a given center (row, col)
bool isXMAS(const vector<string> &grid, int row, int col, int rows, int cols) {
    // Check bounds for diagonals (top-left to bottom-right and top-right to bottom-left)
    if (row - 1 < 0 || row + 1 >= rows || col - 1 < 0 || col + 1 >= cols) {
        return false; // Out of bounds
    }

    // Top-left to bottom-right diagonal
    string diag1 = {grid[row - 1][col - 1], grid[row][col], grid[row + 1][col + 1]};
    // Top-right to bottom-left diagonal
    string diag2 = {grid[row - 1][col + 1], grid[row][col], grid[row + 1][col - 1]};

    // Check if both diagonals form MAS or SAM
    return ((diag1 == "MAS" || diag1 == "SAM") && (diag2 == "MAS" || diag2 == "SAM"));
}

// Function to count all X-MAS patterns in the grid
int countXMASPatterns(const vector<string> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    // Traverse each cell as the potential center of an X-MAS pattern
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] == 'A' && isXMAS(grid, row, col, rows, cols)) {
                count++;
            }
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Please provide the input file as an argument." << endl;
        return 1;
    }

    // Read the input grid from the file
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    vector<string> grid;
    string line;

    while (getline(inputFile, line)) {
        grid.push_back(line);
    }
    inputFile.close();

    /*
    // Debug: Print the grid
    cout << "Grid:" << endl;
    for (const auto &row : grid) {
        cout << row << endl;
    }
    */

    int result = countXMASPatterns(grid);
    cout << "The X-MAS pattern appears " << result << " times in the grid." << endl;

    return 0;
}