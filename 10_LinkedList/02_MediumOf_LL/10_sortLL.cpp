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