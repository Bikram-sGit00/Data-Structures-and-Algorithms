➡️ problemLinks --> https://leetcode.com/problems/minimum-window-substring/  && https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

✅ Brute Force -->  class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int minLen = INT_MAX;
        int strIndx = -1;

        for(int i = 0; i < n; i++){
            vector<int> hash(256, 0);
            // Store required characters of t
            for(int k = 0; k < m; k++){
                hash[t[k]]++;
            }
            for(int j = i; j < n; j++){
                hash[s[j]]--;
                // Check whether current window contains all t characters
                bool valid = true;
                for(int k = 0; k < 256; k++){
                    if(hash[k] > 0){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    int len = j - i + 1;
                    if(len < minLen){
                        minLen = len;
                        strIndx = i;
                    }
                    break; // further j will only make the window bigger
                }
            }
        }
        return strIndx == -1 ? "" : s.substr(strIndx, minLen);
    }
};

Time Complexity : O(n^2 * 256) where n is the length of string s and 256 is the size of the hash array.

Space Complexity : O(256) for the hash array.

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  