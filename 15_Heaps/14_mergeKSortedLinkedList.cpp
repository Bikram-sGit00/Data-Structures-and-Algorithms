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

✅ Better Approach --> class Solution {
public:

    // Merges two already sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Pick the smaller node and attach it to the answer
        while(list1 && list2) {

            if(list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        // Attach whichever list still has nodes
        if(list1) {
            temp->next = list1;
        }
        else {
            temp->next = list2;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) {
            return nullptr;
        }

        ListNode* ans = lists[0];

        // Merge the current answer with each remaining list
        for(int i = 1; i < lists.size(); i++) {
            ans = mergeTwoLists(ans, lists[i]);
            //                 O(n1),  O(n2)   for merging first 2
            //                O(n1+n2),O(n3)   for merging new list made from first 2 + 3rd list 
            // so on ...
        }

        return ans;
    }
};

Time Complexity : O(n1 + n2) + O(n1 + n2 + n3) + O(n1 + n2 + n3 + n4)  , assume each linkedlist is nearly same size n1 = n2 = n3 = n4 = n

              => n + 2n + 3n + 4n + ... + kn (added extra n, doing lot of iterations so single `n` is doesn`t matter && till `kn` cause we are merging k lists)

              => n(1 + 2 + 3 + ... + k)

                    n(k x (k + 1))
              => ≈ ----------------
                          2

Space Complexity : O(1)

✅ Optimized Approach --> 
class Solution {
    struct cmp {
        bool operator()(const std::pair<int, ListNode*>& a, const std::pair<int, ListNode*>& b) {
            return a.first > b.first;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, cmp>minHeap;
        int countOfList = lists.size(); // not all elements, just the number of individual lists

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Put the first node of every non-empty list into the heap, because each list is already sorted & the first node is the smallest node from that list.
        for(int i = 0; i < countOfList; i++){ // O(k log k), where k is the number of linked lists, and log k is for inserting into the minHeap
            if(lists[i]) minHeap.push({lists[i] -> val, lists[i]});
        }

        while(!minHeap.empty()){ // O(n x k) assuming each linked list is of size n
            pair<int, ListNode*> curr = minHeap.top();  // Get the smallest node currently available.
            temp -> next = curr.second;                 // Attach that node to our answer.
            minHeap.pop();

            if(curr.second -> next){ // check if the list has more nodes, if yes, push the next node into the heap.
                minHeap.push({curr.second -> next -> val, curr.second -> next});
            }
            temp = temp -> next; // move the temp pointer to the newly added node, and we will not lost the head as we have dummy pointer
        }
        return dummy -> next; // dummy's next is the head of the merged list
    }
};

Time Complexity : O(k log k) + O(n x k x log k) ≈ O(n log k)

Space Complexity : O(k), at max heap will contain k elements, one from each list.


✅ Without Comparator --> class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>,vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
        int countOfList = lists.size(); // not all elements, just the number of individual lists

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        for(int i = 0; i < countOfList; i++){
            if(lists[i]) minHeap.push({lists[i] -> val, lists[i]});
        }

        while(!minHeap.empty()){
            auto curr = minHeap.top(); 
            temp -> next = curr.second;
            minHeap.pop();

            if(curr.second -> next){
                minHeap.push({curr.second -> next -> val, curr.second -> next});
            }
            temp = temp -> next;
        }
        return dummy -> next;
    }
};

✅ Company Tags -->  