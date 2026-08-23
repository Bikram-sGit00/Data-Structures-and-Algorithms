➡️ problemLinks --> https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

--> The question is same as "Fruit into Baskets" 

✅ Brute Force -->  class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            unordered_map<char, int> mpp;

            for(int j = i; j < n; j++){
                mpp[s[j]]++; // Add current character to the substring

                // If distinct characters exceed k,
                // no longer need to extend this substring
                if(mpp.size() > k)
                    break;

                // Update answer when substring has exactly k distinct characters
                if(mpp.size() == k){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        // No substring with exactly k distinct characters exists
        if(maxLen == 0)
            return -1;

        return maxLen;
    }
};

Time Complexity : O(n^2)  --> Two nested loops, where n is the length of the string.

Space Complexity : O(256)  --> The unordered_map can store up to n distinct characters in the worst case.

✅ Better Approach --> class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<char,int> mpp; // Stores frequency of characters in the current window
        int l = 0; // Left boundary of the window
        int maxLen = 0; // Stores the maximum valid substring length

        for(int r = 0; r < n; r++){
            mpp[s[r]]++; // Add current character to the window

            while(mpp.size() > k){
                mpp[s[l]]--; // Remove the leftmost character
                if(mpp[s[l]] == 0) mpp.erase(s[l]); // Remove character if its frequency becomes 0
                l++; // Move left boundary forward
            }

            if(mpp.size() == k){
                int len = r - l + 1; // Calculate current window length
                maxLen = max(maxLen, len); // Update maximum length
            }
        }

        if(maxLen == 0) return -1; // Return -1 if no substring has exactly k distinct characters
        else return maxLen; // Return the longest valid substring length
    }
};

Time Complexity : O(2N)

Space Complexity : O(k)  --> The unordered_map can store at most k distinct characters.

✅ Optimized Approach --> class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<char,int> mpp; // Stores frequency of characters in the current window
        int l = 0; // Left boundary of the window
        int maxLen = 0; // Stores the maximum valid substring length

        for(int r = 0; r < n; r++){
            mpp[s[r]]++; // Add current character to the window

            if(mpp.size() > k){
                mpp[s[l]]--; // Remove the leftmost character
                if(mpp[s[l]] == 0) mpp.erase(s[l]); // Erase character when its frequency becomes 0
                l++; // Move left boundary forward
            }

            if(mpp.size() == k){
                int len = r - l + 1; // Calculate current window length
                maxLen = max(maxLen, len); // Update maximum length
            }
        }

        if(maxLen == 0) return -1; // Return -1 if no valid substring exists
        else return maxLen; // Return the longest valid substring length
    }
};

Time Complexity : O(n)

Space Complexity : O(k)  --> The unordered_map can store at most k distinct characters.

✅ Company Tags -->  Amazon Google SAPLabs