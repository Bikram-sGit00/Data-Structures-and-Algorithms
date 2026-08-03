➡️ problemLinks --> https://leetcode.com/problems/implement-stack-using-queues/

✅ Optimized Approach --> class MyStack {
    // Single queue used to simulate stack behavior
    queue<int> Q;

    // Stores old queue size before each push (used for rotation)
    int capacity;

public:
    MyStack() {
        // Queue starts empty
        capacity = 0;
    }

    void push(int x) { // let x = 10;
        // Save old size (rotate only old elements)
        capacity = Q.size();

        // Insert new element at rear
        Q.push(x); // {20,40,50,10}

        // Rotate old elements behind the new one
        for (int i = 1; i <= capacity; i++) {
            Q.push(Q.front()); // {10} -> {10,20} -> {10,20,40} -> {10,20,40,50} -> {10,20,40,50,10}
            Q.pop(); // {10,20,40,50}
        }
    }

    int pop() {
        // ❌ Wrong (old mistake):
        // return Q.front();   // Function ends here
        // Q.pop();            // Never executes

        // Save → Remove → Return
        int ans = Q.front();
        Q.pop();
        return ans;
    }

    int top() {
        // Queue front always acts as stack top
        return Q.front();
    }

    bool empty() {
        // STL queue already knows whether it's empty
        // if(Q.empty()) return true;
        // else return false;
        return Q.empty();
    }
};

Time Complexity:
- push(): O(n) - due to the rotation of old elements
- pop(): O(1) - direct access to front element
- top(): O(1) - direct access to front element
- empty(): O(1) - direct check of queue's empty status

Space Complexity:
- O(n) - for storing elements in the queue

✅ Company Tags -->  Accolite Amazon Microsoft OYORooms Snapdeal D-E-Shaw Oracle Adobe Cisco Grofers CouponDunia KritikalSolutions