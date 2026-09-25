➡️ problemLinks --> https://leetcode.com/problems/jump-game/ &&  https://www.geeksforgeeks.org/problems/jump-game/1

✅ Optimized Approach --> class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canReach = 0; // will store the maximum we can reach
        for(int i = 0; i < nums.size(); i++){
            if(i > canReach) return false; // if while doing sum, we cross maximum reached point, means its invalid 
            canReach = max(canReach, i + nums[i]); // update maxReach
            if(canReach >= nums.size()) return true; // if maxReach crossing the array size so stop, we have reached, not necessery though as we just have to return true or false
        }
        return true;
    }
};

Time Complexity : O(n)

Space Complexity : O(1)

✅ Company Tags -->  Amazon - asked 9 times in the last 6 months
Google - asked 6 times in the last 6 months
Bloomberg - asked 5 times in the last 6 months
Meta - asked 4 times in the last 6 months
Infosys - asked 3 times in the last 6 months
Microsoft - asked 2 times in the last 6 months
Tom - asked 2 times in the last 6 months