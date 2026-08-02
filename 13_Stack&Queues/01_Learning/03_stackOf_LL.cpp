➡️ problemLinks --> https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

✅ Optimized Approach --> class myStack {
    // Points to the current top node (head of the linked list)
    Node* top;

    // Current number of nodes in the stack
    int capacity;

public:
    myStack() {
        // Empty stack => no head node
        top = nullptr;

        // Initially, stack contains 0 elements
        capacity = 0;
    }

    bool isEmpty() {
        // Empty stack has no nodes
        return capacity == 0;
    }

    void push(int x) {
        // Create a new node
        Node* temp = new Node(x);

        // Connect new node to the old stack
        temp->next = top;

        // Make the new node the new top
        top = temp;

        // One node added
        capacity++;
    }

    void pop() {
        // Ignore pop on empty stack
        if (isEmpty()) return;

        // Store current top node
        Node* temp = top;

        // Move top to the next node
        top = top->next;

        // Free old top node (avoid memory leak)
        delete temp;

        // One node removed
        capacity--;
    }

    int peek() {
        // No top element exists
        if (isEmpty()) return -1;

        // Top node always stores the answer
        return top->data;
    }

    int size() {
        // Current number of nodes
        return capacity;
    }
};

// Time Complexity: O(1) for all operations
// Space Complexity: O(n) for n elements in the stack

✅ Company Tags -->  Microsoft Samsung FactSet SAPLabs Codenation