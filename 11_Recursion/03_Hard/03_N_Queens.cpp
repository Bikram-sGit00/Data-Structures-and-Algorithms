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
        vector<string> board(n); // 
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


✅ Optimized Approach --> class Solution {
public:
    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               vector<int>& leftRow, vector<int>& lowerDiag,
               vector<int>& upperDiag, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiag[row + col] == 0 &&
                upperDiag[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;

                solve(col + 1, board, ans, leftRow, lowerDiag, upperDiag, n);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;
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
        vector<int> leftRow(n, 0), lowerDiag(2 * n - 1, 0),
            upperDiag(2 * n - 1, 0);
        solve(0, board, ans, leftRow, lowerDiag, upperDiag, n);
        return ans;
    }
};

// Overall TC → O(N!)
// Overall SC → O(N²) (excluding output)
// Board → O(N²)
// Additional space for tracking constraints → O(N)

