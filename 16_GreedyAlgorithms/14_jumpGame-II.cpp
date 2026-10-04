➡️ problemLinks --> https://leetcode.com/problems/jump-game-ii/description/  &&

✅ Brute Force -->  

Time Complexity : 

Space Complexity : 

✅ Better Approach --> class Solution {
    int n;
    vector<int> memo;

    int solver(int indx, vector<int>& nums){
        // If we reach/cross the last index, no more jumps are needed.
        if(indx >= n - 1) return 0;

        // Already calculated this index → directly reuse the answer.
        if(memo[indx] != -1) return memo[indx];

        int mini = INT_MAX;

        // Try every possible jump from the current index.
        for(int i = 1; i <= nums[indx]; i++){

            // Find the minimum jumps needed after making this jump.
            int jumps = solver(indx + i, nums);

            // Ignore paths that cannot reach the last index.
            if(jumps != INT_MAX){
                mini = min(mini, jumps + 1);
            }
        }

        // Store the minimum answer for this index before returning it.
        return memo[indx] = mini; 
    }
    
public:
    int jump(vector<int>& nums) {
        n = nums.size();

        // -1 means this index has not been calculated yet.
        memo.resize(nums.size(), -1);

        // Start from index 0.
        return solver(0, nums);
    }
};

Time Complexity : O(n^2) , where n is the length of the input array nums

Space Complexity : O(n) + O(n) = O(n) , memorization array + recursion stack space

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  Amazon — Asked count: Unknown — Time period: Unknown
Google — Asked count: Unknown — Time period: Unknown
Microsoft — Asked count: Unknown — Time period: Unknown
Apple — Asked count: Unknown — Time period: Unknown
Adobe — Asked count: Unknown — Time period: Unknown
Bloomberg — Asked count: Unknown — Time period: Unknown
Meta — Asked count: Unknown — Time period: Unknown