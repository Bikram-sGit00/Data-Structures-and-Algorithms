➡️ problemLinks --> https://leetcode.com/problems/non-overlapping-intervals/  &&  https://www.geeksforgeeks.org/problems/non-overlapping-intervals/1
 
Overview ::
//& Valid intervals ::
                        1 2
                          2 3
                            3 4 
//& Invalid intervals ::
                        1 3
                          2 4
                            3 5
                        1   3           //^ so here we can remove 1-3 and 2-4 to make it valid, but we have to minimize removals. so we will remove 1-3 



So we will imagine this question as N meeting rooms problem, just here we're allowed to start immediately after the last meeting,

& after that just remove the successful meetings with total meetings to get the answer.


✅ Optimized Approach --> class Solution {
    struct cmp{
        bool operator()(const vector<int>& a, const vector<int>&b){
            return a[1] < b[1]; 
        }
    };
    public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp{});
        int cnt = 1;
        int lastFinish = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){ // same logic as N meetings 
            if(intervals[i][0] >= lastFinish){ // this time ">=" as start is allowd immediately 
                cnt++;                         // count how many meeting we can do 
                lastFinish = intervals[i][1];
            }
        }
        return intervals.size()  - cnt;  // after that just remove we unable to do 
    }
};

Time Complexity : O(n) + O(nlogn)

Space Complexity : O(1)

✅ Company Tags --> 
Amazon - asked 7 times in the last 6 months (2026 data)
Google - asked 4 times in the last 6 months (2026 data)
Microsoft - asked 3 times in the last 6 months (2026 data)
Grammarly - asked 7 times in the last 6 months
micro1 - asked 2 times in the last 6 months