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



class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int openBrac = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') openBrac++;
            else if(s[i] == ')') openBrac--;
            maxDepth = max(maxDepth, openBrac);
        }
        return maxDepth;
    }
};