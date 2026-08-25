➡️ problemLinks --> https://leetcode.com/problems/subarrays-with-k-different-integers/  && https://www.geeksforgeeks.org/problems/subarrays-with-k-different-integers/1 

✅ Brute Force -->  class Solution { 
public: 
    int subarraysWithKDistinct(vector<int>& nums, int k) { 
        int n = nums.size(); 
        int subarrayCnt = 0; 
 
        for(int i = 0; i < n; i++){ 
            unordered_map<int, int> mpp; // Stores frequency of elements in current subarray
 
            for(int j = i; j < n; j++){ 
                mpp[nums[j]]++; // Add current element
 
                if(mpp.size() == k){ 
                    subarrayCnt++; // Found a subarray with exactly k distinct elements
                } 
                else if(mpp.size() > k){ 
                    break; // More than k distinct, so further expansion is useless
                } 
            } 
        } 
 
        return subarrayCnt; 
    } 
};

Time Complexity : O(n^2)

Space Complexity : O(N), at worst case the unordered_map can store k distinct elements.


✅ Optimized Approach --> class Solution { 
public: 
    int helper(vector<int>& nums, int k){ 
        int n = nums.size(); 
        int l = 0; 
        int subarrayCnt = 0; 
        unordered_map<int, int> mpp; // Stores frequency of each element in the window

        for(int r = 0; r < n; r++){ 
            mpp[nums[r]]++; // Add current element to the window

            // Shrink the window until it has at most k distinct elements
            while(mpp.size() > k){ 
                mpp[nums[l]]--; // Remove the leftmost element
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]); // Remove it from the map if its frequency becomes 0
                l++; // Move left pointer forward
            } 
            // All subarrays ending at r and starting from l to r are valid
            subarrayCnt += r - l + 1; 
        } 
        return subarrayCnt; 
    } 

    int subarraysWithKDistinct(vector<int>& nums, int k) { 
        return helper(nums, k) - helper(nums, k - 1); 
    } 
};

Time Complexity : O(2 x 2N) = O(N)
Space Complexity : O(N)

✅ Company Tags -->  