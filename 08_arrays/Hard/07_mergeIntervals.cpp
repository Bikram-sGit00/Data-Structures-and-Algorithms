➡️ problemLinks --> https://leetcode.com/problems/merge-intervals/description/

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

✅ Better Approach -->  Instead of using a nested loop, we can optimize the merging process by keeping track of the last merged interval and only adding a new interval if it doesn't overlap

✅ Optimized Approach --> 

✅ Company Tags -->  