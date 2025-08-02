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

✅ Better Approach -->  The better approach involves using a hash map to store pairs of numbers and their indices. This reduces the time complexity to O(n^2).
class Solution {
public: 
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                // taking bigger data type
                // to avoid integer overflow:
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)

✅ Optimized Approach --> class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--; // 🔁 Fixed here also
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }

        return result;
    }
};
// Time Complexity: O(n^3)
// Space Complexity: O(1) (excluding the output space)

✅ Company Tags -->  Amazon Microsoft OYO Rooms Adobe Google