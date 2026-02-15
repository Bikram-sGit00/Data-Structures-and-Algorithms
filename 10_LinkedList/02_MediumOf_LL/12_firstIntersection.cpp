➡️ problemLinks --> https://leetcode.com/problems/intersection-of-two-linked-lists/description/  &&  https://www.geeksforgeeks.org/problems/intersection-of-two-linked-list/1

✅ Brute Force -->  will store all nodes of one linkedlist and then compare them with the other linkedlist''s nodes ;
class Solution {
public:    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while(headA){
            s.insert(headA);
            headA = headA->next;
        }
        while(headB){
            if(s.find(headB) != s.end()) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};

// Time Complexity --> O(n+m)  &&  Space Complexity --> O(n) ;

✅ Better Approach --> 

✅ Optimized Approach --> class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* T1 = headA;
        ListNode* T2 = headB;

        while(T1 != T2){
            T1 = T1 -> next;
            T2 = T2 -> next;

            if(T1 == T2) return T1; // also covers null condition , as it that case T1 = T2 = NULL

            if(T1 == NULL) T1 = headB;
            if(T2 == NULL) T2 = headA;
        }
        return T1;
    }
};

// Time Complexity --> O(n+m)  &&  Space Complexity --> O(1) ;

✅ GFG version : Have to return all intersections...
class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int, int> mp;

        // Step 1: store frequency of list2
        while (head2 != NULL) {
            mp[head2->data]++;
            head2 = head2->next;
        }

        Node* dummy = new Node(-1);
        Node* tail = dummy;

        // Step 2: traverse list1 and build result
        while (head1 != NULL) {
            if (mp[head1->data] > 0) {
                tail->next = new Node(head1->data);
                tail = tail->next;
                mp[head1->data]--;
            }
            head1 = head1->next;
        }

        return dummy->next;
    }
};

// Time Complexity --> O(n+m)  &&  Space Complexity --> O(n) ;

✅ Company Tags -->  VMWare Flipkart Accolite Amazon Microsoft 24*7 Innovation Labs D-E-Shaw Walmart Komli Media Taxi4Sures