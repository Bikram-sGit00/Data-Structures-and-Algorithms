➡️ problemLinks --> https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

✅ Optimized Approach --> class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        Node* temp = *head;
        while(temp != NULL){
            if(temp-> data == x){
                if(temp == *head){
                    *head = temp -> next; 
                }
                Node* prevNode = temp -> prev;
                Node* nextNode = temp -> next;
                
                if(nextNode) nextNode -> prev = prevNode; // if you manipulate without checking it will throw 
                if(prevNode) prevNode -> next = nextNode; // error cause of null e.g. null -> prev
                delete temp;
                temp = nextNode;
            }
            else{
                temp = temp -> next; // 
            }
        }
    }
};

// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Space Complexity: O(1) as we are not using any extra space for data structures, only a few pointers.

✅ Company Tags -->  