➡️ problemLinks --> https://leetcode.com/problems/merge-intervals/description/  && https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1
 
✅ Brute Force -->  will be sorting the intervals and then iterating through them & compare to merge overlapping intervals 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            int start = arr[i][0]; // cause its a list of list
            int end = arr[i][1];
            if (!ans.empty() &&
                end <= ans.back()[1]) { // "!ans.empty()" means if ans is not empty&& ans.back() gives us the last vectorstored inside the list && [1] means the 2nd element (0 based indexing)
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (arr[j][0] <= end) {
                    end = max(end, arr[j][1]);
                } else {
                    break;
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};

// Time Complexity: O(nlogn) for sorting + O(2N) you might think it is O(n^2) but it is not because we are breaking the loop when we find a non-overlapping interval
// Space Complexity: O(n) for storing the merged intervals

✅ Optimized Approach -->  We can further optimize the merging process by using a single loop and maintaining the start and end of the current merged interval
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            if (ans.empty() ||
                arr[i][0] > ans.back()[1]) { // means new interval,     ans.back() gives us the last element of ans, & ans.back()[0] -> start , of a pair
                ans.push_back(arr[i]);      //                                                                         ans.back()[1] -> end  
            } else { // lying in current interval
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }
};

// Time Complexity: O(nlogn) for sorting + O(n) for merging, first ask the interviewer if the vector will be sorted or not before attempting
// Space Complexity: O(n) for storing the merged intervals

✅ Company Tags (2026 Data) -->  Amazon - asked 22 times in the last 6 months
Bloomberg - asked 13 times in the last 6 months
Apple - asked 13 times in the last 6 months
Microsoft - asked 7 times in the last 6 months
Google - asked 5 times in the last 6 months
Yandex - asked 5 times in the last 6 months
Salesforce - asked 4 times in the last 6 months
micro1 - asked 4 times in the last 6 months
JPMorgan Chase - asked 4 times in the last 6 months
Meta - asked 3 times in the last 6 months
Infosys - asked 3 times in the last 6 months
TikTok - asked 3 times in the last 6 months
Palo Alto Networks - asked 3 times in the last 6 months
IBM- asked 3 times in the last 6 months
Morgan Stanley - asked 3 times in the last 6 months
Visa - asked 3 times in the last 6 months
tcs - asked 2 times in the last 6 months
LinkedIn - asked 2 times in the last 6 months
Walmart Labs - asked 2 times in the last 6 months
Goldman Sachs - asked 2 times in the last 6 months