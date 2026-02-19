➡️ problemLinks --> https://leetcode.com/problems/add-two-numbers/description/ && https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

✅ Optimized Approach --> class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while(l1  || l2 || carry){ // written carry cause for lastest carry the l1 & l2 will be null and loop will stop , so for preventing this we have wrote "till carry not null "
            int sum = 0;
            if(l1){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2){
                sum += l2 -> val;
                l2 = l2->next;
            }
            sum +=carry;
            carry = sum/10; // if have >10 , will return 1 else 0
            ListNode* newNode = new ListNode(sum%10); // if sum is 15 this will give us 5 and next we will set 5's next is 1
            temp-> next = newNode;
            temp = temp-> next;
        }
        return dummy-> next;
    }
};

// Time Complexity: O(max(m,n)) where m and n are the lengths of the two linked lists.
// Space Complexity: O(max(m,n)) for the new linked list created to store the result.

✅ Company Tags -->  Flipkart Morgan Stanley Accolite Amazon Microsoft Snapdeal MakeMyTrip Qualcomm