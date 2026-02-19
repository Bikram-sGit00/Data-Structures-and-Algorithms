➡️ problemLinks --> https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

✅ Brute Force -->  will set two temp pointers and check for all the pairs and count the pairs with given sum. Time complexity will be O(n^2) and space complexity will be O(1)
class Solution
{
public:
    int countPairs(struct Node* head, int x)
    {
        vector<pair<int, int>> ans;
        if(head == NULL) return ans;
        Node* temp1 = head;
        while(temp1 != NULL){
            Node* temp2 = temp1->next;
            while(temp2 != NULL && temp1 -> data + temp2 -> data <= x){
                if(temp1->data + temp2->data == x){
                    ans.push_back({temp1->data, temp2->data});
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return ans;
    }
};

// Time Complexity: O(n^2) ,near about 
// Space Complexity: O(1)

✅ Optimized Approach --> Node* findTail(Node *head){
    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    return tail;
}

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        if(head == NULL) return ans;
        Node* left = head;
        Node* right = findTail(head); // O(n)
        while(left -> data < right -> data){ // (n)
            if(left -> data + right -> data == target){
                ans.push_back({left-> data , right -> data});
                left = left -> next;
                right = right -> prev;
            }
            else if (left -> data + right -> data < target) left = left -> next;
            else right = right -> prev;
        }
        return ans;
    }
};

// Time Complexity : O(2n)
// Space Complexity : O(1) in order to store the ans;

✅ Company Tags -->  