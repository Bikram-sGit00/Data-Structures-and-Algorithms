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

// Time Complexity --> O(log base2^N) or O(log2(N))
// Space Complexity --> O(1)

✅ Recursive Approach --> int bs(vector<int>& nums, int low, int high, int target) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target) {
        return bs(nums, mid + 1, high, target);
    } else {
        return bs(nums, low, mid - 1, target);
    }
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
      return  bs(nums, 0, nums.size() - 1, target);
    }
};

// Time Complexity --> O(log base2^N) or O(log2(N))
// Space Complexity --> O(1)

✅ Company Tags -->  Infosys Oracle Wipro Linkedin Qualcomm TCS Cognizant Accenture
