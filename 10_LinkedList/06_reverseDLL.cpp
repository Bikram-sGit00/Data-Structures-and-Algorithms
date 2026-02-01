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

✅ Optimized Approach --> class Solution {
  public:
    Node *reverse(Node *head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        Node* prev = NULL;
        Node* current = head;
        while(current != NULL){ // swaping like swap (a,b) problem
            prev = current -> prev; 
            current -> prev = current -> next;
            current -> next = prev;
            
            current = current -> prev; // forward in the original list not current -> next cause we swaped
        }
        return prev -> prev; // last_process -> prev or nulls previous
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

✅ Company Tags -->  D-E-Shaw Adobe