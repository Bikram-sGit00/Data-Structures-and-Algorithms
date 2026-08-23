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


✅ Optimized Approach --> class Solution { 
public: 
    int maxScore(vector<int>& nums, int k) { 
        int n = nums.size(); 
        int leftSum = 0; 
        int rightSum = 0; 
        int maxSum = 0; 

        for(int i = 0; i < k ; i++){ 
            leftSum += nums[i]; // Sum of the first k cards from the left
            maxSum = leftSum; // Initially, take all k cards from the left
        } 

        int rightIndx = n - 1; 

        for(int i = k - 1; i >= 0; i--){ 
            leftSum -= nums[i]; // Remove one card from the left
            rightSum += nums[rightIndx]; // Add one card from the right
            rightIndx--; // Move to the next card from the right
            maxSum = max(maxSum, leftSum + rightSum); 
        } 

        return maxSum;
    } 
};

Time Complexity : O(2 x k)

Space Complexity : O(1)

✅ Company Tags -->  