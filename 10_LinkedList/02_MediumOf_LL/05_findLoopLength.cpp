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

✅ Optimized Approach --> class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){ 
                int cnt = 1;  // starting count from 1 because we are already at the first node of the loop
                fast = fast -> next; // move the fast pointer to the next node to start counting the loop length
                while(fast != slow){ // we will keep moving the fast pointer until it meets the slow pointer again, counting the number of nodes in the loop
                    cnt++;
                    fast = fast -> next;
                }
                return cnt;
            }
        }
        return 0;
    }
};

// Time Complexity: O(N), we traverse the entire linked list atleast once to find the length of the loop.
// Space Complexity: O(1) , we use a constant amount of additional space, regardless of the linked list's length to find the length of the loop.

✅ Company Tags -->  Amazon Adobe Qualcomm