➡️ problemLinks --> https://leetcode.com/problems/search-a-2d-matrix/

✅ Optimized Approach --> class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = (n * m) - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;a
    }
};

✅ Company Tags -->  Paytm Accolite Amazon Microsoft Snapdeal MakeMyTrip OlaCabs Oracle Visa GoldmanSachs Directi Adobe SAPLabs Groupon InMobi One97 Polycom TinyOwl