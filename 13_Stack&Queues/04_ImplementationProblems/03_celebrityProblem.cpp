➡️ problemLinks --> https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

✅ Brute Force -->  class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> knows(n, 0);       // knows[i] = number of people i knows
        vector<int> knownBy(n, 0);     // knownBy[i] = number of people who know i

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    knows[i]++;       // i knows j
                    knownBy[j]++;     // j is known by i
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(knows[i] == 0 && knownBy[i] == n - 1)
                return i; // i knows nobody and everybody knows i
        }

        return -1; // no celebrity exists
    }
};

Time Complexity : O(n^2) --> for traversing the matrix
Space Complexity : O(2n) --> for storing the knows and knownBy arrays


✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  Zoho Flipkart Amazon Microsoft Google Fab.com One97 UnitedHealthGroup NPCI