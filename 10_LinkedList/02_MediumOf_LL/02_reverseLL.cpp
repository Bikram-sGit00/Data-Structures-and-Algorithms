➡️ problemLinks --> https://leetcode.com/problems/reverse-linked-list/

✅ Brute Force -->  using stack to store the nodes and then pop them to reverse the linked list.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp != NULL){
            st.push(temp);
            temp = temp->next;
        }
        ListNode* newHead = st.top();
        st.pop();
        temp = newHead;
        while(!st.empty()){
            temp->next = st.top();
            st.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        return newHead;
    }
};

// Time Complexity --> O(2N)
// Space Complexity --> O(N)  (for stack)


✅ Optimized Approach --> 

✅ Company Tags -->  