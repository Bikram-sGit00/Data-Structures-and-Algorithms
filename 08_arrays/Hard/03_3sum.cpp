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
                int k = -(nums[i] + nums[j]); // finding the third element
                if (s.find(k) != s.end()) { // checking if it exists in the set
                    vector<int> temp = {nums[i], nums[j], k};
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

// Time Complexity: ~ O(n^2 * log(n))  where log(n) is due to sorting the triplet before inserting into the set
// Space Complexity: O(n)

✅ Optimized Approach --> The optimized approach involves sorting the array and using a two-pointer technique to find the triplets. This reduces the time complexity to O(n^2) and the space complexity to O(1).

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // that means value is same as previous and it will
                          // not go down
            int j = i + 1;
            int k = n - 1; // last element
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        j++; // skip duplicates
                    while (j < k && nums[k] == nums[k - 1])
                        k--; // skip duplicates
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)

✅ Company Tags -->  Google Accolite Amazon Microsoft OYO Rooms Samsung CarWale
