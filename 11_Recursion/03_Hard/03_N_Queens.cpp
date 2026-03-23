➡️ problemLinks --> https://leetcode.com/problems/n-queens/description/

✅ Brute Force -->  class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int dupRow = row;
        int dupCol = col;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        col = dupCol;
        row = dupRow;
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }
        col = dupCol;
        row = dupRow;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.'); // n size doted board
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};

// Overall TC → O(N! × N)
// O(N!) for state exploration
// O(N) for each isSafe() call

// Overall SC → O(N²) (excluding output)
// Board → O(N²)
// Recursion stack → O(N) depth
// Output storage → O(Solutions × N²)


✅ Optimized Approach --> 

✅ Company Tags -->  