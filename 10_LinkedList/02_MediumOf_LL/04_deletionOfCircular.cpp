➡️ problemLinks --> 

✅ Brute Force -->  class Solution {
public:
    // Function to detect start of loop using Hash Map
    ListNode* detectCycle(ListNode* head) {
        // Create a map to store visited nodes
        unordered_set<ListNode*> visited;

        // Start traversing from head
        while (head != NULL) {
            // If current node is already in set, it's the start of loop
            if (visited.find(head) != visited.end()) {
                return head;
            }

            // Otherwise, insert current node into set
            visited.insert(head);

            // Move to the next node
            head = head->next;
        }

        // If loop not found, return NULL
        return NULL;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the linked list. Each node is visited only once during traversal. Hashing allows O(1) lookup to check for previously visited nodes.
// Space Complexity: O(N) due to the additional hash set used to store visited nodes. In the worst case (no cycle), all N nodes will be stored in the hash set.
