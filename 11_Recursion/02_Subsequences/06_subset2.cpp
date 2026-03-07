➡️ problemLinks --> https://leetcode.com/problems/subsets-ii/ && https://www.geeksforgeeks.org/problems/subset-sum-ii/1

✅ Optimized Approach --> class Solution {
private:
    void findSub(int indx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        
        // Every time we enter this function, the current subset (ds) is valid — add it to ans
        // This includes the empty subset when called the first time
        ans.push_back(ds);

        // Try adding each element starting from 'indx' to build new subsets
        for (int i = indx; i < nums.size(); i++) {

            // ⚠️ DUPLICATE SKIP — This is the key part you should focus on:
            // Since the array is sorted, duplicate values are adjacent.
            // If i != indx → we are NOT at the first element of this loop level
            // AND nums[i] == nums[i-1] → current element is same as previous
            // This means we already explored a branch with nums[i-1] at this position,
            // so skipping avoids generating duplicate subsets.
            //
            // ✅ WHY i != indx matters:
            // We only skip duplicates at the SAME recursion level (same loop start).
            // If i == indx, it's the FIRST pick at this level — always allow it.
            // Example: nums = [1, 2, 2]
            //   At level 0: i=0 picks 1 ✅, i=1 picks first 2 ✅, i=2 sees nums[2]==nums[1] → SKIP ✅
            //   At level 1 (after picking 1): i=1 picks 2 ✅, i=2 sees nums[2]==nums[1] → SKIP ✅
            //   At level 1 (after picking first 2): i=2 is indx here → ALLOW (picks second 2) ✅
            if (i != indx && nums[i] == nums[i - 1]) continue;

            // Choose: add current element to the current subset
            ds.push_back(nums[i]);

            // Explore: recurse with next index (i+1) to build further subsets
            findSub(i + 1, nums, ds, ans);

            // Un-choose (backtrack): remove last element to try the next option
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<vector<int>> ans;  // Stores all unique subsets
        vector<int> ds;           // Temporary subset built during recursion

        // Sorting is ESSENTIAL — it groups duplicates together,
        // which makes the duplicate-skip condition (nums[i] == nums[i-1]) work correctly
        sort(nums.begin(), nums.end());

        // Start recursion from index 0 with an empty subset
        findSub(0, nums, ds, ans);

        return ans;
    }
};

// Time Complexity: O(2^n * n) 
// Space Complexity: O(2^n) * O(k) * O(n) // O(k) for storing each subset, O(n) for recursion stack in worst case

✅ Company Tags -->  