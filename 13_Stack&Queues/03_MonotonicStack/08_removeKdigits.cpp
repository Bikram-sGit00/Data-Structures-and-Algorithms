➡️ problemLinks --> https://leetcode.com/problems/remove-k-digits/  &&  https://www.geeksforgeeks.org/problems/remove-k-digits/1

✅ Optimized Approach --> class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();

        for (int i = 0; i < n; i++) {

            // 🚀 Keep digits increasing: kill bigger left digit when smaller digit arrives
            // Example: 143 → see 3, remove 4 → 13
            while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // 🚀 Still have removals? Number is already increasing → remove from the end
        // Example: 12345, k=2 → remove 5, 4
        while (k > 0) {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";

        string res = "";

        // 🚀 Stack gives reverse order → rebuild the number
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        // 🚀 res is reversed, so trailing 0s here = leading 0s in final answer
        // Example: 001000 → reversed form: 000100 → remove trailing 0s first
        while (res.size() != 0 && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        if (res.empty())
            return "0";

        return res;
    }
};

Time Complexity : O(3n) + O(k)

Space Complexity : O(n) for stack + O(n) for result string = O(2n) ~ O(n)

✅ Company Tags -->  Microsoft NPCI