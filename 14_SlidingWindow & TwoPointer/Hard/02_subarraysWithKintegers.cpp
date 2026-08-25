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

Space Complexity : O(k), at worst case the unordered_map can store k distinct elements.


✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  