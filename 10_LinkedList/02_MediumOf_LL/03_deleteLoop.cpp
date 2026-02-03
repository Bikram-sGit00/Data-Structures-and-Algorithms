➡️ problemLinks --> https://leetcode.com/problems/linked-list-cycle/

✅ Brute Force -->  Using Hashing 
class Solution {
public:
    // Function to detect a loop in the linked list
    bool detectLoop(Node* head) {
        // Initialize a pointer at head
        Node* temp = head;

        // Create a map to keep track of visited nodes
        unordered_map<Node*, int> nodeMap;

        // Traverse the linked list
        while (temp != nullptr) {
            // If node already exists in map, loop detected
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            // Store the current node in the map
            nodeMap[temp] = 1;

            // Move to the next node
            temp = temp->next;
        }

        // If traversal completes, no loop detected
        return false;
    }
};

✅ Optimized Approach --> Tortoise and Hare Algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next != NULL){
            slow = slow-> next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

✅ Company Tags -->  