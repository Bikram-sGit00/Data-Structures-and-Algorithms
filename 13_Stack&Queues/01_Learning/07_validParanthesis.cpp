➡️ problemLinks --> https://leetcode.com/problems/valid-parentheses/
 
✅ Optimized Approach --> class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                char ch = st.top();
                st.pop();
                if ((s[i] == ')' && ch == '(') ||
                    (s[i] == '}' && ch == '{') ||
                    (s[i] == ']' && ch == '['))
                    {
                        // keep checking 
                    }else{
                        return false;
                    }
                    
            }
        }
        return st.empty(); // if this "(((" , it will be in stack , so return false for this now ...
    }
};

Time Complexity :  O(n)
Space Complexity :  O(n)

✅ Company Tags -->  Flipkart Amazon Microsoft OYORooms Snapdeal Oracle Walmart Adobe Google Yatra.com 