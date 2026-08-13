➡️ problemLinks --> https://leetcode.com/problems/sliding-window-maximum/  &&  https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

✅ Brute Force -->  

Time Complexity : 

Space Complexity : 

✅ Optimized Approach --> class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // remove elements which are outside the window
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();

            // remove smaller elements from back
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            dq.push_back(i); // store index of current element

            // i entered formation zone
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

Time Complexity : O(2N)

Space Complexity : O(k) + O(N-k)

✅ Company Tags -->  Flipkart Amazon Microsoft Directi Google NPCI
