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


✅ Optimized Approach --> ListNode* reverseList(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = NULL; 
    while (temp != NULL) {
        ListNode* nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }
    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* firstPointer = head;
        ListNode* secondPointer = newHead;
        while (secondPointer != NULL) {
            if (firstPointer->val != secondPointer->val) {
                reverseList(newHead);
                return false;
            }
            firstPointer = firstPointer->next;
            secondPointer = secondPointer->next;
        }
        reverseList(newHead);
        return true;
    }
};

// Time Complexity: O(N)  --> for finding the middle and reversing the second half of the linked list
// Space Complexity: O(1)  --> for using only constant space to store the pointers and reverse the linked list in place

✅ Company Tags -->  Accolite Amazon Microsoft Snapdeal MakeMyTrip Adobe Yodlee Infotech KLA Tencor KritikalSolutions