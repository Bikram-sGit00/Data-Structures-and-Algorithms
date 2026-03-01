➡️ problemLinks --> https://www.geeksforgeeks.org/problems/reverse-a-stack/1

✅ Optimized Approach --> class Solution {
    private:

        // This function puts an element at the BOTTOM of the stack
        // even though stack normally allows insertion only at TOP.
        void insertAtBottom(stack<int> &st, int ele){

            // Base Case:
            // If stack is empty, that means we reached the bottom.
            // So now we can safely push the element.
            if(st.empty()){
                st.push(ele);
                return;   // stop recursion
            }
            
            // Step 1:
            // Remove the top element and store it somewhere safe.
            int topEle = st.top();
            st.pop();
            
            // Step 2:
            // Recursively keep removing elements
            // until stack becomes empty.
            insertAtBottom(st, ele);
            
            // Step 3:
            // After ele is inserted at bottom,
            // we push back the removed elements
            // so stack structure stays same.
            st.push(topEle);
        }

  public:

    void reverseStack(stack<int> &st) {

        // Base Case:
        // If stack is empty, nothing to reverse.
        if(st.empty()){
            return;
        }
        
        // Step 1:
        // Remove the top element.
        int ele = st.top();
        st.pop();
        
        // Step 2:
        // Recursively reverse the remaining stack.
        reverseStack(st);
        
        // Step 3:
        // After smaller stack is reversed,
        // insert the removed element at bottom.
        insertAtBottom(st, ele);
    }
};

// Time Complexity: O(N^2) --> For each of the N elements, we are doing an O(N) operation to insert it at the bottom.
// Space Complexity: O(N) --> Due to recursive call stack, in worst case we can have N calls on the stack.

✅ Company Tags -->  