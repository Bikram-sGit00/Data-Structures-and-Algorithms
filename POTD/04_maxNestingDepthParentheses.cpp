// parenthisis means stack


class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxDepth = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')') st.pop();
            maxDepth = max(maxDepth, (int)st.size()); // .size() returns size_T type
        }
        return maxDepth;
    }
};