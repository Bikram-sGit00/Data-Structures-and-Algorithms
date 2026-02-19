➡️ problemLinks --> https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

✅ Optimized Approach --> class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        Node* temp = head;
        while(temp != NULL && temp -> next != NULL){
            Node* nextNode = temp -> next;
            while(nextNode != NULL && nextNode -> data == temp -> data ){ // will stop at not matching element
                Node* duplicate = nextNode; 
                nextNode = nextNode -> next; 
                delete duplicate;
            }
            temp -> next = nextNode;
            if(nextNode) nextNode -> prev = temp;
            temp = temp -> next;
        }
        return head;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the linked list
// Space Complexity: O(1) as we are not using any extra space for data structures

✅ Company Tags -->  