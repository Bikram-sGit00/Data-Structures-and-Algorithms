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


✅ Optimized Approach --> Node* merge(Node* l1, Node* l2) {
    
    // Dummy node to simplify merge logic
    Node* dummy = new Node(-1);
    
    // 'res' always points to the last node
    // of the merged bottom list being built
    Node* res = dummy;

    // Merge like standard merge of two sorted lists
    while (l1 && l2) {
        
        if (l1->data < l2->data) {
            
            // Attach l1 to merged bottom chain
            res->bottom = l1;
            
            // Move res forward (tail update)
            res = l1;
            
            // Advance l1 vertically
            l1 = l1->bottom;
        }
        else {
            
            // Attach l2 to merged bottom chain
            res->bottom = l2;
            
            // Move res forward (tail update)
            res = l2;
            
            // Advance l2 vertically
            l2 = l2->bottom;
        }

        // VERY IMPORTANT:
        // After attaching a node, break its horizontal link.
        // Final flattened list must use only bottom pointers.
        res->next = nullptr;
    }

    // Attach remaining nodes (if any)
    if (l1) res->bottom = l1;
    if (l2) res->bottom = l2;

    // Safety: ensure head of merged list
    // does not retain any horizontal linkage
    if (dummy->bottom)
        dummy->bottom->next = nullptr;

    // Return real head (skip dummy)
    return dummy->bottom;
}

class Solution {
public:

    // Recursively flatten the linked list
    Node* flatten(Node* head) {
        
        // Base case:
        // If only one list remains, it is already flat
        if (head == NULL || head->next == NULL)
            return head;

        // Recursively flatten the right side
        Node* mergedHead = flatten(head->next);

        // Merge current vertical list with flattened right side
        head = merge(head, mergedHead);

        return head;
    }
};

// Time Complexity: O(2nm) (where n is number of nodes in horizontal direction and m is number of nodes in vertical direction)
// Space Complexity: O(1) (excluding recursion stack space)

✅ Company Tags -->  Paytm Flipkart Amazon Microsoft Snapdeal 24*7 InnovationLabs Payu Visa GoldmanSachs Qualcomm Drishti-Soft