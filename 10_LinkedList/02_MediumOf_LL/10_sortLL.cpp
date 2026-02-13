➡️ problemLinks --> 

✅ Brute Force -->  class Solution {
public:
    // Function to sort the linked list
    Node* sortLL(Node* head) {
        // Vector to store node values
        vector<int> arr;

        // Pointer to traverse the list
        Node* temp = head;

        // Traverse and push values into vector
        while (temp != nullptr) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        // Sort the vector
        sort(arr.begin(), arr.end());

        // Reassign sorted values to list nodes
        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->data = arr[i];
            temp = temp->next;
        }

        // Return head of sorted list
        return head;
    }
};

// Time Complexity:O(2*N + NlogN)
// Space Complexity:O(N)

✅ Optimized Approach --> ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head -> next;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

ListNode* merge(ListNode* left, ListNode* right){
    ListNode* dummyNode = new Node(-1);
    ListNode* temp = dummyNode;
    while(list1 != NULL && list2 != NULL){
        if(list1 -> data < list2 -> data){
            temp-> next = list1;
            list1 = list1 -> next;
        }
        else{
            temp -> next = list2;
            list2 = list2 -> next;
        }
        temp = temp -> next;
    }
    if(list1 != NULL){
        temp -> next = list1;
    }
    else{
        temp -> next = list2;
    }
    return dummyNode -> next;

}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head== NULL || head=-> next==NULL){
            return head;
        }
        ListNode* middleNode = findMiddle(head);
        ListNode* right = middleNode -> next;
        middleNode -> next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return merge(left,right);
        
    }
};

// Time Complexity: O(NlogN)
// Space Complexity: O(1) (excluding recursive stack space)

✅ Company Tags -->  Microsoft