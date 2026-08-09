➡️ problemLinks --> https://leetcode.com/problems/trapping-rain-water/  &&  https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

✅ Brute Force -->  class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        for (int i = 0; i < n; i++) {

            int leftMax = 0;
            int rightMax = 0;

            // 🔍 Scan left → find the highest wall
            for (int j = 0; j < i; j++) {
                leftMax = max(leftMax, height[j]);
            }

            // 🔍 Scan right → find the highest wall
            for (int j = i + 1; j < n; j++) {
                rightMax = max(rightMax, height[j]);
            }

            // 💧 Water = smaller wall - current height
            totalWater += min(leftMax, rightMax) - height[i];
        }

        return totalWater;
    }
};

Time Complexity : O(n^2)

Space Complexity : O(1)

✅ Better Approach --> 

Time Complexity :  

Space Complexity :  

✅ Optimized Approach --> 

Time Complexity :  

Space Complexity :  

✅ Company Tags -->  Flipkart Amazon Microsoft Google GoldmanSachs Adobe