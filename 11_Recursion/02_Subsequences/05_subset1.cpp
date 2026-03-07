➡️ problemLinks --> https://leetcode.com/problems/subsets/

✅ Optimized Approach --> class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;
        
        vector<vector<int>> result;
        
        for(int selector = 0; selector < total; selector++){  // start from 1 to skip empty string
            vector<int> subset;
            for(int i = 0; i < n; i++){
                if(selector & (1 << i)){
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }
        return result; 
    }
};

// Time Complexity: O(n * 2^n) where n is the number of elements in the input array. We generate 2^n subsets and each subset can take O(n) time to construct.
// Space Complexity: O(n * 2^n) for storing all the subsets in the result vector. Each subset can take O(n) space in the worst case (when all elements are included).

✅ Company Tags -->  