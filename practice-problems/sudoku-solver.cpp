/*
* Sudoku Solver
* Time: O(9^empty_places)
* Space: O(1)
*/

#include <iostream>
#include <vector>

// Function to check if placing `dig` at (row, col) is safe
bool isSafe(std::vector<std::vector<char>>& board, int row, int col, char dig) {
    // Check the row and column
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == dig || board[i][col] == dig) {
            return false;
        }
    }

    // Check the 3x3 subgrid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            if (board[i][j] == dig) {
                return false;
            }
        }
    }

    return true;
}

// Backtracking function to solve the Sudoku
bool solver(std::vector<std::vector<char>>& board, int row, int col) {
    // If we reach beyond the last row, the Sudoku is solved
    if (row == 9) {
        return true;
    }

    // Calculate the next cell position
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    // If the cell is already filled, move to the next cell
    if (board[row][col] != '.') {
        return solver(board, nextRow, nextCol);
    }

    // Try placing digits from '1' to '9'
    for (char dig = '1'; dig <= '9'; ++dig) {
        if (isSafe(board, row, col, dig)) {
            board[row][col] = dig; // Place the digit
            if (solver(board, nextRow, nextCol)) {
                return true; // If the next recursion solves the board, return true
            }
            board[row][col] = '.'; // Backtrack
        }
    }

    return false; // If no digit can be placed, return false
}

int main() {
    // Initialize the Sudoku board
    std::vector<std::vector<char>> board = {
        {'2', '.', '.', '.', '.', '1', '4', '.', '.'},
        {'7', '.', '.', '.', '9', '.', '.', '.', '.'},
        {'.', '3', '.', '.', '5', '6', '.', '.', '2'},
        {'.', '7', '.', '2', '1', '8', '5', '.', '6'},
        {'1', '.', '2', '.', '.', '5', '9', '3', '.'},
        {'.', '6', '.', '.', '.', '9', '.', '.', '.'},
        {'6', '.', '.', '.', '8', '.', '.', '.', '.'},
        {'9', '.', '.', '5', '.', '3', '8', '.', '.'},
        {'4', '1', '8', '.', '2', '.', '.', '6', '5'}
    };

    // Print the initial board
    std::cout << "Initial Sudoku Board:" << std::endl;
    for (const auto& row : board) {
        for (char val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Solve the Sudoku
    if (solver(board, 0, 0)) {
        std::cout << "\nSolved Sudoku Board:" << std::endl;
        for (const auto& row : board) {
            for (char val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "\nNo solution exists for the given Sudoku board." << std::endl;
    }

    return 0;
}