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

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  