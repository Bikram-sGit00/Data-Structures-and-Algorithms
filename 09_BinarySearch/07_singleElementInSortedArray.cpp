➡️ problemLinks --> https://leetcode.com/problems/single-element-in-a-sorted-array/  &&  https://www.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1

✅ Brute Force -->  

✅ Optimized Approach --> class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n - 2;
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0]; // if first element is answer
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1]; // if last element is answer
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];
            // We are in left
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1; // eleminate left half
            } else {
                high = mid - 1;
            }
        }
        return -1; // dummy statement
    }
};

✅ Company Tags -->  Amazon D-E-Shaw Ola Cabs