➡️ problemLinks --> https://leetcode.com/problems/binary-subarrays-with-sum/description/ && https://www.geeksforgeeks.org/problems/binary-subarray-with-sum/1

✅ Brute Force -->  

Time Complexity : 

Space Complexity : 

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

✅ Optimized Approach 1 (Recommended)--> class Solution {
public:
    int helper(vector<int>& nums, int goal){
        int n = nums.size();
        int l = 0;
        int windowSum = 0;
        int subArrayCnt = 0;
        if(goal < 0) return 0; // negative sum is impossible in a binary array

        for(int r = 0; r < n; r++){
            windowSum += nums[r]; // expand the window by absorbing nums[r]
            while(windowSum > goal){
                windowSum -= nums[l]; // eject nums[l] until the window becomes valid
                l++;
            }
            subArrayCnt += r - l + 1; // every start from l to r forms a valid subarray
        }
        return subArrayCnt; // total subarrays with sum <= goal
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1); // remove sums below goal, leaving exactly goal
    }
};

Time Complexity : O(2N)

Space Complexity : O(1)


✅ Optimized Approach 2 -->


✅ Company Tags -->