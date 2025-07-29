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


✅ Optimized Approach -->  We can use the Boyer-Moore Voting Algorithm to find the majority elements in linear time and constant space.
class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        // Code here
        int cnt1 = 0, cnt2 = 0;
        int ele1, ele2;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && nums[i] != ele2) {
                cnt1 = 1, ele1 = nums[i];
            } else if (cnt2 == 0 && nums[i] != ele1) {
                cnt2 = 1, ele2 = nums[i];
            } else if (ele1 == nums[i])
                cnt1++;
            else if (ele2 == nums[i])
                cnt2++;
            else
                cnt1--, cnt2--;
        }
        cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num == ele1)
                cnt1++;
            else if (num == ele2)
                cnt2++;
        }

        vector<int> result;
        int threshold = (int)(nums.size() / 3);
        if (cnt1 > threshold)
            result.push_back(ele1);
        if (cnt2 > threshold)
            result.push_back(ele2);

        sort(result.begin(),result.end());
        return result;
    }
};

//Time Complexity: O(N), where N = size of the given array. Reason: We are traversing the array only once.
//Space Complexity: O(1), as we are using only a constant amount of space for

✅ Company Tags -->  Bloomberg Salesforce Accenture Microsoft TCS Google