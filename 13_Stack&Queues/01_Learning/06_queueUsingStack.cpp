➡️ problemLinks --> https://leetcode.com/problems/implement-queue-using-stacks/description/  &&  https://www.geeksforgeeks.org/problems/queue-using-stack/1

✅ Pop & Top Optimized Code -->  Here Push is costly and Pop & Top are O(1) operations. 
class MyQueue {
    // s1 always stores the queue in correct order
    // s2 is a temporary stack used only during push()
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x) {

        // Step 1: Move all old elements to s2
        // This makes s1 empty.
        while (s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Step 2: Insert the new element.
        // It becomes the bottom-most element after restoration.
        s1.push(x);

        // Step 3: Restore all old elements back to s1.
        // Queue order is now preserved.
        while (s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }

        /*
        Example:

        Queue before push(4)

        Front
          ↓
        1 2 3

        s1 (Top -> Bottom)

        1
        2
        3

        -------------------------

        Step 1: Move s1 -> s2

        s1 = Empty

        s2 (Top -> Bottom)

        3
        2
        1

        -------------------------

        Step 2: Push 4 into s1

        s1

        4

        -------------------------

        Step 3: Move s2 -> s1

        s1 (Top -> Bottom)

        1
        2
        3
        4

        Queue after push(4)

        Front
          ↓
        1 2 3 4
        */
    }

    int pop() {
        // Top of s1 always represents the queue front
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek() {
        // Queue front is always on top of s1
        return s1.top();
    }

    bool empty() {
        // Queue is empty when s1 is empty
        return s1.empty();
    }
};

Time Complexity : 
- push(): O(2n) - due to moving elements between stacks
- pop(): O(1) - direct access to top element of s1
- peek(): O(1) - direct access to top element of s1
- empty(): O(1) - direct check of s1's empty status

Space Complexity : O(n) - where n is the number of elements in the queue, as all elements are stored in s1.


✅ Company Tags -->  Microsoft

Time Complexity :  

Space Complexity : 