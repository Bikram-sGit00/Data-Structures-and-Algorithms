➡️ problemLinks --> https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

✅ Optimized Approach --> class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myQueue {
    Node *start;
    Node *end;
    int capacity;
    
  public:
    myQueue() {
        // Initialize your data members
        start = nullptr;
        end = nullptr;
        capacity = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(capacity == 0) return true;
        else return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* temp = new Node(x);
        if(capacity == 0){
            // start = temp;
            // end = temp;
            start = end = temp;
        }
        else{
        end -> next = temp;
        end = temp;
        }
        capacity++;
        
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()) return;
        Node* temp = start;
        start = start -> next;
        delete temp;
        capacity--;
        
        // When queue became empty
        if(capacity == 0) end = nullptr;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -
        if(isEmpty()) return -1;
        else return start -> data;
    }

    int size() {
        // Returns the current size of the queue.
        return capacity;
    }
};

// Time Complexity: O(1) for all operations (enqueue, dequeue, getFront, size, isEmpty)
// Space Complexity: O(n) where n is the number of elements in the queue

✅ Company Tags -->  