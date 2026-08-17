➡️ problemLinks --> https://leetcode.com/problems/longest-substring-without-repeating-characters/description/  &&  https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1

✅ Brute Force -->  class Solution { 
public: 
    int lengthOfLongestSubstring(string s) { 
        int n = s.length(); 
        int maxLen = 0;  
        for (int i = 0; i < n; i++) { 
            vector<int> hashArray(256, 0); // tracks characters seen in current substring
            for (int j = i; j < n; j++) { 
                if (hashArray[s[j]] == 1) break; // duplicate found, stop expanding
                int len = j - i + 1; // calculate current substring length
                maxLen = max(maxLen, len); // update maximum length
                hashArray[s[j]] = 1; // mark current character as seen
            } 
        } 
        return maxLen; // return longest substring length
    } 
};

Time Complexity : O(n^2)
Space Complexity : O(256)

✅ Optimized Approach --> class Solution { 
public: 
    int lengthOfLongestSubstring(string s) { 
        int n = s.length(); 
        int maxLen = 0; 
        int l = 0; 
        // int r = 0; 
        vector<int> hashArray(256, 0); // stores whether a character is present in the current window
 
        for (int r = 0; r < n; r++){ 
            while(hashArray[s[r]] == 1){ // duplicate found, shrink window from the left
                hashArray[s[l]] = 0; // remove the leftmost character from the window
                l++; // move left pointer forward
            } 
            hashArray[s[r]] = 1; // mark current character as present
            int len = r - l + 1; // calculate current window length
            maxLen = max(maxLen,len); // update maximum length
        } 
        return maxLen; // return longest substring length
    } 
};

Time Complexity : O(n)

Space Complexity : O(256)

✅ Company Tags -->  Amazon Microsoft Housing.com Adobe Google Synopsys MorganStanley