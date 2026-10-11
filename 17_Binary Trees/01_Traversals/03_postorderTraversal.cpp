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



✅ Iterative Approach (using only one stacks) --> class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> postorder;
        TreeNode* node = root;

        // Postorder traversal: Left -> Right -> Root
        //
        // Example tree:
        //          1
        //         / \
        //        2   3
        //       / \
        //      4   5
        //
        // Expected postorder: [4, 5, 2, 3, 1]
        //
        // We use a stack to remember nodes while moving left.
        // A node is added to the answer only after both its
        // left and right subtrees have been processed.

        while(node != nullptr || !st.empty()){

            if(node != nullptr){

                // Keep the current node on the stack because
                // we still need to process its right subtree
                // and then visit the node itself.
                st.push(node);

                // First, move as far left as possible.
                node = node -> left;

            }else{

                // We cannot go further left.
                // Check whether the top node has a right child.
                TreeNode* temp = st.top() -> right;

                if(temp == nullptr){

                    // No right child exists, so both subtrees
                    // of the top node are now processed.
                    //
                    // We can safely visit this node.
                    //
                    // Example:
                    //      4
                    //
                    // 4 has no children, so visit 4 first.

                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp -> val);

                    // IMPORTANT:
                    // If the node we just visited was the RIGHT
                    // child of the node on top of the stack,
                    // that parent's left and right subtrees
                    // have both been processed.
                    //
                    // Example:
                    //        2
                    //       / \
                    //      4   5
                    //
                    // After visiting 5:
                    // - Left subtree (4) is already processed.
                    // - Right subtree (5) is now processed.
                    // - Therefore, we can visit 2.
                    //
                    // Keep moving upward while the node we just
                    // visited was the right child of its parent.

                    while(!st.empty() && temp == st.top() -> right){

                        // The parent can now be visited because
                        // its right subtree has just been completed.
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp -> val);
                    }

                }else{

                    // A right child exists, so we cannot visit
                    // the current node yet.
                    //
                    // Example:
                    //        2
                    //       / \
                    //      4   5
                    //
                    // If 4 is processed but 5 is not,
                    // we must visit 5 before visiting 2.
                    //
                    // Move to the right subtree and process it
                    // before adding the parent to the answer.
                    node = temp;
                }
            }
        }

        // All nodes have been visited in Left -> Right -> Root order.
        return postorder;
    }
};


Time Complexity :: O(2n)
Space Complexity :: O(n)  // stack space, excluding the result vector space


✅ Company Tags -->  

