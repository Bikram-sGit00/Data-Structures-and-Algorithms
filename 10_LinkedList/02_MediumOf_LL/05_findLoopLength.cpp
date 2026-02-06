➡️ problemLinks --> https://www.geeksforgeeks.org/problems/find-length-of-loop/1

✅ Brute Force -->  class Solution {
public:
    // Function to return the length of loop using hashing
    int lengthOfLoop(Node* head) {
        // Hashmap to store visited nodes and their timer values
        unordered_map<Node*, int> visitedNodes;

        // Pointer to traverse the linked list
        Node* temp = head;

        // Timer to track visited nodes
        int timer = 0;

        // Traverse the linked list till temp reaches nullptr
        while (temp != NULL) {
            // If revisiting a node, return the difference of timer values
            if (visitedNodes.find(temp) != visitedNodes.end()) {
                // Calculate the length of the loop
                int loopLength = timer - visitedNodes[temp];

                // Return the length of the loop
                return loopLength;
            }

            // Store the current node and its timer value
            visitedNodes[temp] = timer;

            // Move to the next node
            temp = temp->next;

            // Increment the timer
            timer++;
        }

        // If traversal is completed and we reach the end of the list
        // means there is no loop
        return 0;
    }
};

// Time Complexity: O(N), we traverse the entire linked list atleast once to find the length of the loop.
// Space Complexity: O(N) , we use a map to store the timers for the nodes in the linked list.

✅ Optimized Approach --> 

✅ Company Tags -->  