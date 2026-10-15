➡️ problemLinks --> https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/?envType=daily-question&envId=2026-10-15

✅ Optimized Approach --> class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        
        // Fix the starting index of each subarray.
        for(int i = 0; i < nums.size(); i++){
            // Store distinct elements for subarrays starting at i.
            unordered_set<int> unique;

            // Extend the subarray by moving the ending index j.
            for(int j = i; j < nums.size(); j++){
                // Insert the current element; duplicates are stored only once.
                unique.insert(nums[j]);

                // Add the square of the distinct element count for this subarray.
                ans += unique.size() * unique.size();
            }
        }

        // Return the sum of squared distinct counts of all subarrays.
        return ans;
    }
};

Time Complexity : O(n^2)

Space Complexity : O(n)

✅ Company Tags -->  