➡️ problemLinks --> https://leetcode.com/problems/balanced-binary-tree/  &&  https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

✅ Optimized Approach -->
- Pattern: Postorder DFS — Left → Right → Root.
- Key idea: Calculate height and check balance simultaneously, avoiding repeated traversals.
- -1 sentinel: Signals that an unbalanced subtree has been found; propagate it immediately.
- Balance condition: abs(leftH - rightH) <= 1.
- Time: O(N) — each node is visited at most once.
- Auxiliary space: O(H) — recursive call stack, where \(H\) is the tree height.

class Solution {
public:
    int checkBalance(TreeNode* root) {
        // Base case: An empty subtree has height 0.
        if(root == nullptr) return 0;

        // Calculate the left subtree's height.
        int leftH = checkBalance(root -> left);

        // If the left subtree is unbalanced, propagate -1 immediately.
        if(leftH == -1) return -1;

        // Calculate the right subtree's height.
        int rightH = checkBalance(root -> right);

        // If the right subtree is unbalanced, propagate -1 immediately.
        if(rightH == -1) return -1;


        // If the height difference exceeds 1, the current subtree is unbalanced.
        if(abs(leftH - rightH) > 1) return -1;

        // Return the current subtree's height if it is balanced.
        return 1 + max(leftH, rightH);
    }

    bool isBalanced(TreeNode* root) {
        // -1 means unbalanced; any other result means balanced.
        return checkBalance(root) != -1;
    }
};

✅ Company Tags -->  