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

GFG :: On GFG, the same Solution object can potentially be reused, so result may already contain values from a previous test case/call. so we will pass the result.

class Solution {
  public:
    void solver(Node* node, vector<int>& result){ 
        if(node == nullptr) return;  
        
        result.push_back(node -> data);
        solver(node -> left, result);
        solver(node -> right, result);
    }
    vector<int> preOrder(Node* root) {
        vector<int> result;
        solver(root, result);
        return result;
    }
};

Time Complexity : O(n)

Space Complexity : O(n) + O(n) = O(n)  // recursive stack space + result vector space


✅ Iterative Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  

