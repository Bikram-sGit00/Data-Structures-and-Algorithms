➡️ problemLinks --> https://leetcode.com/problems/maximum-depth-of-binary-tree/  &&  https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

✅ Optimized Approach --> 

Pattern: Recursion / Postorder traversal (Left → Right → Root).

Logic: Find the left and right subtree depths, take the maximum, and add 1 for the current node.

Base case: nullptr returns 0.

Time: O(N) — visits every node once.

Auxiliary space: O(H) — recursive call stack, where \(H\) is the tree height.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: An empty tree has depth 0.
        if (root == nullptr) return 0;

        // Recursively find the maximum depth of the left subtree.
        int leftH = maxDepth(root->left);

        // Recursively find the maximum depth of the right subtree.
        int rightH = maxDepth(root->right);

        // Take the deeper subtree and add 1 for the current node.
        return 1 + max(leftH, rightH);
    }
};

✅ Company Tags --> 	
Google - asked 11 times in the last 6 months
Bloomberg - asked 5 times in the last 6 months
Amazon - asked 4 times in the last 6 months
Microsoft - asked 3 times in the last 6 months
LinkedIn - asked 2 times in the last 6 months
Meta - asked 2 times in the last 6 months
tcs - asked 2 times in last 6 months