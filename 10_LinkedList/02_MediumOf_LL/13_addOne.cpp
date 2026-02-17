➡️ problemLinks --> https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

✅ Brute Force -->  

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