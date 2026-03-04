➡️ problemLinks --> https://leetcode.com/problems/combination-sum/  

✅ Optimized Approach --> class Solution {
private:
    /*
     * Recursive function to find all combinations that sum to target
     * indx     -> current index in candidates array
     * target   -> remaining sum we still need to achieve
     * candidates -> input array of numbers
     * ans      -> stores all valid combinations found
     * ds       -> current combination being built (decision set)
     */
    void findCombination(int indx, int target, vector<int>& candidates,
                         vector<vector<int>>& ans, vector<int> ds) {

        // Base case: reached end of candidates array
        if (indx == candidates.size()) {
            if (target == 0) {
                // Current combination perfectly sums to original target
                ans.push_back(ds);
            }
            return; // Either way, stop exploring this path
        }

        // ── PICK / TAKE the current element ──────────────────────────
        // Only pick if it doesn't exceed the remaining target
        if (candidates[indx] <= target) {
            ds.push_back(candidates[indx]);              // Choose element
            findCombination(indx,                        // Stay on same index
                            target - candidates[indx],   // Reduce remaining target
                            candidates, ans, ds);
            ds.pop_back(); // Backtrack: undo the choice before trying next option
        }

        // ── SKIP / DON'T TAKE the current element ────────────────────
        // Move to the next index without adding current element to ds
        // (same element can't be reused once we skip it)
        findCombination(indx + 1, target, candidates, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // Stores all valid combinations
        vector<int> ds;          // Temporary combination built during recursion
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
```

**Key idea to remember — the "Pick / Skip" pattern:**

Each recursive call makes a binary decision for `candidates[indx]`:
```
                     findCombination(indx, target)
                    /                             \
           PICK it                              SKIP it
  (stay at same index,                   (move to indx+1,
   reduce target)                         target unchanged)

// Time Complexity: O(2^t * k) where t is the target and k is the average length of combinations found
// Space Complexity: O(k * x) where k is the average length of combinations and x is the number of combinations found

✅ Company Tags --> Amazon Microsoft Adobe NPCI