➡️ problemLinks --> https://leetcode.com/problems/merge-two-sorted-lists/description/
 
✅ Optimized Approach --> class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        while(list1 != NULL && list2 != NULL){
            if(list1 -> val < list2-> val){
                res -> next = list1;
                res = list1;
                list1 = list1-> next;
            }
            else{
                res -> next = list2;
                res = list2;
                list2 = list2-> next;
            }
        }
        if(list1) res -> next = list1;
        if(list2) res -> next = list2;

        return dummy -> next;
    }
};

// Time Complexity --> O(n + m) (where n and m are the lengths of the two lists)
// Space Complexity --> O(1) (excluding the space used by the new list created)

✅ Company Tags -->  Zoho Flipkart Accolite Amazon Microsoft Samsung FactSet MakeMyTrip Oracle Brocade Synopsys OATSSystems Belzabar NPCI