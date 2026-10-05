➡️ problemLinks --> https://leetcode.com/problems/binary-tree-preorder-traversal/  &&  https://www.geeksforgeeks.org/problems/preorder-traversal/1

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

Space Complexity : O(n) + O(h) = O(n)  // recursive stack space + result vector space

Note :: Recursive stack space = O(h), where h is the height of the tree.
In the worst case, the tree can be completely skewed, making h = n, so the worst-case auxiliary space is O(n).

✅ Iterative Approach --> class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;

        // if tree is empty, return empty answer
        if(root == nullptr) return preorder;

        stack<TreeNode*> st;
        st.push(root); // start traversal with root

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            //preorder is root -> left -> right, but as stack follows LIFO, we push in reverse direction
            if(node -> right != nullptr) st.push(node -> right); 
            if(node -> left != nullptr) st.push(node -> left); 

            // process root before its left and right subtrees
            preorder.push_back(node -> val); 
        }

        return preorder;
    }
};

The important recall pattern is:

Preorder = Root → Left → Right

Since `stack` is LIFO, push:

Right first → Left second

so that Left comes out first.


Time Complexity : O(n)

Space Complexity : O(n) at worst case, else -> O(h)

✅ Company Tags -->  Flipkart Amazon Microsoft Walmart

