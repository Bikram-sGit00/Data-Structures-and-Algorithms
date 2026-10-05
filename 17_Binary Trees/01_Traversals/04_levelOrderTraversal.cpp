➡️ problemLinks --> https://leetcode.com/problems/binary-tree-level-order-traversal/  &&  https://www.geeksforgeeks.org/problems/level-order-traversal/1
 
✅ Solution --> class Solution { 
public: 
    vector<vector<int>> levelOrder(TreeNode* root) { 
        vector<vector<int>> ans; 
        if(root == nullptr) return ans; // if tree is empty, return empty answer

        queue<TreeNode*> Q; 
        Q.push(root); // start BFS with the root node

        while(!Q.empty()){ 
            vector<int> currLevel; 

            int levelSize = Q.size(); // make sure to store elements available in queue as we will traverse only for that much elements, 
            for(int i = 0; i < levelSize; i++){ {// if we do i <Q.size(), we're doing push into it for that it will give us wrong ans;
                TreeNode* node = Q.front(); 
                Q.pop(); 

                // Add children to the queue for the next level
                if(node -> left != nullptr) Q.push(node -> left); 
                if(node -> right != nullptr) Q.push(node -> right); 

                // Store the value of the current node
                currLevel.push_back(node -> val); 
            } 

            ans.push_back(currLevel); // add current level to final answer
        } 

        return ans; 
    } 
};

Time Complexity : O(n)

Space Complexity : O(n) - queue takes O(n) space in worst case, we know "ans" also takes O(n) space, but it is to return answer not to solve it

✅ Company Tags -->  Flipkart MorganStanley Accolite Amazon Microsoft Samsung D-E-Shaw OlaCabs Payu Adobe Cisco Qualcomm