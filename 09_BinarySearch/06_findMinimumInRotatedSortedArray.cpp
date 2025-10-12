➡️ problemLinks --> https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/  &&  https://www.geeksforgeeks.org/problems/minimum-number-in-a-sorted-rotated-array-1587115620/1

✅ Optimized Approach --> class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            if(arr[low]<=arr[high]){ // check case if whole array is sorted
              ans=min(ans,arr[low]);
              break;
            }
            if (arr[low]<=arr[mid]){
              ans=min(ans,arr[low]);
              low=mid+1;
            }
            else{
              ans=min(ans,arr[mid]);
              high=mid-1;
            }
        }
        return ans;
    }
};

// Time Complexity: O(log base2 N) in average case and O(N) in worst case
// Space Complexity: O(1)

✅ Company Tags -->  