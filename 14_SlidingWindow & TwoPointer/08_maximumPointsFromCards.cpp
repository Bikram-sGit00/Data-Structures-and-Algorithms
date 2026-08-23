➡️ problemLinks --> https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/  &&  https://www.geeksforgeeks.org/problems/maximum-point-you-can-obtain-from-cards/1

✅ Brute Force --> 
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = 0;

        // Try every possible number of cards taken from the left
        for(int leftCnt = 0; leftCnt <= k; leftCnt++) {

            int sum = 0;

            // Take leftCnt cards from the left
            for(int i = 0; i < leftCnt; i++) {
                sum += nums[i];
            }

            // Take remaining cards from the right
            int rightCnt = k - leftCnt;

            for(int i = 0; i < rightCnt; i++) {
                sum += nums[n - 1 - i];
            }

            // Store the maximum score among all possibilities
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

Time Complexity : O(k^2)    

Space Complexity : O(1)

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  