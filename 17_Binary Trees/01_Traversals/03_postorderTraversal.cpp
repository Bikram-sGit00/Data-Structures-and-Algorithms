➡️ problemLinks --> https://leetcode.com/problems/binary-tree-postorder-traversal/  &&  https://www.geeksforgeeks.org/problems/postorder-traversal/1

✅ Recursive Approach --> class Solution {
public:
    void postorder(TreeNode* node, vector<int>& result){
        if(node == nullptr) return;

        postorder(node -> left,result);
        postorder(node -> right,result);
        result.push_back(node -> val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
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

