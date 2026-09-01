➡️ problemLinks --> https://leetcode.com/problems/top-k-frequent-elements/  &&  https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1

✅ Brute Force -->  Store {frequency, element} pairs in an array/vector, sort in descending order of frequency, and take the first k elements.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp; // Count frequency
        for (int num : nums) {
            mpp[num]++;
        }
        
        vector<pair<int, int>> arr; // Store {frequency, element}
        for (auto it : mpp) {
            arr.push_back({it.second, it.first});
        }
        
        sort(arr.rbegin(), arr.rend());// Sort in descending order of frequency

        vector<int> ans;// Take first k elements
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};

Time Complexity : 
- Frequency counting → O(n)
- Sorting            → O(n log n)
- Taking k elements  → O(k)
- Overall → O(n log n)

Space Complexity : O(n)

✅ Better Approach --> 

Time Complexity : 

Space Complexity : 

✅ Optimized Approach --> 

Time Complexity : 

Space Complexity : 

✅ Company Tags -->  Amazon - asked 25 times in the last 6 months
Google - asked 9 times in the last 6 months
Bloomberg - asked 5 times in the last 6 months
Meta - asked 4 times in the last 6 months
Microsoft - asked 3 times in the last 6 months
tcs - asked 3 times in the last 6 months
Walmart Labs - asked 3 times in the last 6 months
Nvidia - asked 2 times in the last 6 months
American Express - asked 2 times in the last 6 months
Apple - asked 2 times in the last 6 months
TikTok - asked 2 times in the last 6 months
SoFi - asked 2 times in the last 6 months
Visa - asked 2 times in the last 6 months
Snowflake - asked 2 times in the last 6 months
eBay - asked 2 times in the last 6 months