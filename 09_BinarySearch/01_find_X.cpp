➡️ problemLinks --> https://leetcode.com/problems/binary-search/

✅ Iterative Approach --> int binarySearch(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            ans = mid;        // store index   (can also return directly if don't want to use extra variable)
            high = mid - 1;   // move left to find smallest index
        }
        else if (arr[mid] > k) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

// Time Complexity --> O(logN)
// Space Complexity --> O(1)

✅ Company Tags -->  Infosys Oracle Wipro Linkedin Qualcomm TCS Cognizant Accenture
