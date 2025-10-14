➡️ problemLinks --> https://leetcode.com/problems/find-peak-element/

✅ Brute Force -->  Iterate through the array and check if the current element is greater than its neighbors.

✅ Optimized Approach --> class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n - 2;
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            if(nums[mid]>nums[mid-1]){
              low=mid+1;
            }
            else{
              high=mid-1;
            }
        }
        return -1;
    }
};

✅ Company Tags -->  Accolite Amazon Visa Adobe Google