➡️ problemLinks --> https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

✅ Brute Force -->  will set two temp pointers and check for all the pairs and count the pairs with given sum. Time complexity will be O(n^2) and space complexity will be O(1)
class Solution
{
public:
    int countPairs(struct Node* head, int x)
    {
        int count = 0;
        Node* temp1 = head;
        while(temp1 != NULL){
            Node* temp2 = temp1->next;
            while(temp2 != NULL && temp1 -> data + temp2 -> data <= x){
                if(temp1->data + temp2->data == x){
                    count++;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return count;
    }
};

// Time Complexity: O(n^2) ,near about 
// Space Complexity: O(1)

✅ Optimized Approach --> 

✅ Company Tags -->  