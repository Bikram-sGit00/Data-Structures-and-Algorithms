➡️ problemLinks --> https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

✅ Brute Force -->  using stack ,
struct Node* reverseDLL(struct Node* head) {
    if(!head || !head->next) return head;
    
    stack<Node*> st;
    Node* temp = head;
    
    while(temp) {
        st.push(temp);
        temp = temp->next;
    }
    
    head = st.top();
    st.pop();
    temp = head;
    
    while(!st.empty()) {
        temp->next = st.top();
        st.pop();
        temp->next->prev = temp;
        temp = temp->next;
    }
    temp->next = NULL;
    
    return head;
}

// Time Complexity: O(2N)
// Space Complexity: O(N)

✅ Better Approach --> 

✅ Optimized Approach --> 

✅ Company Tags -->  