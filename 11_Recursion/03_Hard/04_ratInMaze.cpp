➡️ problemLinks --> https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

✅ Brute Force -->  class Solution {
    public:
        solve(int i, int j, vector<vector<int>>& maze, int n, vector<string>& ans, string move, vector<vector<int>>& vis){
            if(i = n-1 && j = n-1){
                ans.push_back(move);
                return;
            }
            //Downward
            if()
        }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0)); //outer vector<...>(n, ...)creates n rows, inner vector<int>(n, 0)each row has n columns, all filled with 0
        if(maze[0][0] == 1) solve(0, 0, maze, n, ans, "", vis); //rat starts at row=0, col=0, current path string (empty at start)
        return ans;
    }
};

✅ Optimized Approach --> class Solution {
    public:
        void solve(int i, int j, vector<vector<int>>& maze, int n, vector<string>& ans, string move, vector<vector<int>>& vis){
            if(i == n-1 && j == n-1){
                ans.push_back(move);
                return;
            }
            // direction arrays (D, L, R, U) - sorted alphabetically ✅
            int di[] = {1, 0, 0, -1}; // row change
            int dj[] = {0, -1, 1, 0}; // col change
            string dir = "DLRU";
            for(int indx = 0; indx < 4 ; indx++){
                int nextI = i + di[indx];
                int nextJ = j + dj[indx];
                if(nextI >= 0 && nextJ >= 0 && nextI < n && nextJ < n && !vis[nextI][nextJ] && maze[nextI][nextJ] == 1){
                  vis[i][j] = 1;
                  solve(nextI,nextJ,maze,n,ans,move + dir[indx],vis);
                  vis[i][j] = 0;
                }
                
            }
        }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0)); //outer vector<...>(n, ...)creates n rows, inner vector<int>(n, 0)each row has n columns, all filled with 0
        if(maze[0][0] == 1) solve(0, 0, maze, n, ans, "", vis); //rat starts at row=0, col=0, current path string (empty at start)
        return ans;
    }
};

✅ Company Tags -->  Amazon Microsoft