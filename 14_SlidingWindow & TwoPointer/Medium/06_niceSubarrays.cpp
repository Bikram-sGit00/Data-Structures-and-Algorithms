➡️ problemLinks --> https://leetcode.com/problems/count-number-of-nice-subarrays/  &&  https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1

✅ Optimized Approach --> class Solution {
public:
    int helper(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0;
        int result = 0;
        int windowSum = 0;
        for(int r  = 0; r < n; r++){
            windowSum += nums[r] % 2; // if even then store 0, and if odd so 1;
            while(windowSum > k){
                windowSum -= nums[l] % 2; 
                l++;
            }
            result += r - l + 1;
        }
        return result;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};

Time Complexity : O(2N)

Space Complexity : O(1)

✅ Company Tags -->  