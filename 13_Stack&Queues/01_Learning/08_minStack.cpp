➡️ problemLinks --> https://leetcode.com/problems/min-stack/submissions/2095734318/

✅ Brute Force -->  class MinStack {
    // {value, minimum till this point}
    stack<pair<int, int>> st;

public:
    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            // First element is its own minimum.
            st.push({value, value});
        } else {
            // Carry forward the minimum seen so far.
            st.push({value, min(st.top().second, value)});
        }
    }

    void pop() {
        // Removing top automatically restores previous minimum.
        st.pop();
    }

    int top() {
        // First = actual stack value.
        return st.top().first;
    }

    int getMin() {
        // Second = minimum till current top.
        return st.top().second;
    }
};

Time Complexity : O(1) for all operations
Space Complexity : O(2n) where n is the number of elements in the stack

