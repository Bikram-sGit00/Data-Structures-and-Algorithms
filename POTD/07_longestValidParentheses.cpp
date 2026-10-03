➡️ problemLinks --> https://leetcode.com/problems/longest-valid-parentheses/description/?envType=daily-question&envId=2026-10-03

✅ Optimized Approach --> class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int open = 0;
        int close = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') open++;
            else close++;

            if(open == close) result = max(result, open + close); // if open braces and close braces == so add into ans;
            else if(close > open) open = close = 0; // otherwise if closing is greater than open braces , reset all stuffs and start counting again
        }                                          // e.g. ())(()) here we can see we get valid = 2 for this "()" but after ignoring extra ")"
                                                  // we got longest valid as 4 for " (()) "
        open = 0;
        close = 0;

        //Again checking right to left, e.g. () ( (), in this type cases , open braces can dominate , as in first loop we only check if closing are dominating or not 
        // so this time iterate right to left and check if open > close , so reset , check 2 times and return the maximum
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '(') open++;
            else close++;

            if(open == close) result = max(result, open + close);
            else if(open > close) open = close = 0;
        }

        return result;
    }
};

Time Complexity : O(n) + O(n) = O(n) , where n is the length of the string s

Space Complexity : O(1)

✅ Company Tags -->  Google — asked Unknown times — time period Unknown
Amazon — asked Unknown times — time period Unknown
Microsoft — asked Unknown times — time period Unknown
Meta — asked Unknown times — time period Unknown
Bloomberg — asked Unknown times — time period Unknown
Uber — asked Unknown times — time period Unknown
TikTok — asked Unknown times — time period Unknown
Oracle — asked Unknown times — time period Unknown
LinkedIn — asked Unknown times — time period Unknown