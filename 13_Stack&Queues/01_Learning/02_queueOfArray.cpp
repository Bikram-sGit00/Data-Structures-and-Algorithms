➡️ problemLinks --> https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

✅ Optimized Approach --> class myQueue {

    // Dynamically allocated array to store queue elements
    int *Q;

    // Index of the current front element
    int start;

    // Index of the current rear element
    int end;

    // Number of elements currently present in the queue
    int currSize;

    // Maximum capacity of the queue
    int size;

public:

    myQueue(int n) {

        // Queue size is known only at runtime -> allocate dynamically
        Q = new int[n];

        // Store maximum capacity for overflow checks
        size = n;

        // Queue initially contains no elements
        currSize = 0;

        // No valid front and rear indices yet
        start = -1;
        end = -1;
    }

    bool isEmpty() {

        // Queue is empty when it contains zero elements
        return currSize == 0;
    }

    bool isFull() {

        // Queue is full when current size reaches capacity
        return currSize == size;
    }

    void enqueue(int x) {

        // Ignore insertion if queue is already full
        if (isFull()) return;

        // First insertion creates the queue
        if (currSize == 0) {
            start = 0;
            end = 0;
        }
        else {

            // Circular Queue:
            // Move rear forward and wrap to 0 if needed
            end = (end + 1) % size;
        }

        // Insert at rear
        Q[end] = x;

        // One more element is now present
        currSize++;
    }

    void dequeue() {

        // Ignore removal if queue is empty
        if (isEmpty()) return;

        // Removing the last element destroys the queue state
        if (currSize == 1) {
            start = end = -1;
            currSize = 0;
        }
        else {

            // Move front forward and wrap if needed
            start = (start + 1) % size;

            // One element removed
            currSize--;
        }

        // No need to erase Q[start]
        // Changing start logically removes the element.
    }

    int getFront() {

        // Empty queue has no front element
        if (isEmpty()) return -1;

        return Q[start];
    }

    int getRear() {

        // Empty queue has no rear element
        if (isEmpty()) return -1;

        return Q[end];
    }
};

// Time Complexity: O(1) for all operations (enqueue, dequeue, getFront, getRear, isEmpty, isFull)
// Space Complexity: O(n) for the queue array

✅ Company Tags -->  Amazon GoldmanSachs