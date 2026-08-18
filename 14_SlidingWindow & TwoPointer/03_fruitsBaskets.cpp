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

✅ Better Approach (Recommended) --> class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int maxLen = 0;

        unordered_map<int, int> mp;  // fruit -> frequency

        for (int r = 0; r < n; r++) {
            mp[fruits[r]]++;         // Add fruits[r] to the window

            while (mp.size() > 2) {  // More than 2 fruit types
                mp[fruits[l]]--;     // Remove fruits[l] from the window

                if (mp[fruits[l]] == 0)
                    mp.erase(fruits[l]); // Remove fruit type completely

                l++;                 // Shrink window from left
            }

            int len = r - l + 1;     // Current valid window length
            maxLen = max(maxLen, len); // Update maximum length
        }

        return maxLen;
    }
};

Time Complexity : O(n)  --> Single pass through the array, where n is the number of fruits.

Space Complexity : O(k)  --> The unordered_map can store up to k distinct fruit types, where k is the number of distinct fruits in the input.

✅ Optimized Approach --> class Solution { 
public: 
    int totalFruit(vector<int>& fruits) { 
        int n = fruits.size();                    // Store array size
        int maxLen = 0;                           // Store maximum valid window length
        int l = 0;                                // Left pointer of sliding window
        unordered_map<int, int> mpp;              // Store fruit type and its frequency
 
        for (int r = 0; r < n; r++) { 
            mpp[fruits[r]]++;                     // Add current fruit to the window

            if(mpp.size() > 2){                   // More than 2 unique fruit types
                mpp[fruits[l]]--;                 // Remove leftmost fruit from the map

                if(mpp[fruits[l]] == 0)            // If no such fruit remains in window  
                    mpp.erase(fruits[l]);          // Remove its key from the map & make sure we write this before l++, unlike better approach, as doing l++ first will erase the next

                l++;                              // Shrink window from the left
            } 

            int len = r - l + 1;
            maxLen = max(maxLen,len);
        } 

        return maxLen;
    } 
};

Time Complexity : O(n)  --> Single pass through the array, where n is the number of fruits.
    
Space Complexity : O(K) 

✅ Company Tags -->  Amazon - asked 20 times in the last 6 months
Google - asked 7 times in the last 6 months
Bloomberg - asked 3 times in the last 6 months
TikTok - asked 2 times in the last 6 months
Salesforce - asked 2 times in the last 6 months
Meta - asked 2 times in the last 6 months
Microsoft - asked 2 times in the last 6 months