➡️ problemLinks --> https://leetcode.com/problems/binary-subarrays-with-sum/description/ && https://www.geeksforgeeks.org/problems/binary-subarray-with-sum/1

✅ Brute Force -->  

Time Complexity : 

Space Complexity : 

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

✅ Optimized Approach 1 (Recommended) --> class Solution {
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


✅ Optimized Approach 2 --> class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = 0;
        int n = nums.size();
        int windowSum = 0;
        int zeroCnt = 0;
        int subArrayCnt = 0;

        for(int r = 0; r < n; r++){
            windowSum += nums[r]; // expand the window and update its sum
            while(l < r && (nums[l] == 0 || windowSum > goal)){
                if(nums[l] == 0) zeroCnt++; // count removable leading zeros that preserve the sum
                else zeroCnt = 0; // a '1' resets the chain of removable leading zeros
                windowSum -= nums[l]; // remove the leftmost element from the window
                l++; // advance the left boundary
            }
            if(windowSum == goal){
                subArrayCnt += 1 + zeroCnt; // count the original window plus zero-shifted windows
            }
        }
        return subArrayCnt; // total subarrays whose sum equals the goal
    }
};

Time Complexity : O(2N)

Space Complexity : O(1)

✅ Company Tags -->