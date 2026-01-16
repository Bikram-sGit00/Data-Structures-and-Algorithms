➡️ problemLinks --> https://leetcode.com/problems/find-a-peak-element-ii/description/  && 

✅ Optimized Approach --> int findMax(vector<vector<int>>& mat, int n, int m, int col) {
    int maxi = -1;
    int indx = -1;
    for (int i = 0; i < n; i++) {
        if (mat[i][col] > maxi) {
            maxi = mat[i][col];
            indx = i;
        }
    }
    return indx;
}

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size(); // columns
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int maxRowIndx = findMax(mat, n, m, mid);
            int left = mid - 1 >= 0 ? mat[maxRowIndx][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxRowIndx][mid + 1] : -1;
            if (mat[maxRowIndx][mid] > left && mat[maxRowIndx][mid] > right) {
                return {maxRowIndx, mid};
            } else if (mat[maxRowIndx][mid] > left) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
}; 

// Time Complexity --> O(log m * n) or O(n log m)
// Space Complexity --> O(1)

✅ Company Tags -->  