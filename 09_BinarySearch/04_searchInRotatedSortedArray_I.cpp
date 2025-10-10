➡️ problemLinks --> https://leetcode.com/problems/search-in-rotated-sorted-array/description/

✅ Brute Force --> class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }
};
// Time Complexity --> O(N)
// Space Complexity --> O(1)

✅ Optimized Approach --> 

✅ Company Tags -->   Paytm Flipkart Amazon Microsoft Snapdeal D-E-Shaw FactSet Hike MakeMyTrip Intuit Adobe Google BankBazaar Times Internet