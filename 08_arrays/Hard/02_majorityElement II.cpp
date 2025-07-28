➡️ problemLinks --> https://leetcode.com/problems/majority-element-ii/ && https://www.geeksforgeeks.org/problems/majority-vote/1

✅ Brute Force -->  will iterate through all elements and count their occurrences, which is O(n^2) in time complexity.
 class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }
            if (count > n / 3 && find(result.begin(), result.end(), nums[i]) == result.end()) {
                result.push_back(nums[i]);
            }
        }
        
        return result;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1) or actually O(2)
