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


✅ Better Approach -->  We can use a hash map to count the occurrences of each element in a single pass, which reduces the time complexity to O(n).
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap;
        vector<int> result;
        int n = nums.size();
        
        for (int num : nums) {
            countMap[num]++;
        }
        
        for (const auto& pair : countMap) {
            if (pair.second > n / 3) {
                result.push_back(pair.first);
            }
        }
        
        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
