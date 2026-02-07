➡️ problemLinks --> https://leetcode.com/problems/palindrome-linked-list/description/  &&  https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

✅ Brute Force -->  will create a stack then compare the elements one by one to know the linkedlist is palindrome or not.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(temp->val != st.top()) return false;
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};

// Time Complexity: O(N) + O(N)  --> O(2N) or O(N)✔️
// Space Complexity: O(N)  --> for stack

✅ Better Approach --> 

✅ Optimized Approach --> 

✅ Company Tags -->  