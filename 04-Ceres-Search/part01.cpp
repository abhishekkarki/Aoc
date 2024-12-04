#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Directions for traversing the grid in 8 directions
const vector<pair<int, int>> directions = {
    {0, 1},   // Right
    {1, 0},   // Down
    {1, 1},   // Diagonal Down-Right
    {1, -1},  // Diagonal Down-Left
    {0, -1},  // Left
    {-1, 0},  // Up
    {-1, -1}, // Diagonal Up-Left
    {-1, 1}   // Diagonal Up-Right
};

// Function to check if the word fits starting from a specific cell in a specific direction
bool searchInDirection(const vector<string> &grid, int row, int col, const string &word, int dx, int dy, int rows, int cols) {
    int wordLen = word.length();
    for (int i = 0; i < wordLen; i++) {
        int newRow = row + i * dx;
        int newCol = col + i * dy;

        // Check if out of bounds
        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
            return false;
        }

        // Check if character matches
        if (grid[newRow][newCol] != word[i]) {
            return false;
        }
    }
    return true;
}

// Function to count occurrences of the word
int countWordOccurrences(const vector<string> &grid, const string &word) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    // Traverse each cell in the grid
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] == word[0]) { // First character matches
                // Check all 8 directions
                for (auto [dx, dy] : directions) {
                    if (searchInDirection(grid, row, col, word, dx, dy, rows, cols)) {
                        count++;
                    }
                }
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

    string word = "XMAS";
/*
    // Debug: Print the grid
    cout << "Grid:" << endl;
    for (const auto &row : grid) {
        cout << row << endl;
    }
*/
    int result = countWordOccurrences(grid, word);
    cout << "The word " << word << " appears " << result << " times in the grid." << endl;

    return 0;
}