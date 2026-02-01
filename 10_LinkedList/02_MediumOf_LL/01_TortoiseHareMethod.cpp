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

✅ Optimized Approach --> class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Time Complexity --> O(n/2)
// Space Complexity --> O(1)

✅ Company Tags -->  VMWare Zoho Flipkart Morgan Stanley Amazon Microsoft Samsung Hike Payu MAQ Software Adobe Wipro SAP Labs Qualcomm Nagarro GEVeritas IgniteWorld Netskope