➡️ problemLinks --> https://leetcode.com/problems/jump-game-ii/description/  &&  https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

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


🚀 My Way of Writing this Code --> class Solution {
public:
    int jump(vector<int>& nums) {
        // If there is only one element, we are already at the destination. 
        if(nums.size() <= 1) return 0;

        int jump = 0;       // Number of jumps taken so far.
        int canReach = 0;  // Farthest index we can reach from the current range.
        int currEnd = 0;   // End of the range reachable using the current number of jumps.

        for(int i = 0; i < nums.size(); i++){

            // If the current index is beyond our reachable range,
            // then we can never reach this index or anything after it.
            if(i > canReach) return -1;

            // From all indices we have scanned so far,
            // find the farthest index we can reach with the NEXT jump.
            canReach = max(canReach, i + nums[i]);

            // We have reached the end of the current jump's range.
            // So now we must take one more jump to reach the next range.
            if(i == currEnd){
                jump++;
                currEnd = canReach;
            }

            // If the current jump can already reach or cross the last index,
            // we don't need any more jumps, so return the answer immediately.
            if(currEnd >= nums.size() - 1) return jump;
        }

        // If the last index could not be reached.
        return -1;
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