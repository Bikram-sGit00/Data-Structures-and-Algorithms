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

✅ Iterative Approach (using two stacks) --> class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        // st1 processes the nodes, while st2 stores them in reverse postorder.
        stack<TreeNode*> st1, st2;
        vector<int> postorder;

        // If the tree is empty, there is nothing to traverse.
        if(root == nullptr) return postorder;

        TreeNode* node = root; // Not needed in this approach, but kept as in your code.

        // Start processing from the root.
        st1.push(root);

        while(!st1.empty()){

            // Take the top node from st1 and move it to st2.
            root = st1.top();
            st1.pop();
            st2.push(root);

            // Push the left child first.
            if(root -> left) st1.push(root -> left);

            // Push the right child next.
            if(root -> right) st1.push(root -> right);

            // Since a stack follows LIFO, the right child is processed
            // before the left child in the next iterations.
        }

        // st2 now contains the nodes in reverse postorder.
        // Popping from st2 reverses the order to Left -> Right -> Root.
        while(!st2.empty()){
            postorder.push_back(st2.top() -> val);
            st2.pop();
        }

        return postorder;
    }
};


Time Complexity : O(n)

Space Complexity : O(n) + O(n) = O(n)  // two stacks space, excluding the result vector space

✅ Company Tags -->  

