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

// Time Complexity: O(n^3)
// Space Complexity: O(n)

✅ Better Approach --> The better approach involves hashmap & set data structures to store unique triplets. This reduces the time complexity to O(n^2) but still requires O(n) space for the set.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st; // using sets to store unique combination
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            unordered_set<int> s; // using unordered set to store elements
            for (int j = i + 1; j < n; j++) {
                int x = -(nums[i] + nums[j]); // finding the third element
                if (s.find(x) != s.end()) { // checking if it exists in the set
                    vector<int> temp = {nums[i], nums[j], x};
                    sort(temp.begin(), temp.end());
                    st.insert(temp); // storing into set
                }
                s.insert(nums[j]); // inserting current element into set
            }
        }
        vector<vector<int>> result(st.begin(), st.end()); // converting set to vector
        return result;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)

✅ Optimized Approach --> 

✅ Company Tags -->  
