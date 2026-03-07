➡️ problemLinks --> https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

✅ Brute Force -->  class Solution {
    public:
        void helper(int indx, int n, vector<int>& arr, int sum, vector<int>& subsetSum){
            if(indx == n ){
                subsetSum.push_back(sum);
                return;
            }
            helper(indx+1, n, arr, arr[indx] + sum, subsetSum);
            helper(indx+1, n, arr, sum, subsetSum);
        }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        vector<int> subsetSum;  // ✅ Normal vector, not reference
        int n = arr.size();
        helper(0, n, arr, 0, subsetSum);
        
        // Now check if target exists in subsetSum
        for(int s : subsetSum){
            if(s == target) return true;
        }
        return false;
    }
};

// Time Complexity: O(2^n) due to generating all subsets.
// Space Complexity: O(2^n) for storing all subset sums in the worst case. The recursion stack can go as deep as O(n) in the worst case.

✅ Optimized Approach --> optimised approach can be achieved using dynamic programming...

✅ Company Tags -->  Amazon Microsoft