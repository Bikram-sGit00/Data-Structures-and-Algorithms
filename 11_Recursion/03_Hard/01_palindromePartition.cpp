➡️ problemLinks --> https://leetcode.com/problems/palindrome-partitioning/

✅ Optimized Approach --> class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result; // stores all valid partitions
        vector<string> path;           // stores current partition
        func(0, s, path, result);      // start recursion from index 0
        return result;
    }

    void func(int indx, string s, vector<string>& path,
              vector<vector<string>>& result) {

        // base case: reached end of string, save current partition
        if (indx == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = indx; i < s.size(); i++) { // iterating in a string  , ++i is just a good habit , it doesn't matter much as compiler optimizes it
            if (isPalindrome(s, indx, i)) {                    // check if s[indx..i] is palindrome
                path.push_back(s.substr(indx, i - indx + 1)); // choose: add substring to path
                func(i + 1, s, path, result);                  // explore: recurse from next index
                path.pop_back();                               // unchoose: backtrack
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {               // check characters from both ends
            if (s[start++] != s[end--])      // mismatch found, not a palindrome
                return false;
        }
        return true;                         // all characters matched, is a palindrome
    }
};

✅ Company Tags -->  Amazon Microsoft Google