➡️ problemLinks --> https://leetcode.com/problems/lfu-cache/  &&  https://www.geeksforgeeks.org/problems/lfu-cache-1665050355/1

✅ Optimized Approach --> //To implement a node in doubly linked list that will store data items
struct Node {
   int key, value, freq;
   Node *next; 
   Node *prev;
   Node(int _key, int _value) {
       key = _key;
       value = _value; 
       freq = 1; // new node will start with frequency 1
   }
}; 

// To implement the doubly linked list
struct List {
   int size; // Size 
   Node *head; // Dummy head
   Node *tail; // Dummy tail
   
   // Constructor
   List() {
       head = new Node(0, 0); 
       tail = new Node(0,0); 
       head->next = tail;
       tail->prev = head; 
       size = 0;
   }
   
   // Function to add node in front 
   void addFront(Node *node) {
       Node* temp = head->next;
       node->next = temp;
       node->prev = head;
       head->next = node;
       temp->prev = node;
       size++; 
   }
   
   // Function to remove node from the list
   void removeNode(Node* delnode) {
       Node* prevNode = delnode->prev;
       Node* nextNode = delnode->next;
       prevNode->next = nextNode;
       nextNode->prev = prevNode;
       size--; 
   }
};


class LFUCache {
    int capacity;                              // Maximum cache size
    int minFreq;                               // Smallest frequency currently present

    unordered_map<int, Node*> keyNode;         // key -> actual node
    unordered_map<int, List*> freqList;        // frequency -> DLL
public:
    LFUCache(int capacity) {
        this -> capacity = capacity;
        minFreq = 0;
    }
    // Moves node from old frequency list to new frequency list
    void updateFreqList(Node* node){
        int oldFreq = node -> freq;
        // Remove node from its current frequency list
        freqList[oldFreq] -> removeNode(node); // as Freq is key in freqList map

        //If the old element's frequency list completely disappeared, update the global minimum.
        if(oldFreq == minFreq && freqList[oldFreq]->size == 0) minFreq ++; //freq 1 → empty, update min
        node -> freq++; // Increase node's frequency

        // Create new list if this frequency doesn't exist
        if(freqList.find(node -> freq) == freqList.end()){
            freqList[node -> freq] = new List();
        }
        // Put node at front = most recently used in new frequency
        freqList[node -> freq] -> addFront(node);
    }
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1; // Key doesn't exist

        Node* node = keyNode[key]; //If we have, get the node
        updateFreqList(node); // Updating its frequency

        return node -> value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return; // given cache size is 0 , so we can never store anything

        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node -> value = value; // Update its value
            updateFreqList(node); // Since it was used, increase its frequency
            return;
        }
        // Cache is full -> remove LFU node
        if(keyNode.size() == capacity){
            List* list = freqList[minFreq]; // pointer to min list
            Node* toBeDelNode = list -> tail -> prev; // Least recently used node is at the back
            list -> removeNode(toBeDelNode); // Remove it from the DLL
            keyNode.erase(toBeDelNode ->key); // Remove it from key -> node map
            delete toBeDelNode; // Delete the node from memory
        }

        Node* newNode = new Node(key,value); // Create new node
        minFreq = 1; // New node starts with frequency 1

        if(freqList.find(1) == freqList.end()){ // Create frequency-1 list if needed
            freqList[1] = new List();
        }

        freqList[1] -> addFront(newNode); // Add new node to frequency-1 list
        keyNode[key] = newNode; // // Store key -> node mapping
    }
};

Time Complexity : O(1) for both get and put operations, as all operations (insertion, deletion, and access) in the hash maps and doubly linked lists are O(1).

Space Complexity : O(n), where n is the capacity of the cache, as we are storing up to n nodes in the cache along with their frequency lists.

✅ Company Tags -->  