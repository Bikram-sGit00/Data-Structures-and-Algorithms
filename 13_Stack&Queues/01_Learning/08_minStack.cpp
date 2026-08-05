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

✅ Optimized Approach --> class MinStack {
    stack<long long> st;
    long long min;

public:
    MinStack() {
        min = INT_MAX; // Initial minimum before any element is pushed.
    }

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            min = value; // First element is always the minimum.
        } else {
            if (value > min) {
                st.push(value); // Normal value, no encoding needed.
            } else {
                // New minimum → store encoded value to recover old minimum later.
                st.push(2LL * value - min);
                min = value;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long new_val = st.top();
        st.pop();

        if (new_val < min) {
            // Encoded value found → decode previous minimum.
            min = 2LL * min - new_val;
        }
    }

    int top() {
        if (st.empty()) return 0;

        long long x = st.top();

        // Encoded values are always smaller than current minimum.
        if (x >= min)
            return x;
        else
            return min; // Actual top was the current minimum.
    }

    int getMin() {
        // Current minimum is always maintained separately.
        return min;
    }
};

Time Complexity : O(1) for all operations

Space Complexity : O(n) where n is the number of elements in the stack

✅ Company Tags -->  Flipkart Amazon Microsoft Snapdeal D-E-Shaw FactSet Walmart GoldmanSachs SAPLabs Sapient One97 GreyOrange Kuliza