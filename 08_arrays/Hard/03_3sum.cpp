➡️ problemLinks --> https://leetcode.com/problems/3sum/description/ && https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

✅ Brute Force -->  The brute force approach involves using three nested loops to check all possible triplets in the array. This results in a time complexity of O(n^3)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st; // using sets to store unique combination
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {
                            nums[i], nums[j],
                            nums[k]}; // storing =0s into a temp vector
                        sort(temp.begin(),
                             temp.end()); // storing before storing in set
                        st.insert(temp);  // storing into set
                    }
                }
            }
        }
        vector<vector<int>>
            result( // finally storing sets into result variable to return
                st.begin(), st.end());
        return result;
    }
};

✅ Better Approach --> 

✅ Optimized Approach --> 

✅ Company Tags -->  