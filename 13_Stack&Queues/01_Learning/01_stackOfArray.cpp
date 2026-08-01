➡️ problemLinks --> https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

✅ Optimized Approach --> class myStack {
    // Pointer to dynamically allocated array (size is known only at runtime)
    int *st;

    // Index of the current top element (-1 means stack is empty)
    int top;

    // Maximum number of elements the stack can hold
    int capacity;

public:
    myStack(int n) {
        // Allocate array dynamically because 'n' is available only at runtime
        st = new int[n];

        // Stack starts empty
        top = -1;

        // Save capacity for overflow checks
        capacity = n;
    }

    bool isEmpty() {
        // Empty stack => no valid index exists
        return top == -1;
    }

    bool isFull() {
        // Last valid index = capacity - 1
        return top == capacity - 1;
    }

    void push(int x) {
        // Ignore push if stack is already full
        if (isFull()) return;

        // Move top first, then insert element
        // (++top): -1→0, 0→1, 1→2...
        st[++top] = x;
    }

    void pop() {
        // Ignore pop if stack is already empty
        if (top != -1)
            top--;

        // No need to erase st[top];
        // Decreasing 'top' logically removes the element. The stack ADT (Abstract Data Type) simply stops considering that element part of the stack. So now its not a part of the stack anymore. The next push will overwrite it. This is a common practice in stack implementations.
    }

    int peek() {
        // Return -1 if stack is empty
        if (top == -1)
            return -1;

        // Top element is always at index 'top'
        return st[top];
    }
};

// Time Complexity: O(1) for all operations (push, pop, peek, isEmpty, isFull)
// Space Complexity: O(n) where n is the capacity of the stack

✅ Company Tags -->  FactSet Visa GoldmanSachs Qualcomm KritikalSolutions