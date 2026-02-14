➡️ problemLinks --> https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

✅ Brute Force -->  will set 3 counters for 0s, 1s and 2s and then will traverse the linked list and count the number of 0s, 1s and 2s. After that we will again traverse the linked list and update the values of nodes according to the count of 0s, 1s and 2s.

// Time Complexity: O(N) + O(N) = O(2N) ~ O(N)
// Space Complexity: O(1)

✅ Optimized Approach --> class Solution {
  public:
    Node* segregate(Node* head) {
        if(head == NULL || head -> next == NULL) return head;
        Node* dummy0head = new Node(-1);
        Node* dummy1head = new Node(-1);
        Node* dummy2head = new Node(-1);
        
        Node* zero_ptr = dummy0head;
        Node* one_ptr = dummy1head;
        Node* two_ptr = dummy2head;
        Node* temp = head;
        
        while(temp){
            if(temp -> data == 0){
                zero_ptr -> next = temp;
                zero_ptr = zero_ptr -> next;
            }
            else if(temp -> data == 1){
                one_ptr -> next = temp;
                one_ptr = one_ptr -> next;
            }
            else{
                two_ptr -> next = temp;
                two_ptr = two_ptr -> next;
            }
            temp = temp -> next;
        }
        zero_ptr -> next = (dummy1head->next)? dummy1head->next : dummy2head -> next;
        one_ptr -> next = dummy2head -> next;
        two_ptr -> next = NULL;
        
        Node* newHead = dummy0head -> next;
        delete dummy0head;
        delete dummy1head;
        delete dummy2head;
        
        return newHead;
        
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

✅ Company Tags -->  Amazon Microsoft MakeMyTrip NPCI