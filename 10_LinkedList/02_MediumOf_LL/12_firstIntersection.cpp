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

✅ Optimized Approach --> 

✅ Company Tags -->  