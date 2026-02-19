➡️ problemLinks --> https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/1924606857/

✅ Optimized Approach --> class Solution {
private:
    ListNode* findKthNode(ListNode* temp, int k) {
        k -= 1; // start from one step ahead
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        // ListNode* nextNode;
        ListNode* prevNode = NULL;
        while (temp != NULL) {
            ListNode* kthNode = findKthNode(temp, k);
            if (kthNode == NULL) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if (temp == head) {
                head = kthNode;
            } else {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};

✅ Company Tags -->  Paytm VMWare Accolite Amazon Microsoft Snapdeal Hike MakeMyTrip Walmart GoldmanSachs Adobe SAPLabs