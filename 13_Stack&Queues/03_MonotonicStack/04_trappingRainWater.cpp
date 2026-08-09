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

✅ Better Approach --> class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int total = 0;

        vector<int> leftMax(arr.size());
        vector<int> rightMax(arr.size());

        // 🚀 Left skyline: carry the highest wall seen so far
        leftMax[0] = arr[0];

        // ⚠️ Start from 1 — index 0 is already initialized
        for (int i = 1; i < arr.size(); i++) {
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }

        // 🚀 Right skyline: carry the highest wall from the right
        rightMax[n - 1] = arr[n - 1];

        // ⚠️ Start from n-2 — last index is already initialized
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

        // 💧 Smaller boundary decides how much water survives
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < leftMax[i] && arr[i] < rightMax[i]) {
                total += min(leftMax[i], rightMax[i]) - arr[i];
            }
        }

        return total;
    }
};

Time Complexity : O(3N) ~ O(N)
Space Complexity : O(2N) ~ O(N)


✅ Optimized Approach --> class Solution {
public:
int trap(vector<int>& height) {
int n = height.size();
int l = 0;
int r = n - 1;
int leftMax = 0;
int rightMax = height[n-1];
int totalWater = 0;

    // 🚀 Two pointers scan inward from both boundaries
    while(l < r){
        // 🧠 Process the side with the smaller current boundary
        if(height[l] <= height[r]){
            // 💧 Existing left wall traps water
            if(leftMax > height[l]) totalWater += (leftMax - height[l]);
            
            // 🧱 New highest left wall found
            else leftMax = height[l];
            
            l++;
        }
        else{
            // 💧 Existing right wall traps water
            if(rightMax > height[r]) totalWater += (rightMax - height[r]);
            
            // 🧱 New highest right wall found
            else rightMax = height[r];
            
            r--;
        }
    }
    return totalWater;
    }
};

Time Complexity :  O(n)
Space Complexity :  O(1)

✅ Company Tags -->  Flipkart Amazon Microsoft Google GoldmanSachs Adobe