/*
* N Queens probelm using recursion and backtracking
*/

#include <iostream>
#include <vector>
#include <string>

// Check if placing a queen at (row, col) is safe
bool isSafe(const std::vector<std::string>& board, int row, int col, int n) {
    // Check the current column for a queen
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Check the left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check the right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

// Backtracking function to solve the N-Queens problem
void nQueens(std::vector<std::string>& board, int row, int n, std::vector<std::vector<std::string>>& ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q'; // Place a queen
            nQueens(board, row + 1, n, ans); // Recurse to the next row
            board[row][j] = '.'; // Backtrack
        }
    }
}

int main() {
    int n = 4; // Size of the board (number of queens)
    std::vector<std::string> board(n, std::string(n, '.')); // Initialize board with '.'
    std::vector<std::vector<std::string>> ans;

    nQueens(board, 0, n, ans);

    // Print all solutions
    for (const auto& solution : ans) {
        for (const auto& row : solution) {
            std::cout << row << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}