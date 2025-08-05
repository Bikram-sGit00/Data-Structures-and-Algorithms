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
                arr[i][0] > ans.back()[1]) { // means new interval
                ans.push_back(arr[i]);
            } else { // lying in current inrterval
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }
};

// Time Complexity: O(nlogn) for sorting + O(n) for merging 
// Space Complexity: O(n) for storing the merged intervals

✅ Company Tags -->  Amazon Microsoft Google Nutanix Zoho