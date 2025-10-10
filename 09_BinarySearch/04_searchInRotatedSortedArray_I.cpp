➡️ problemLinks --> https://leetcode.com/problems/search-in-rotated-sorted-array/description/

✅ Brute Force --> class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }
};
// Time Complexity --> O(N)
// Space Complexity --> O(1)

✅ Optimized Approach --> class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            // if mid points the target
            if (arr[mid] == target)
                return mid;

            if (arr[low] <= arr[mid]) {
                if (arr[low] <= target && target <= arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (arr[mid] <= target && target <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Time Complexity --> O(logN)
// Space Complexity --> O(1)

✅ Company Tags -->   Paytm Flipkart Amazon Microsoft Snapdeal D-E-Shaw FactSet Hike MakeMyTrip Intuit Adobe Google BankBazaar Times Internet