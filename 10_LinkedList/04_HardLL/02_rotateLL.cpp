➡️ problemLinks --> https://leetcode.com/problems/rotate-list/  &&  https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

✅ Brute Force -->  

✅ Optimized Approach --> class Solution {
private:
    ListNode* findNth(ListNode* temp, int k) {
        int cnt = 1;
        while (temp != NULL) {
            if (cnt == k)
                return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;
        // find actual tail
        ListNode* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }
        if (k % len == 0)
            return head;
        k = k % len;
        tail->next = head;
        ListNode* newTail = findNth(head, len - k);
        head = newTail->next;
        newTail->next = NULL;

        return head;
    }
};

// Time Complexity: O(2N)
// Space Complexity: O(1)

✅ Company Tags -->  Accolite Amazon Microsoft MakeMyTrip