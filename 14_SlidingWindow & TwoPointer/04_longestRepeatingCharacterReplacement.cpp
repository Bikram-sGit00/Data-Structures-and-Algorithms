➡️ problemLinks --> https://leetcode.com/problems/longest-repeating-character-replacement/  &&  https://www.geeksforgeeks.org/problems/longest-repeating-character-replacement/1

✅ Brute Force -->  class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int maxFreq = 0;
            vector<int> freqArray(26,0);
            for(int j = i; j < n; j++){
                freqArray[s[j] - 'A']++; // 'A' - 'A' = 0, freq[0] = 1, A -> 1;
                maxFreq = max(maxFreq, freqArray[s[j] - 'A']); // if j = 'B', so freq[1] -> maybe 2 , and now compare with other frequencies e.g A or C.

                int len = j - i + 1; // if 'AAB', its better to change B right. so we count length 
                int changesRequired = len - maxFreq; // and then len - maxFreq(A's Freq) => 2 - 1, convert 1 element.

                if(changesRequired <= k) maxLen = max(maxLen, len);

            }

        }

        return maxLen;
    }
};

Time Complexity : O(n^2)  --> Two nested loops, where n is the length of the string.
Space Complexity : O(26)  --> The freqArray has a fixed size of 26, so its constant space

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  Google - asked 10 times in the last 6 months
Amazon - asked 4 times in the last 6 months
Microsoft - asked 3 times in the last 6 months
Bloomberg - asked 3 times in the last 6 months
DE Shaw - asked 3 times in the last 6 months
Meta - asked 3 times in the last 6 months
Infosys - asked 2 times in the last 6 months
Zoho - asked 2 times in the last 6 months