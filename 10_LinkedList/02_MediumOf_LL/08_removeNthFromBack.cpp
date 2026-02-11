➡️ problemLinks --> https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/1915933864/

✅ Brute Force --> class Solution {
public:
    // Function to print the linked list
    void printLL(Node* head) {
        while (head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }  
    Node* deleteNthNodeFromEnd(Node* head, int N) {
        // If list is empty, return NULL
        if (head == NULL) {
            return NULL;
        }

        int cnt = 0;
        Node* temp = head;

        // Count the number of nodes in the linked list
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        // If N equals the total number of nodes, delete the head
        if (cnt == N) {
            Node* newHead = head->next;
            // free memory
            delete head; 
            return newHead;
        }

        // Calculate the position from start to delete
        int res = cnt - N;
        temp = head;

        // Traverse to the node just before the one to delete
        while (temp != NULL) {
            res--;
            if (res == 0) {
                break;
            }
            temp = temp->next;
        }

        // Delete the target node
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode; // free memory

        return head;
    }
};

// Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list and then iterating up to the (L-N)th node of the linked list, where L is the total length of the list.
// Space Complexity: O(1), constant additional space is used.


✅ Optimized Approach --> 

✅ Company Tags -->  