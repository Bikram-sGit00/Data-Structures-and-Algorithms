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

✅ Optimized Approach --> class Solution {
public:
    int jump(vector<int>& nums) {

        int l = 0;       // Start of the current range of indices.
        int r = 0;       // End of the current range of indices.
        int jumps = 0;   // Number of jumps taken so far.

        // Continue until the current range can reach the last index.
        while(r < nums.size() - 1){

            int farthest = 0;   // Store the farthest index we can reach
                                // using one more jump from the current range.

            // Check every index inside the current range.
            // From each index, calculate how far we can jump.
            for(int i = l; i <= r; i++){
                farthest = max(i + nums[i], farthest);
            }

            // The current range is finished.
            // The next range will start just after 'r'
            // and will end at the farthest index we found.
            l = r + 1;
            r = farthest;

            // Moving from the current range to the next range
            // requires one more jump.
            jumps++;
        }

        // Minimum number of jumps needed to reach the last index.
        return jumps;
    }
};
                
Time Complexity : O(n) , where n is the length of the input array nums

Space Complexity : O(1)

✅ Company Tags -->  Amazon — Asked count: Unknown — Time period: Unknown
Google — Asked count: Unknown — Time period: Unknown
Microsoft — Asked count: Unknown — Time period: Unknown
Apple — Asked count: Unknown — Time period: Unknown
Adobe — Asked count: Unknown — Time period: Unknown
Bloomberg — Asked count: Unknown — Time period: Unknown
Meta — Asked count: Unknown — Time period: Unknown