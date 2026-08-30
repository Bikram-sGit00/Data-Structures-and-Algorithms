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

✅ Optimized Approach --> class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l = 0;
        int cnt = 0;
        int strIndx = -1;
        int minLen = INT_MAX;
        vector<int> hash(256, 0);
        for (int i = 0; i < m; i++) { //O(m)
            hash[t[i]]++; // add all the t's elements into hash
        }
        for (int r = 0; r < n; r++) { //O(n)
            if (hash[s[r]] > 0) { // we found something in s that also in t, so we increase ther counter
                cnt++;
            }
            hash[s[r]]--; // now decrease that in hash, as we have increased the counter
O(n), overall while (cnt == m) { // our conter gets equal to the size of t, means we got a substring containing all t'elements
                int len = r - l + 1;
                if (len < minLen) { //update the minimum possible
                    minLen = len;
                    strIndx = l; // can't use min(), as we have to update our starting position everytime, as we will return the string, not the size of min
                }
                hash[s[l]]++; // now we will keep checking for possible answer with minimum length, so keep moving l while counter == size of t, and why ++ ? as by default its -1 so -- will increase that to -2, -3 so one, where as ++ will set this as 0, 1, 2
                if (hash[s[l]] > 0) // and after removal or moving l, if we found its value > 0, means we are not  
                    cnt--; // using it for answer, so remove this from cnt
                l++; // now forward l
            }
        }
        return strIndx == -1 ? "" : s.substr(strIndx, minLen); // if starting index never been updated,means we never find a substring containing all t'element, return empty string
    }
};

Time Complexity : O(2n) + O(M)

Space Complexity : O(256)

✅ Company Tags -->  Amazon - asked 18 times in the last 6 months
Microsoft - asked 5 times in the last 6 months
Google - asked 3 times in the last 6 months
Lyft - asked 3 times in the last 6 months
Meta - asked 2 times in the last 6 months
Bloomberg - asked 2 times in the last 6 months
Oracle - asked 2 times in the last 6 months
Goldman Sachs - asked 2 times in the last 6 months