➡️ problemLinks --> https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

✅ Brute Force -->  class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;  // Stores the length of the longest subarray with sum = 0

        // Try every possible subarray starting from index i
        for (int i = 0; i < n; i++) {
            int sum = 0;  // Reset sum for every new starting index i

            // Extend the subarray to index j
            for (int j = i; j < n; j++) {
                sum += nums[j];  // Add current element to sum

                if (sum == 0) {
                    // If sum becomes 0, update maxLen if this subarray is longer
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        // Return the maximum length found
        return maxLen;
    }
};
// Time Complexity: O(N^2) - due to nested loops
// Space Complexity: O(1) - no extra space used


✅ Optimized Approach --> class Solution {
public:
    int maxLength(vector<int>& nums) {
        // Hash map to store the first occurrence of each prefix sum
        unordered_map<int, int> mpp;

        int sum = 0;       // Running sum (prefix sum)
        int maxi = 0;      // Maximum length of subarray with sum = 0

        // Traverse through the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];  // Update the running sum

            if (sum == 0) {
                // If sum becomes 0, the subarray from index 0 to i has sum = 0
                maxi = i + 1;
            }
            else if (mpp.find(sum) != mpp.end()) {
                // If this sum has been seen before,
                // then the subarray between previous index + 1 to current index has sum = 0
                // Example: if sum was seen at index 2, and current index is 6,
                //          then subarray from index 3 to 6 has sum = 0
                maxi = max(maxi, i - mpp[sum]);
            }
            else {
                // Store the first occurrence of this prefix sum
                // Only store it the first time we see it to maximize the subarray length
                mpp[sum] = i;
            }
        }

        // Return the maximum length of subarray with sum = 0
        return maxi;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N) for the hash map
✅ Company Tags -->  Amazon Microsoft MakeMyTrip