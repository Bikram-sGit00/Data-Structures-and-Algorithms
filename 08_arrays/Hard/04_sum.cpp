➡️ problemLinks --> https://leetcode.com/problems/4sum/description/ && https://www.geeksforgeeks.org/find-four-numbers-with-a-given-sum/

✅ Brute Force -->  The brute force approach involves using four nested loops to check all possible quadruplets in the array. This results in a time complexity of O(n^4)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st; // using sets to store unique combination
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    for (int l = k + 1; l < n; l++) {
                        // if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        //     vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        //     sort(temp.begin(), temp.end());
                        //     st.insert(temp);
                        // }
                        // long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];
                        long long sum = nums[i] + nums[j] ;  // using long long & doing + step by step to prevent overflow
                        sum+= nums[k] ;
                        sum+= nums[l] ;
                        if(sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};

// Time Complexity: O(n^4)
// Space Complexity: O(n)

✅ Better Approach --> 

✅ Optimized Approach --> 

✅ Company Tags -->  