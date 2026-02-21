➡️ problemLinks --> https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1;

✅ Brute Force --> will create a array to store all the nodes and then create a new linked list from the array.
class Solution {
public:    Node* flatten(Node* root) {
        if (root == NULL)
            return root;
        vector<Node*> arr;
        Node* temp = root;
        while (temp != NULL) {
            Node* down = temp;
            while (down != NULL) {
                arr.push_back(down);
                down = down->down;
            }
            temp = temp->next;
        }
        for (int i = 0; i < arr.size() - 1; i++) {
            arr[i]->next = arr[i + 1];
            arr[i]->down = NULL;
        }
        arr[arr.size() - 1]->next = NULL;
        arr[arr.size() - 1]->down = NULL;

        return arr[0];
    }
};

// Time Complexity: O(n * m) * 2 + x log x (where x = n * m)
// Space Complexity: O(n * m) * 2


✅ Optimized Approach --> 

✅ Company Tags -->  Paytm Flipkart Amazon Microsoft Snapdeal 24*7 InnovationLabs Payu Visa GoldmanSachs Qualcomm Drishti-Soft