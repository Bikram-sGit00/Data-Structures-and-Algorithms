➡️ problemLinks --> https://leetcode.com/problems/odd-even-linked-list/description/  && https://leetcode.com/problems/odd-even-linked-list/description/

✅ Brute Force -->  will go theough the odd indexes and then through the even indexes and create a list , and then again reIterate to change the main linked list 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        vector<int> arr;

        // Step 1: store odd index values
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }

        // If last odd node exists (for odd length list)
        if (temp != NULL) {
            arr.push_back(temp->val);
        }

        // Step 2: store even index values
        temp = head->next;
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }

        if (temp != NULL) {
            arr.push_back(temp->val);
        }

        // Step 3: overwrite linked list values
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};

// Time Complexity: O(n) for traversing the linked list and O(n) for overwriting values, resulting in O(n) overall.
// Space Complexity: O(n) for storing the values in the vector.

✅ Better Approach --> 

✅ Optimized Approach --> 

✅ Company Tags -->  