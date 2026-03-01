➡️ problemLinks --> https://www.geeksforgeeks.org/problems/sort-a-stack/1

✅ Optimized Approach --> class Solution {
  private:
  
    void insertSorted(stack<int>& st, int element) {
        // Base case: 
        // If stack is empty OR top is smaller/equal than element
        // then element belongs at top
        if (st.empty() || st.top() <= element) {
            st.push(element);
            return;
        }
        
        // Store the top element temporarily
        int topElement = st.top();
        st.pop();
        
        // Recursively insert element in remaining stack
        insertSorted(st, element);
        
        // Put the stored element back
        st.push(topElement);
    }

  public:
  
    void sortStack(stack<int>& st) {
        // Base case: if empty
        if (st.empty()) {
            return;
        }
        
        // Remove top element
        int topElement = st.top();
        st.pop();
        
        // Recursively sort remaining stack
        sortStack(st);
        
        // Insert removed element in sorted order
        insertSorted(st, topElement);
    }
};

// Time Complexity: O(n^2) in worst case (when stack is sorted in reverse order)
// Space Complexity: O(n) due to recursive call stack

✅ Company Tags -->  Amazon Microsoft GoldmanSachs Intuit Yahoo IBM Kuliza

