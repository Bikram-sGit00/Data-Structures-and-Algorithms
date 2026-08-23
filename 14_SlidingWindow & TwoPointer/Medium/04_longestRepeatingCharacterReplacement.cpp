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

✅ Better Approach --> class Solution {  // make sure to read readme file to understand the approach properly ...
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0; 
        int maxLen = 0; 
        int maxFreq = 0; // highest frequency seen so far in the window
        vector<int> freqArray(26,0); // frequency of each uppercase character

        for(int r = 0; r < n; r++){ 
            freqArray[s[r] - 'A']++; // increase frequency of current character
            maxFreq = max(maxFreq,freqArray[s[r] - 'A']); // update max frequency only when adding a character

            // int len = r - l + 1; // DON'T keep len here because l can change inside while, making len stale

            while(r - l + 1 - maxFreq > k){ // window needs more than k changes, so shrink it     |  No need to recalculate maxFreq here because,
                freqArray[s[l] - 'A']--; // remove left character from current window                we only care about the max frequency seen so far in the window,
                l++; // move left pointer forward                                                    not necessarily the current window's max frequency. (readme for better understanding.)

                // We use (r-l+1) directly because l changes inside while;
                // if len was calculated before while, it would keep the OLD window size.
            }

            int len = r - l +1; // calculate length AFTER shrinking, so l and r represent the current window
            maxLen = max(maxLen, len); // update answer with the current valid window
        }

        return maxLen; 
    }
};

Time Complexity : O(2N)  --> The outer loop runs for N iterations, and the inner while loop also runs for a total of N iterations across all iterations of the outer loop. Therefore, the overall time complexity is O(2N), which simplifies to O(N).
Space Complexity : O(26)  --> The freqArray has a fixed size of 26, so its constant space

✅ Optimized Approach --> submit code using if

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