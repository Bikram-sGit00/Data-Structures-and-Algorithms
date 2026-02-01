✅ Arr -> Dll conversion ::
class Solution {
  public:
    Node* createDLL(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return NULL;

        Node* head = new Node(arr[0]);
        Node* prev = head;

        for (int i = 1; i < n; i++) {
            Node* temp = new Node(arr[i]);
            temp->prev = prev;     // backward link
            prev->next = temp;     // forward link
            prev = temp;
        }

        return head;
    }
};
