➡️ problemLinks --> https://leetcode.com/problems/max-consecutive-ones-iii/  &&  https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1

✅ Brute Force -->  class Solution { 
public: 
    int longestOnes(vector<int>& nums, int k) { 
        int n = nums.size(); 
        int maxLen = 0; 
        for (int i = 0; i < n; i++) { 
            int zeroCnt = 0;                  // count zeros in current subarray
            for (int j = i; j < n; j++){ 
                if(nums[j] == 0) zeroCnt++;   // increase zero count if current element is 0
                if(zeroCnt <= k){             // valid window if zeros <= k
                    int len = j - i + 1;      // calculate current subarray length
                    maxLen = max(maxLen, len); // update maximum length
                } 
                else break;                   // stop if zeros exceed k
            } 
        } 
        return maxLen;                        // return longest valid subarray
    } 
}; 

Time Complexity : O(n^2)
Space Complexity : O(1)

✅ Better Approach --> class Solution { 
public: 
    int longestOnes(vector<int>& nums, int k) { 
        int n = nums.size(); 
        int l = 0;                  // left pointer of the window
        int maxLen = 0;             // stores maximum valid window length
        int zeroCnt = 0;            // counts zeros in the current window

        for (int r = 0; r < n; r++) {   
            if (nums[r] == 0) zeroCnt++; // include nums[r] in the window

            while (zeroCnt > k) { // shrink until window becomes valid
                if (nums[l] == 0) zeroCnt--; // remove zero when l moves and l == 0
                l++; // move left pointer forward
            }
            // if (zeroCnt <= k) {
            //     int len = r - l + 1;
            //     maxLen = max(maxLen, len);
            // } // No need of this as while() is already completed 

            int len = r - l + 1; // calculate current valid window length
            maxLen = max(maxLen, len); // update maximum length
        } 

        return maxLen; 
    } 
};

Time Complexity : O(2N)
Space Complexity : O(1)

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  Accolite Amazon Microsoft MakeMyTrip OlaCabs