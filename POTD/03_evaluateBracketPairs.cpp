➡️ problemLinks --> https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/?envType=daily-question&envId=2026-09-26

Problem::
Given a string containing normal characters and keys inside parentheses, replace each (key) with its corresponding value from the knowledge list.
If a key is not present, replace it with ?.

My Approach::
- Store the knowledge pairs in an unordered_map for fast lookup.
- Traverse the string using i.
- Whenever "(" is found, use find(')') to locate the closing bracket.
- Extract the key using substr().
- Check the key in the map and append its value, or ? if it doesn`t exist.
- Move i directly to ")" and continue processing the string.

✅ Optimized Approach --> class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp; // will store the knowledge as key value pair

        for(auto &str : knowledge){
            mpp[str[0]] = str[1];
        }

        string result = "";
        int i = 0;

        while(i < s.size()){
            if(s[i] == '('){ // look for first opening
                // now look for closing, & after finding put that much directly into result and move i straight to closing to continue
                int j = s.find(')', i + 1); // syntax: (what to search, from where to start search)
                string subString = s.substr(i + 1, j - i - 1);
                result += mpp.count(subString) ? mpp[subString] : "?"; // if found in map put into result else add "?"
                i = j;
            }
            // else result.push_back(s[i]);
            else result += s[i]; // OR
            i++;
        }
        return result;
    }
};

Time Complexity : O(n + m) where n is the length of the string s and m is the total number of characters in all keys in the knowledge list.

Space Complexity : O(n + m) where n is the length of the string s and m is the total number of characters in all keys in the knowledge list.

✅ Company Tags -->  Google Apple