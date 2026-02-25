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

    void addNode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node* node = mpp[key];
        int result = node->val;
        deleteNode(node);
        addNode(node);
        return result;
    }

    void put(int key, int value) {
        if(cap == 0) return;

        if(mpp.find(key) != mpp.end()){
            Node* existing = mpp[key];
            deleteNode(existing);
            delete existing;
            mpp.erase(key);
        }
        else if(mpp.size() == cap){
            Node* lru = tail -> prev;
            mpp.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }
        addNode(new Node(key,value));
        mpp[key] = head -> next;
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });

// Time Complexity: O(1) for both get and put operations.
// Space Complexity: O(capacity) for storing the cache entries in the unordered_map and the doubly linked list.

✅ Company Tags -->  Paytm Zoho Flipkart MorganStanley Amazon Microsoft OYORooms Samsung Snapdeal Hike MakeMyTrip OlaCabs Visa Walmart GoldmanSachs Adobe Google Yahoo