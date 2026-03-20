➡️ problemLinks --> https://leetcode.com/problems/word-search/  &&  https://www.geeksforgeeks.org/problems/word-search/1

✅ Optimized Approach --> class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == word.size()) return true;  // matched all chars
        
        // out of bounds or mismatch or already visited
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() 
            || board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';  // mark visited

        bool found = dfs(board, word, i+1, j, k+1) ||
                     dfs(board, word, i-1, j, k+1) ||
                     dfs(board, word, i, j+1, k+1) ||
                     dfs(board, word, i, j-1, k+1);

        board[i][j] = temp;  // backtrack (restore)
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (dfs(board, word, i, j, 0)) return true;
        return false;
    }
};

// Time Complexity: O(M × N × 4^L) — L = word length 
// Space Complexity: O(L) for recursion stack in worst case

**Dry run on a small example:**
```
Grid:          Word: "SEE"
A B C E
S F C S
A D E E

Start DFS from every 'S':
→ Found 'S' at (1,0) → look for 'E' in neighbors → none match
→ Found 'S' at (1,3) → look for 'E' at (2,3) ✓ → look for 'E' at (2,2) ✓ → return true

✅ Company Tags --> Amazon Microsoft Intuit Apple NPCI
