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

✅ Company Tags -->  VMWare Flipkart Accolite Amazon Microsoft 24*7 Innovation Labs D-E-Shaw Walmart Komli Media Taxi4Sures