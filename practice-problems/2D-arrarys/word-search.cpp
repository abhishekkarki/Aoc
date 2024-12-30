class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if (index == word.size()) {
            return true;
        }
        
        // boundary check and character match
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        // Mark the cell as visited by modifying it
        char temp = board[i][j];
        board[i][j] = '#';

        // explore all four possible directions
        bool found = dfs(board, word, index + 1, i + 1, j) || // down
                     dfs(board, word, index + 1, i - 1, j) || // up
                     dfs(board, word, index + 1, i, j + 1) || // right
                     dfs(board, word, index + 1, i, j - 1);   // left

        // backtrack by restoring the original value
        board[i][j] = temp;
        
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true; // word found
                }
            }
        }
        return false; // word not found
    }
};