➡️ problemLinks --> https://leetcode.com/problems/middle-of-the-linked-list/  &&  https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

✅ Brute Force -->  class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        int mid = count / 2;
        temp = head;
        for(int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        
        return temp;
    }
};

// Time Complexity --> O(N)
// Space Complexity --> O(1)

✅ Optimized Approach --> 

✅ Company Tags -->  