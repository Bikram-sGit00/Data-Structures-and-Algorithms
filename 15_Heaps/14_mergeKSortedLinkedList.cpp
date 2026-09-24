➡️ problemLinks --> https://leetcode.com/problems/merge-k-sorted-lists/  &&  https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

✅ Brute Force -->  class Solution {
public:

    // Converts a sorted vector into a Linked List
    ListNode* convertToLinkedList(vector<int>& arr) {

        // Dummy node helps us build the linked list easily
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Create a new node for every value in the vector
        for(int val : arr) { //(n) where n is the total number of nodes across all linked lists
            temp->next = new ListNode(val);  // O(n) space complexity for creating new nodes
            temp = temp->next;
        }

        // dummy itself is not part of the answer
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int> arr;

        // Step 1: Store every value from every linked list
        for(int i = 0; i < lists.size(); i++) {// O(k), where k is the number of linked lists

            ListNode* temp = lists[i];

            while(temp != NULL) { // ≈ O(n), where n is the number of nodes inside the linked lists
                arr.push_back(temp->val); 
                temp = temp->next;
            }
        }

        // Step 2: Sort all values together
        sort(arr.begin(), arr.end()); //O(nlogn), where n is the total number of nodes across all linked lists

        // Step 3: Convert the sorted vector back into a Linked List
        return convertToLinkedList(arr); // O(n), where n is the total number of nodes across all linked lists
    }
};

Time Complexity : O(n x k) + O(nlogn) + O(n) = O(nlogn)

Space Complexity : O(n) + O(n) ≈ O(n), where n is the total number of nodes across all linked lists

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  



