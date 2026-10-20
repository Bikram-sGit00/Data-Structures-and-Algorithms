➡️ problemLinks --> https://leetcode.com/problems/same-tree/

✅ Optimized Approach --> can use any traversal technique to check if both output are same
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If either node is nullptr, both must be nullptr to be identical.
        if(p == nullptr || q == nullptr) return (p == q);

        // Check whether the current values match and both left and right subtrees are identical.
        return (p -> val == q -> val) && isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
}; 

Time Complexity : O(n) 

Space Complexity : O(n)

✅ Company Tags -->  Amazon - asked 5 times in the last 6 months
Google - asked 3 times in the last 6 months
Meta - asked 2 times in the last 6 months
Microsoft - asked 2 times in the last 6 months
tcs - asked 2 times in the last 6 months
Bloomberg - asked 2 times in last 6 months