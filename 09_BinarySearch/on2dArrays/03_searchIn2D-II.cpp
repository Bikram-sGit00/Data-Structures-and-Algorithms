➡️ problemLinks --> https://leetcode.com/problems/search-a-2d-matrix-ii/  &&  https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

✅ Optimized Approach --> class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target)
                row++;
            else
                col--;
        }
        return false;
    }
};

// Time Complexity: O(N + M)
// Space Complexity: O(1)

✅ Company Tags -->  Paytm Accolite Amazon Microsoft Snapdeal MakeMyTrip OlaCabs Oracle Visa GoldmanSachs Directi Adobe SAPLabs Groupon InMobi One97 Polycom TinyOwl