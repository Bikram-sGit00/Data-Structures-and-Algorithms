➡️ problemLinks --> https://leetcode.com/problems/binary-tree-inorder-traversal/  &&  https://www.geeksforgeeks.org/problems/inorder-traversal/1

✅ Recursive Approach --> class Solution {
public:
    void inorder(TreeNode* node, vector<int>& result){
        if(node == nullptr) return;

        inorder(node -> left, result);
        result.push_back(node -> val);
        inorder(node -> right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

Time Complexity : O(n)

Space Complexity : O(n) + O(h) = O(n)  // recursive stack space + result vector space

Note :: Recursive stack space = O(h), where h is the height of the tree.
In the worst case, the tree can be completely skewed, making h = n, so the worst-case auxiliary space is O(n).

✅ Iterative Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  

