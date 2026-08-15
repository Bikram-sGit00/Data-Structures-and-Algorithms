➡️ problemLinks --> https://leetcode.com/problems/lru-cache/description/  &&  https://www.geeksforgeeks.org/problems/lru-cache/1

✅ Optimized Approach --> class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    // Add node just after head = mark it as most recently used
    void addNode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    // Delete node by connecting its previous and next nodes
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Dummy nodes avoid special cases while adding/deleting
    Node* head = new Node(-1, -1); // dummy head = MRU side
    Node* tail = new Node(-1, -1); // dummy tail = LRU side

    int cap; // maximum number of real nodes allowed in cache
    unordered_map<int, Node*> mpp; // key -> node for O(1) access

    LRUCache(int capacity) {
        cap = capacity; // store the cache capacity
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1; // key does not exist

        Node* node = mpp[key];
        int result = node->val;

        deleteNode(node); // remove from its old position
        addNode(node);    // move to front = recently used

        return result;
    }

    void put(int key, int value) {
        if(cap == 0) return; // cache cannot store anything

        if(mpp.find(key) != mpp.end()){
            Node* existing = mpp[key];

            deleteNode(existing); // remove old node
            delete existing;      // free its memory
            mpp.erase(key);       // remove old key mapping
        }
        else if(mpp.size() == cap){
            Node* lru = tail -> prev; // last real node = least recently used

            mpp.erase(lru->key); // remove LRU key from map
            deleteNode(lru);     // remove LRU from linked list
            delete lru;          // free its memory
        }

        addNode(new Node(key,value)); // new node becomes most recently used
        mpp[key] = head -> next;      // map key to the newly added node
    }
};

Time Complexity : O(1) for both get and put operations, as we are using a combination of a doubly linked list and a hash map to achieve constant time complexity for both operations.

Space Complexity : O(capacity) for storing the nodes in the doubly linked list and the key-node mappings in the hash map.

✅ Company Tags -->  Paytm Zoho Flipkart MorganStanley Amazon Microsoft OYORooms Samsung Snapdeal Hike MakeMyTrip OlaCabs Visa Walmart GoldmanSachs Adobe Google Yahoo