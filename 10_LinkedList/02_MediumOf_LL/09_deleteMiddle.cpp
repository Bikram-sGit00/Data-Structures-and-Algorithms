➡️ problemLinks --> https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/  &&  https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

✅ Brute Force -->  class Solution {
public:
    // Function to delete the middle node of a linked list
    Node* deleteMiddle(Node* head) {
        // Initialize a temporary node to traverse the linked list
        Node* temp = head;
        
        // Variable to hold the number of nodes in the linked list
        int n = 0;
        
        // Loop to count the number of nodes in the linked list
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        
        // Calculate the index of the middle node
        int res = n / 2;
        
        // Reset the temporary node to the beginning of the linked list
        temp = head;
        
        // Loop to find the middle node to delete
        while (temp != NULL) {
            res--;
            
            // If the middle node is found
            if (res == 0) {
                // Create a pointer to the middle node
                Node* middle = temp->next;
                
                // Adjust pointers to skip the middle node
                temp->next = temp->next->next;
                
                // Free the memory allocated to the middle node
                free(middle);
                
                // Exit the loop after deleting the middle node
                break;
            }
            
            // Move to the next node in the linked list
            temp = temp->next;
        }
        
        // Return the head of the modified linked list
        return head;
    }
};

// Time Complexity: O(L + L/2) 
// Space Complexity: O(1), constant additional space is used.

✅ Optimized Approach --> class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        // fast starts from head->next->next instead of head
        // so that slow stops exactly at (middle - 1)
        fast = head->next->next;

        // Move fast by 2 steps and slow by 1 step
        // When fast reaches the end, slow is just before middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* toBeDel = slow->next;
        slow->next = slow->next->next;
        // Free memory of the deleted node (important in C++)
        delete toBeDel;
        return head;
    }
};

// Time Complexity: O(n/2);
// Space Complexity: O(1), constant additional space is used.

✅ Company Tags -->  Flipkart Amazon Microsoft