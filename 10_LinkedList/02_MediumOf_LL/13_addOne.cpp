➡️ problemLinks --> https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

✅ Brute Force -->  class Solution {
public:
    // function to reverse the linked list
    Node* reverseList(Node* node) {
        Node* prev = nullptr;
        Node* current = node;

        while (current) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    // Function to add one to the number represented by the linked list
    Node* addOne(Node* head) {
        // Reverse the list to make least significant digit accessible
        head = reverseList(head);

        Node* current = head;
        // Initial carry since we want to add 1
        int carry = 1;  

        // Traverse the list and add carry
        while (current && carry) {
            int sum = current->data + carry;
            current->data = sum % 10;
            carry = sum / 10;

            // If there's no next node and we still have a carry, append a new node
            if (!current->next && carry) {
                current->next = new Node(carry);
                carry = 0;  
            }

            current = current->next;
        }

        // Reverse the list back to restore original order
        head = reverseList(head);
        return head;
    }
};

// Time Complexity: O(3N)
// Space complexity : O(1)

✅ Optimized Approach --> int helper(Node* temp){
    if(temp == NULL) return 1; // base case 
    int carry = helper(temp -> next);
    temp -> data += carry; // add carry with digit
    if(temp -> data < 10){
        return 0; // means no carry over
    }
    return 1; // carry
}

class Solution {
  public:
    Node* addOne(Node* head) {
        Node* temp = head;
        int carry = helper(temp); // passing elements 
        if(carry == 1){ // if have to create extra digit
            Node* newHead = new Node(1);
            newHead -> next = head;
            return newHead;
        }
        return head; // else return prev head 
    }
};

// Time Complexity: O(N) where N is the number of nodes in the linked list.
// Space Complexity: O(N) due to recursive stack space in the worst case when all digits are 9.

✅ Company Tags -->  amazon