➡️ problemLinks --> https://leetcode.com/problems/combination-sum-ii/  &&  https://www.geeksforgeeks.org/problems/combination-sum-ii/1

✅ Optimized Approach --> class Solution {
private:
    void findCombination(int indx, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int> ds) {
        // Base case: if remaining target becomes 0, we found a valid combination
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = indx; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level to avoid duplicate combinations.
            // Example: candidates = [1,1,2], if we already processed candidates[0]=1,
            // we skip candidates[1]=1 at the same level (but still allow it in deeper levels)
            if (i > indx && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, if current element exceeds target,
            // all further elements will too — no point continuing
            if (candidates[i] > target) break;

            // Choose: add current candidate to the current combination
            ds.push_back(candidates[i]);

            // Explore: move to next index (i+1) since each element can only be used once
            // Subtract current candidate from remaining target
            findCombination(i + 1, target - candidates[i], candidates, ans, ds);

            // Un-choose (backtrack): remove last added element to try next candidate
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort so that duplicates are adjacent (needed for skip-duplicate logic above)
        // and so we can break early when candidate exceeds target
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds; // ds = current combination being built ("decision set")
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

// Time Complexity: O(2^n * k) where n is the number of candidates and k is the average length of combinations found.
// Space Complexity: O(k * x) where k is the average length of combinations and x is the number of valid combinations found. The recursion stack can go as deep as O(k) in the worst case.

✅ Company Tags -->  