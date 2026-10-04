➡️ problemLinks --> https://leetcode.com/problems/binary-tree-preorder-traversal/

✅ Recursive Approach -->  class Solution {
public:
    vector<int> result;

    void preorder(TreeNode* node){
        if(node == nullptr) return;

        result.push_back(node -> val);
        preorder(node->left);
        preorder(node -> right); 
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return result;
    }
};

Time Complexity : O(n)

Space Complexity : O(n) + O(n) = O(n)  // recursive stack space + result vector space


✅ Iterative Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  