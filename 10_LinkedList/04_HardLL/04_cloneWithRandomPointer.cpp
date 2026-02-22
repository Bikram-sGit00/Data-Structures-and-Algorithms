➡️ problemLinks --> https://leetcode.com/problems/copy-list-with-random-pointer/description/  &&  https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

✅ Brute Force -->  will use a hash map to store the mapping of original nodes to their corresponding cloned nodes. We will first create a new node for each original node and store the mapping in the hash map. Then, we will iterate through the original list again and set the next and random pointers for the cloned nodes using the hash map. The time complexity of this approach is O(n) and the space complexity is O(n) due to the hash map.

class solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        // Step 1: Create a mapping of original nodes to their corresponding cloned nodes
        unordered_map<Node*, Node*> nodeMap;
        Node* temp = head;
        
        while(temp != NULL) {
            nodeMap[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        // Step 2: Set the next and random pointers for the cloned nodes
        temp = head;
        while(temp != NULL) {
            Node* copyNode = nodeMap[temp];
            copyNode->next = nodeMap[temp->next];
            copyNode->random = nodeMap[temp->random];
            temp = temp->next;
        }
        
        // Return the head of the cloned list
        return nodeMap[head];
    }
};

✅ Optimized Approach --> void insertCopyInBetween(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* nxtElement = temp->next;
        Node* copyNode = new Node(temp->val);
        copyNode->next = nxtElement;
        temp->next = copyNode;
        temp = nxtElement;
    }
}

void connectRandomPointers(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* copyNode = temp->next;
        if (temp->random)
            copyNode->random = temp->random->next;
        else
            copyNode->random = NULL;

        temp = temp->next->next;
    }
    
}

Node* extactClonedList(Node* head) {
    Node* temp = head;
    Node* dummy = new Node(-1);
    Node* res = dummy;
    while (temp != NULL) {
        res->next = temp->next;
        res = res->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummy->next;
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return extactClonedList(head);
    }
};

// Time Complexity: O(3n)  &&  Space Complexity: O(1)

✅ Company Tags --> Flipkart MorganStanley Amazon Microsoft OYORooms Snapdeal D-E-Shaw MakeMyTrip OlaCabs Walmart Adobe BankBazaar



