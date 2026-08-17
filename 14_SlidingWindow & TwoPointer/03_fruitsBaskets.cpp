➡️ problemLinks --> https://leetcode.com/problems/fruit-into-baskets/  && https://www.geeksforgeeks.org/problems/longest-subarray-with-atmost-two-distinct-integers/1

✅ Brute Force -->  class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;                         // Stores the maximum valid subarray length

        for (int i = 0; i < n; i++) {
            set<int> fruitSet;                 // Stores distinct fruit types in current window

            for (int j = i; j < n; j++) {
                fruitSet.insert(fruits[j]);    // Add current fruit type

                if (fruitSet.size() <= 2) {
                    int len = j - i + 1;       // Calculate current window length
                    maxLen = max(maxLen, len); // Update maximum length
                } 
                else
                    break;                     // More than 2 fruit types → stop this window
            }
        }

        return maxLen;                         // Return longest valid window
    }
};

Time Complexity : O(n^2)  --> Two nested loops, where n is the number of fruits.
Space Complexity : O(n)  --> The set can store up to n distinct fruit types in the worst case.

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  