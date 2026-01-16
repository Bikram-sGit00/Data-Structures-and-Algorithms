➡️ problemLinks --> https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

✅ Optimized Approach --> int upperBound(vector<int>& arr, int target, int n) {
    // int n = arr.size();
    int low = 0, high = n - 1, ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>>& mat, int n, int m, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += upperBound(mat[i], x, m);
    }
    return cnt;
}

class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int low = INT_MAX, high = INT_MIN;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }
        int req = (n * m) / 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(mat, n, m, mid);
            if (smallEqual <= req)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};

// Time Complexity --> (log 10^9 *n * log m)

// Time Complexity: O(rows × log(max - min) × log(cols)), Binary search runs on the value space from min to max of the matrix and for each mid in binary search, we count how many numbers are less than or equal to mid
// Space Complexity: O(1), constant extra space is used.


✅ Company Tags -->  