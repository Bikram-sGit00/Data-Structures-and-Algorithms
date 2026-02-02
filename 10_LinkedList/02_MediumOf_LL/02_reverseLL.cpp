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
✅ Better Approach --> will reverse the pointers of the linked list iteratively.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;   // Pointer to traverse the list
        ListNode* prev = NULL;   // Will become the new head after reversal

        while (temp != NULL) {

            // 1. Store the next node before breaking the link
            ListNode* nextNode = temp->next;

            // 2. Reverse the current node's pointer
            //    Instead of pointing to the next node,
            //    it now points to the previous node
            temp->next = prev;

            // 3. Move 'prev' one step forward
            //    This node is now part of the reversed list
            prev = temp;

            // 4. Move 'temp' to the next node in the original list
            temp = nextNode;
        }

        // 'prev' now points to the new head of the reversed list
        return prev;
    }
};

// Time Complexity --> O(N)
// Space Complexity --> O(1)

✅ Optimized Approach --> 

✅ Company Tags -->  