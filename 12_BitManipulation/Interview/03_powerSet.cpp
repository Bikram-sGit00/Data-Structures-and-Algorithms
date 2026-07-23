➡️ problemLinks --> 

✅ Optimized Approach --> class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;      // Stores all subsets

        int n = nums.size();

        int subset = 1 << n;          // Total subsets = 2^n

        // Try every binary number from 0 to 2^n - 1
        for (int i = 0; i <= subset - 1; i++) {

            vector<int> list;         // Current subset

            // Check every bit
            for (int j = 0; j <= n - 1; j++) {

                // If j-th bit is ON, include nums[j]
                if (i & (1 << j))
                    list.push_back(nums[j]);
            }

            // Store the current subset
            ans.push_back(list);
        }

        return ans;
    }
};

// Time Complexity : O(n * 2^n) , where n is the size of the input array
// Space Complexity : O(n * 2^n) , where n is the size of the input array

✅ Company Tags -->  