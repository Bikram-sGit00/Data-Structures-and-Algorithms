➡️ problemLinks --> https://leetcode.com/problems/kth-missing-positive-number/ && https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1

✅ Brute Force --> class MissingKFinder {
public:
    // Function to find the k-th missing number
    int missingK(vector<int> vec, int n, int k) {
        for (int i = 0; i < n; i++) {
            if (vec[i] <= k) {
                k++;  // If current number is less than or equal to k, increment k
            } else {
                break; // Stop when we reach a number greater than k
            }
        }
        return k;  // Return the final value of k which is the missing number
    }
};

// Time Complexity --> O(N)
// Space Complexity --> O(1)

✅ Optimized Approach --> class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int missCount = arr[mid] - (mid + 1); // count of missing numbers
            if (missCount < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // return k+high+1;
        return low + k;
    }
};

// Time Complexity --> O(log N)
// Space Complexity --> O(1)

