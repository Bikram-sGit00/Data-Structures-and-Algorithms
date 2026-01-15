➡️ problemLinks --> https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

✅ Optimized Approach --> int lowerBound(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1, ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt_max = 0;
        int indx = -1;
        for (int i = 0; i < n; i++) {
           int cnt_ones = m-lowerBound(mat[i], 1);
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                indx=i;
            }
        }
        return indx;
    }
};

✅ Company Tags -->  Amazon Microsoft Snapdeal